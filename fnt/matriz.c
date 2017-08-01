/*
 * Copyright (C) 2017 Ricardo Quezada Figueroa
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "vector_vectores.h"
#include "vector.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <math.h>
#include <gmp.h>

Matriz *nueva_matriz_vacia(int filas, int columnas);
int es_escalar(Matriz *a);
Matriz *suma_escalar(Matriz *escalar, Matriz *matriz);
Matriz *resta_escalar_izq(Matriz *escalar, Matriz *matriz);
Matriz *resta_escalar_der(Matriz *escalar, Matriz *matriz);
Matriz *producto_escalar(Matriz *escalar, Matriz *matriz);
Matriz *copiar_matriz(Matriz *matriz);

Matriz *nueva_matriz(VVectores *vvectores)
{
	Matriz *resultado;
	resultado = nueva_matriz_vacia(vvectores->num_elementos, vvectores->primero->vector->num_elementos);

	int l = 0, m;
	for(VVectores_contenedor *i = vvectores->primero; i != NULL; i = i->siguiente) {
		m = 0;
		for(Contenedor *j = i->vector->primero; j != NULL; j = j->siguiente) {
			mpz_set(resultado->datos[l][m], j->valor);
			m++;
		}
		if(resultado->columnas != i->vector->num_elementos){
			liberar_vvectores(vvectores);
			printw("Error: Matriz incompleta.\n");
			raise(SIGUSR1);
		}
		l++;
	}
	return resultado;
}

Matriz *nueva_matriz_escalar(mpz_t escalar)
{
	Matriz *resultado;
	resultado = nueva_matriz_vacia(1 ,1);

	mpz_set(resultado->datos[0][0], escalar);
	mpz_clear(escalar);		//¿?
	return resultado;
}

Matriz *suma_matrices(Matriz *a, Matriz *b)
{
	if(es_escalar(a))
		return suma_escalar(a, b);
	if(es_escalar(b))
		return suma_escalar(b, a);

	if((a->columnas != b->columnas) || (a->filas != b->filas)) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Matriz incompleta.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(a->filas, a->columnas);
	for(int i=0; i<a->filas; i++)
		for(int j=0; j<a->columnas; j++)
			mpz_add(resultado->datos[i][j], a->datos[i][j], b->datos[i][j]);

	return resultado;
}

Matriz *resta_matrices(Matriz *a, Matriz *b)
{
	if(es_escalar(a))
		return resta_escalar_izq(a, b);
	if(es_escalar(b))
		return resta_escalar_der(a, b);

	if((a->columnas != b->columnas) || (a->filas != b->filas)) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Resta entre matrices de distintas dimnsiones.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(a->filas, a->columnas);
	for(int i=0; i<a->filas; i++)
		for(int j=0; j<a->columnas; j++)
			mpz_sub(resultado->datos[i][j], a->datos[i][j], b->datos[i][j]);

	return resultado;
}

Matriz *multiplica_matrices(Matriz *a, Matriz *b)
{
	if(es_escalar(a))
		return producto_escalar(a, b);
	if(es_escalar(b))
		return producto_escalar(b, a);

	if(a->columnas != b->filas) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Multiplicación entre matrices incorrecta.\n");
		raise(SIGUSR1);
	}

	Matriz *res = nueva_matriz_vacia(a->filas, b->columnas);
	mpz_t acumulado, temp;
	mpz_init(acumulado);
	mpz_init(temp);
	for(int i=0; i<a->filas; i++)
		for(int j=0; j<b->columnas; j++) {
			mpz_set_ui(acumulado, 0);
			for(int k=0; k<a->columnas; k++){
				mpz_mul(temp, a->datos[i][k], b->datos[k][j]);
				mpz_add(acumulado, acumulado, temp);
			}
			mpz_set(res->datos[i][j], acumulado);
		}

	mpz_clear(acumulado);
	mpz_clear(temp);
	return res;
}

Matriz *division_escalar(Matriz *a, Matriz *b)
{
	if(b->columnas != 1 || b->filas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Dividendo debe ser escalar.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(a->filas, a->columnas);
	for(int i=0; i<a->filas; i++)
		for(int j=0; j<a->columnas; j++)
			mpz_cdiv_q(resultado->datos[i][j], a->datos[i][j], b->datos[0][0]);

	return resultado;
}

Matriz *potencia_matrices(Matriz *a, Matriz *b)
{
	if(b->columnas != 1 || b->filas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Potencia debe ser escalar.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = copiar_matriz(a);
	unsigned int potencia = mpz_get_ui(b->datos[0][0]);
	for(int i=0; i<potencia-1; i++)
		resultado = multiplica_matrices(a, resultado);

	return resultado;
}

Matriz *potencia_escalar(Matriz *a, Matriz *b)
{
	if(b->columnas != 1 || b->filas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Potencia debe ser escalar.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(a->filas, a->columnas);
	for(int i=0; i<a->filas; i++)
		for(int j=0; j<a->columnas; j++)
			mpz_pow_ui(resultado->datos[i][j], a->datos[i][j], mpz_get_ui(b->datos[0][0]));

	return resultado;
}

Matriz *mayor_que_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operandos de comparación deben ser escalares.\n");
		raise(SIGUSR1);
	}

 	int tmp = mpz_cmp(a->datos[0][0], b->datos[0][0]);
	Matriz *resultado = nueva_matriz_vacia(1, 1);
	if(tmp > 0)
		mpz_set_ui(resultado->datos[0][0], 1);
	else
		mpz_set_ui(resultado->datos[0][0], 0);

	return resultado;
}

Matriz *mayor_o_igual_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operandos de comparación deben ser escalares.\n");
		raise(SIGUSR1);
	}

	int tmp = mpz_cmp(a->datos[0][0], b->datos[0][0]);
	Matriz *resultado = nueva_matriz_vacia(1, 1);
	if(tmp >= 0)
		mpz_set_ui(resultado->datos[0][0], 1);
	else
		mpz_set_ui(resultado->datos[0][0], 0);

	return resultado;
}

Matriz *menor_que_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operandos de comparación deben ser escalares.\n");
		raise(SIGUSR1);
	}

	int tmp = mpz_cmp(a->datos[0][0], b->datos[0][0]);
	Matriz *resultado = nueva_matriz_vacia(1, 1);
	if(tmp < 0)
		mpz_set_ui(resultado->datos[0][0], 1);
	else
		mpz_set_ui(resultado->datos[0][0], 0);

	return resultado;
}

Matriz *menor_o_igual_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operandos de comparación deben ser escalares.\n");
		raise(SIGUSR1);
	}

	int tmp = mpz_cmp(a->datos[0][0], b->datos[0][0]);
	Matriz *resultado = nueva_matriz_vacia(1, 1);
	if(tmp <= 0)
		mpz_set_ui(resultado->datos[0][0], 1);
	else
		mpz_set_ui(resultado->datos[0][0], 0);

	return resultado;
}

Matriz *igual_a_matrices(Matriz *a, Matriz *b)
{
	mpz_t res;
	mpz_init(res);
	if(a->filas != b->filas || a->columnas != b->columnas) {
		mpz_set_ui(res, 0);
		return nueva_matriz_escalar(res);
	}

	mpz_set_ui(res, 0);
	for (int i=0; i<a->filas; i++)
		for (int j=0; j<a->columnas; j++)
			if (mpz_cmp(a->datos[i][j], b->datos[i][j]) != 0)
				return nueva_matriz_escalar(res);

	mpz_set_ui(res, 1);
	return nueva_matriz_escalar(res);
}

Matriz *distinto_de_matrices(Matriz *a, Matriz *b)
{
	mpz_t res;
	mpz_init(res);
	if(a->filas != b->filas || a->columnas != b->columnas) {
		mpz_set_ui(res, 1);
		return nueva_matriz_escalar(res);
	}

	mpz_set_ui(res, 1);
	for (int i=0; i<a->filas; i++)
		for (int j=0; j<a->columnas; j++)
			if (mpz_cmp(a->datos[i][j], b->datos[i][j]) != 0)
				return nueva_matriz_escalar(res);

	mpz_set_ui(res, 0);
	return nueva_matriz_escalar(res);
}

Matriz *disyuncion_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	mpz_set_ui(resultado->datos[0][0], mpz_get_ui(a->datos[0][0]) || mpz_get_ui(b->datos[0][0]));
	return resultado;
}

Matriz *disyuncion_exclusiva_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	int d1 = mpz_get_si(a->datos[0][0]);
	int d2 = mpz_get_si(b->datos[0][0]);
	mpz_set_si(resultado->datos[0][0], (d1 && !d2) || (!d1 && d2));
	return resultado;
}

Matriz *conjuncion_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	mpz_set_ui(resultado->datos[0][0], mpz_get_ui(a->datos[0][0]) && mpz_get_ui(b->datos[0][0]));
	return resultado;
}

Matriz *condicional_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	mpz_set_ui(resultado->datos[0][0], !mpz_get_ui(a->datos[0][0]) || mpz_get_ui(b->datos[0][0]));
	return resultado;
}

Matriz *bicondicional_matrices(Matriz *a, Matriz *b)
{
	if(a->filas != 1 || a->columnas != 1 || b->filas != 1 || b->columnas != 1) {
		liberar_matriz(a);
		liberar_matriz(b);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	int d1 = mpz_get_si(a->datos[0][0]);
	int d2 = mpz_get_si(b->datos[0][0]);
	mpz_set_si(resultado->datos[0][0], (!d1 && !d2) || (d1 && d2));
	return resultado;
}

Matriz *negacion_matrices(Matriz *a)
{
	if(a->filas != 1 || a->columnas != 1) {
		liberar_matriz(a);
		printw("Error: Operación lógica solo disponible entre escalares.\n");
		raise(SIGUSR1);
	}

	Matriz *resultado = nueva_matriz_vacia(1, 1);
	mpz_set_ui(resultado->datos[0][0], !mpz_get_ui(a->datos[0][0]));
	return resultado;
}

int evaluar_matriz(Matriz *a)
{
	if(a->filas != 1 || a->columnas != 1) {
		liberar_matriz(a);
		printw("Error: Evaluación solo diponible para escalares.\n");
		raise(SIGUSR1);
	}

	return mpz_get_si(a->datos[0][0]);
}


Matriz *ejecutar_funcion(Matriz *matriz, double (*funcion)())
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_set_ui(resultado->datos[i][j], (unsigned int) funcion( (double) mpz_get_ui(matriz->datos[i][j])));
	return resultado;
}

Matriz *transpuesta(Matriz *matriz)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->columnas, matriz->filas);
	for (int i=0; i<matriz->filas; i++)
		for (int j=0; j<matriz->columnas; j++)
			mpz_set(resultado->datos[j][i], matriz->datos[i][j]);
	return resultado;
}

void imprimir_matriz(Matriz *matriz)
{
	char temp[10000];
	for(int i=0; i<matriz->filas; i++){
		for(int j=0; j<matriz->columnas; j++){
			mpz_get_str(temp, 10, matriz->datos[i][j]);
			printw("%s\t", temp);
		}
		printw("\n");
	}
	refresh();
}

void liberar_matriz(Matriz *matriz)
{
	for(int i=0; i<matriz->filas; i++){
		for(int j=0; j<matriz->columnas; j++)
			mpz_clear(matriz->datos[i][j]);
		free(matriz->datos[i]);
	}
	free(matriz->datos);
	free(matriz);
}

Vector *agregar_matriz_a_vector(Vector *vector, Matriz *matriz)
{
	if(matriz->filas != 1) {
		printw("Error: Matriz solo construible a partir de vectores.\n");
		raise(SIGUSR1);
	}

	for(int i=0; i<matriz->columnas; i++) {

		Contenedor *auxiliar;
		Contenedor *contenedor = nuevo_contenedor();
		mpz_set(contenedor->valor, matriz->datos[0][i]);

		auxiliar = vector->ultimo;
		vector->ultimo = contenedor;
		contenedor->anterior = auxiliar;
		auxiliar->siguiente = contenedor;
		vector->num_elementos++;
	}

	return vector;
}

Vector *nuevo_vector_de_matriz(Matriz *matriz)
{
	if(matriz->filas != 1) {
		printw("Error: Matriz solo construible a partir de vectores.\n");
		raise(SIGUSR1);
	}

	Vector *resultado;
	resultado = malloc(sizeof(Vector));
	if(!resultado) {
		printw("Memoria insuficiente.\n");
		exit(1);
	}

	Contenedor *contenedor = nuevo_contenedor();
	mpz_set(contenedor->valor, matriz->datos[0][0]);

	resultado->primero = contenedor;
	resultado->ultimo = contenedor;
	resultado->num_elementos = 1;

	for(int i=1; i<matriz->columnas; i++) {

		Contenedor *auxiliar;
		Contenedor *contenedor2 = nuevo_contenedor();
		mpz_set(contenedor2->valor, matriz->datos[0][i]);

		auxiliar = resultado->ultimo;
		resultado->ultimo = contenedor2;
		contenedor2->anterior = auxiliar;
		auxiliar->siguiente = contenedor2;
		resultado->num_elementos++;
	}

	return resultado;
}

Matriz *nueva_matriz_vacia(int filas, int columnas)
{
	Matriz *resultado;
	resultado = malloc(sizeof(Matriz));
	if(!resultado) {
		printw("Memoria insuficiente.\n");
		exit(1);
	}

	resultado->filas = filas;
	resultado->columnas = columnas;

	resultado->datos = malloc(sizeof(mpz_t*) * resultado->filas);
	if(!resultado->datos) {
		printw("Memoria insuficiente.\n");
		exit(1);
	}

	for(int i=0; i<resultado->filas; i++) {
		resultado->datos[i] = malloc(sizeof(mpz_t) * resultado->columnas);
		if(!resultado->datos[i]) {
			printw("Memoria insuficiente.\n");
			exit(1);
		}

		for(int j=0; j<resultado->columnas; j++)
			mpz_init(resultado->datos[i][j]);
	}

	return resultado;
}

int es_escalar(Matriz *a)
{
	return (a->filas == 1) && (a->columnas == 1);
}

Matriz *suma_escalar(Matriz *escalar, Matriz *matriz)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_add(resultado->datos[i][j], matriz->datos[i][j], escalar->datos[0][0]);

	return resultado;
}

Matriz *resta_escalar_izq (Matriz *escalar, Matriz *matriz)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_sub(resultado->datos[i][j], escalar->datos[0][0], matriz->datos[i][j]);

	return resultado;
}

Matriz *resta_escalar_der (Matriz *matriz, Matriz *escalar)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_sub(resultado->datos[i][j], matriz->datos[i][j], escalar->datos[0][0]);

	return resultado;
}

Matriz *producto_escalar(Matriz *escalar, Matriz *matriz)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_mul(resultado->datos[i][j], matriz->datos[i][j], escalar->datos[0][0]);

	return resultado;
}

Matriz *copiar_matriz(Matriz *matriz)
{
	Matriz *resultado = nueva_matriz_vacia(matriz->filas, matriz->columnas);
	for(int i=0; i<matriz->filas; i++)
		for(int j=0; j<matriz->columnas; j++)
			mpz_set(resultado->datos[i][j], matriz->datos[i][j]);
	return resultado;
}
