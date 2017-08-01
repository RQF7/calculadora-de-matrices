/* programa.c
 * Implementación de operaciones de programa.
 * vim: set foldmethod=indent :
 *
 * Copyright (c) 2017 Ricardo Quezada
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * */

#include "programa.h"
#include "vector.h"
#include "vector_vectores.h"
#include "matriz.h"
#include "simbolo.h"
#include "parser.tab.h"
#include <stdio.h>
#include <curses.h>

#define TAM_PILA 2048
static Dato_de_pila pila[TAM_PILA];
static Dato_de_pila *apuntador_de_pila;

#define TAM_PROGRAMA 5000
Instruccion programa[TAM_PROGRAMA];
Instruccion *apuntador_de_programa;
Instruccion *contador_de_programa;
Instruccion *programa_base = programa;
int regresando;

static Vector *vector;
static VVectores *vvector;

typedef struct Marco {
	Simbolo *simbolo;
	Instruccion *direccion_de_retorno;
	Dato_de_pila *argumentos;
	int numero_de_argumentos;
} Marco;

#define TAM_MARCOS 1000
Marco marco[TAM_MARCOS];
Marco *apuntador_de_marco;

void iniciar_codificacion()
{
	apuntador_de_programa = programa_base;
	apuntador_de_pila = pila;
	apuntador_de_marco = marco;
	regresando = 0;
}

Dato_de_pila sacar_de_pila()
{
	if (apuntador_de_pila <= pila)
		error_en_ejecucion("Apuntador de pila fuera de rango (por debajo)", (char *) 0);
	return *--apuntador_de_pila;

}

void meter_a_pila(Dato_de_pila d)
{
	if (apuntador_de_pila >= &pila[TAM_PILA])
		error_en_ejecucion("Apuntador de pila fuera de rango (por arriba)", (char *) 0);
	*apuntador_de_pila++ = d;
}

Instruccion *codificar(Instruccion instruccion)
{
	Instruccion *pos_actual = apuntador_de_programa;
	if (apuntador_de_programa >= &programa[TAM_PROGRAMA])
		error_en_ejecucion("Memoria ram saturada", (char *) 0);
	*apuntador_de_programa++ = instruccion;
	return pos_actual;
}

void ejecutar(Instruccion *instruccion)
{
	for (contador_de_programa = instruccion; *contador_de_programa != DETENER && !regresando; )
		(*(*contador_de_programa++))();
}

void definir(Simbolo *simbolo)
{
	simbolo->u.definicion = programa_base;
	programa_base = apuntador_de_programa;
}

Matriz **obtener_argumento()
{
	long int num_arg =  (long int) *contador_de_programa++;
	if(num_arg > apuntador_de_marco->numero_de_argumentos)
		error_en_ejecucion(apuntador_de_marco->simbolo->nombre, "Argumentos insuficientes");

	return &apuntador_de_marco->argumentos[num_arg - apuntador_de_marco->numero_de_argumentos].valor;
}

void asignar()
{
	if(DEBUG) {
		printw("asignar\n");
		refresh();
	}

	Dato_de_pila dato1, dato2;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	if (dato1.simbolo->tipo != VARIABLE && dato1.simbolo->tipo != INDEFINIDO)
		error_en_ejecucion("Asignacion a no-variable", dato1.simbolo->nombre);
	dato1.simbolo->u.valor = dato2.valor;
	dato1.simbolo->tipo = VARIABLE;
	meter_a_pila(dato1);
}

void asignar_default()
{
	if(DEBUG) {
		printw("asignar_default\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	Simbolo *simbolo = buscar("res");
	simbolo->u.valor = dato.valor;
	meter_a_pila(dato);
}

void imprimir()
{
	if(DEBUG) {
		printw("imrpimir\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	if(dato.simbolo->nombre)
		printw("%s:\n", dato.simbolo->nombre);
	imprimir_matriz(dato.simbolo->u.valor);
	printw("\n");
	refresh();
}

void imprimir_exp()
{
	if(DEBUG) {
		printw("imprimir_exp\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	printw("res:\n");
	imprimir_matriz(dato.valor);
	printw("\n");
	refresh();
}

void evaluar()
{
	if(DEBUG) {
		printw("evaluar\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	if (dato.simbolo->tipo == INDEFINIDO)
		error_en_ejecucion("Variable no definida", dato.simbolo->nombre);
	dato.valor = dato.simbolo->u.valor;
	meter_a_pila(dato);
}

void meter_variable()
{
	if(DEBUG) {
		printw("meter_variable\n");
		refresh();
	}

	Dato_de_pila dato;
	dato.simbolo = (Simbolo *)(*contador_de_programa++);
	meter_a_pila(dato);
}

void meter_constante()
{
	if(DEBUG) {
		printw("meter_constante\n");
		refresh();
	}

	Dato_de_pila dato;
	dato.valor = ((Simbolo *) *contador_de_programa++)->u.valor;
	meter_a_pila(dato);
}

void ejecutar_funcion_programa()
{
	if(DEBUG) {
		printw("ejecutar_funcion_programa\n");
		refresh();
	}

	Dato_de_pila dato, resultado;
	dato = sacar_de_pila();
	resultado.valor = ejecutar_funcion(dato.valor, *(double (*)())(*contador_de_programa++));
	meter_a_pila(resultado);
}

void sumar()
{
	if(DEBUG) {
		printw("sumar\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = suma_matrices(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void restar()
{
	if(DEBUG) {
		printw("restar\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = resta_matrices(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void multiplicar()
{
	if(DEBUG) {
		printw("multiplicar\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = multiplica_matrices(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void dividir()
{
	if(DEBUG) {
		printw("dividir\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = division_escalar(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void elevar_a_potencia()
{
	if(DEBUG) {
		printw("elevar_a_potencia\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = potencia_matrices(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void elevar_a_potencia_escalar()
{
	if(DEBUG) {
		printw("elevar_a_potencia_escalar\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	resultado.valor = potencia_escalar(dato2.valor, dato1.valor);
	meter_a_pila(resultado);
}

void negar()
{
	if(DEBUG) {
		printw("negar\n");
		refresh();
	}

	Dato_de_pila dato1, resultado;
	dato1 = sacar_de_pila();
	mpz_t tmp;
	mpz_init_set_si(tmp, -1);
	resultado.valor = multiplica_matrices(dato1.valor, nueva_matriz_escalar(tmp));
	mpz_clear(tmp);
	meter_a_pila(resultado);
}

void transponer ()
{
	if(DEBUG) {
		printw("transponer\n");
		refresh();
	}

	Dato_de_pila dato1, resultado;
	dato1 = sacar_de_pila();
	resultado.valor = transpuesta(dato1.valor);
	meter_a_pila(resultado);
}

void incremento_unitario()
{
	if(DEBUG) {
		printw("incremento_unitario\n");
		refresh();
	}

	Dato_de_pila dato, resultado;
	dato = sacar_de_pila();
	mpz_t aux;
	mpz_init_set_si(aux, 1);
	resultado.valor = suma_matrices(dato.valor, nueva_matriz_escalar(aux));
	meter_a_pila(resultado);
}

void decremento_unitario()
{
	if(DEBUG) {
		printw("decremento_unitario\n");
		refresh();
	}

	Dato_de_pila dato, resultado;
	dato = sacar_de_pila();
	mpz_t aux;
	mpz_init_set_si(aux, 1);
	resultado.valor = resta_matrices(dato.valor, nueva_matriz_escalar(aux));
	meter_a_pila(resultado);
}


void iniciar_vector()
{
	if(DEBUG) {
		printw("iniciar_vector\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	vector = nuevo_vector_de_matriz(dato.valor);
}

void continuar_vector()
{
	if(DEBUG) {
		printw("continuar_vector\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	agregar_matriz_a_vector(vector, dato.valor);
}

void iniciar_vvectores()
{
	if(DEBUG) {
		printw("iniciar_vvectores\n");
		refresh();
	}

	vvector = nuevo_vvectores(vector);
}

void continuar_vvectores()
{
	if(DEBUG) {
		printw("agregar_a_vvectores\n");
		refresh();
	}

	agregar_a_vvectores(vvector, vector);
}

void terminar_construccion()
{
	if(DEBUG) {
		printw("terminar_construccion\n");
		refresh();
	}

	Matriz *matriz = nueva_matriz(vvector);
	liberar_vvectores(vvector);
	Dato_de_pila dato;
	dato.valor = matriz;
	meter_a_pila(dato);
}

void instruccion_vacia()
{
	if(DEBUG) {
		printw("instruccion_vacia\n");
		refresh();
	}

	sacar_de_pila();
}

void voltear_operandos()
{
	if(DEBUG) {
		printw("voltear operandos\n");
		refresh();
	}

	Dato_de_pila dato1;
	Dato_de_pila dato2;
	dato1 = sacar_de_pila();
	dato2 = sacar_de_pila();
	meter_a_pila(dato1);
	meter_a_pila(dato2);
}

void codigo_si()
{
	if(DEBUG) {
		printw("codigo_si\n");
		refresh();
	}

	Dato_de_pila dato;
	Instruccion *guardar_posicion = contador_de_programa;

	ejecutar(guardar_posicion + 3);
	dato = sacar_de_pila();
	if (evaluar_matriz(dato.valor))
		ejecutar (*((Instruccion **) (guardar_posicion)));
	else if (*((Instruccion **) (guardar_posicion + 1)))
		ejecutar (*((Instruccion **) (guardar_posicion + 1)));

	if (!regresando)
		contador_de_programa = *((Instruccion **) (guardar_posicion + 2));
}

void codigo_mientras()
{
	if(DEBUG) {
		printw("codigo_mientras\n");
		refresh();
	}

	Dato_de_pila dato;
	Instruccion *guardar_posicion = contador_de_programa;

	ejecutar(guardar_posicion + 2);
	dato = sacar_de_pila();
	while (evaluar_matriz(dato.valor)) {
		ejecutar(*((Instruccion **) (guardar_posicion)));
		ejecutar(guardar_posicion + 2);
		dato = sacar_de_pila();
	}

	if (!regresando)
		contador_de_programa = *((Instruccion **) (guardar_posicion + 1));
}

void codigo_ciclo()
{
	if(DEBUG) {
		printw("codigo_ciclo\n");
		refresh();
	}

	Dato_de_pila dato;
	Instruccion *guardar_posicion = contador_de_programa;

	ejecutar(*((Instruccion **) (guardar_posicion + 2)));			/* Inicializar */
	ejecutar(*((Instruccion **) (guardar_posicion + 3)));			/* Condicion */
	dato = sacar_de_pila();
	while (evaluar_matriz(dato.valor)) {
		ejecutar(*((Instruccion **) (guardar_posicion)));
		ejecutar(*((Instruccion **) (guardar_posicion + 4)));		/* Incremento */
		ejecutar(*((Instruccion **) (guardar_posicion + 3)));		/* Condicion */
		dato = sacar_de_pila();
	}

	if (!regresando)
		contador_de_programa = *((Instruccion **) (guardar_posicion + 1));
}

void mayor_que()
{
	if(DEBUG) {
		printw("mayor_que\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = mayor_que_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void mayor_o_igual()
{
	if(DEBUG) {
		printw("mayor_o_igual\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = mayor_o_igual_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void menor_que()
{
	if(DEBUG) {
		printw("menor_que\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = menor_que_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void menor_o_igual()
{
	if(DEBUG) {
		printw("menor_o_igual\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = menor_o_igual_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void igual_a()
{
	if(DEBUG) {
		printw("igual_a\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = igual_a_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void distinto_de()
{
	if(DEBUG) {
		printw("distinto_de\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = distinto_de_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void disyuncion()
{
	if(DEBUG) {
		printw("disyuncion\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = disyuncion_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void disyuncion_exclusiva()
{
	if(DEBUG) {
		printw("disyuncion_exclusiva\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = disyuncion_exclusiva_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void conjuncion()
{
	if(DEBUG) {
		printw("conjuncion\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = conjuncion_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void condicional()
{
	if(DEBUG) {
		printw("condicional\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = condicional_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}
void bicondicional()
{
	if(DEBUG) {
		printw("bicondicional\n");
		refresh();
	}

	Dato_de_pila dato1, dato2, resultado;
	dato2 = sacar_de_pila();
	dato1 = sacar_de_pila();
	resultado.valor = bicondicional_matrices(dato1.valor, dato2.valor);
	meter_a_pila(resultado);
}

void negacion()
{
	if(DEBUG) {
		printw("negacion\n");
		refresh();
	}

	Dato_de_pila dato, resultado;
	dato = sacar_de_pila();
	resultado.valor = negacion_matrices(dato.valor);
	meter_a_pila(resultado);
}

void instruccion_imprimir()
{
	if(DEBUG) {
		printw("instruccion_imprimir\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	imprimir_matriz(dato.valor);
	printw("\n");
	refresh();
}

void llamada()
{
	if(DEBUG) {
		printw("llamada\n");
		refresh();
	}

	Simbolo *simbolo = (Simbolo *) contador_de_programa[0];
	if(apuntador_de_marco++ >= &marco[TAM_MARCOS - 1])
		error_en_ejecucion(simbolo->nombre, "Pila de llamadas demasiado profunda");

	apuntador_de_marco->simbolo = simbolo;
	apuntador_de_marco->numero_de_argumentos = (long int) contador_de_programa[1];
	apuntador_de_marco->direccion_de_retorno = contador_de_programa + 2;
	apuntador_de_marco->argumentos = apuntador_de_pila - 1;
	ejecutar(simbolo->u.definicion);
	regresando = 0;

}

void regreso_de_funcion()
{
	if(DEBUG) {
		printw("regreso_de_funcion\n");
		refresh();
	}

	Dato_de_pila dato;
	if(apuntador_de_marco->simbolo->tipo == PROCEDIMIENTO)
		error_en_ejecucion(apuntador_de_marco->simbolo->nombre, "Procedimientos no regresan nada");
	dato = sacar_de_pila();
	regresar();
	meter_a_pila(dato);
}

void regreso_de_procedimiento()
{
	if(DEBUG) {
		printw("regreso_de_procedimiento\n");
		refresh();
	}

	if(apuntador_de_marco->simbolo->tipo == FUNCION)
		error_en_ejecucion(apuntador_de_marco->simbolo->nombre, "Las funciones deben regresar valores");
	regresar();
}

void regresar()
{
	if(DEBUG) {
		printw("regresar\n");
		refresh();
	}

	for (int i=0; i<apuntador_de_marco->numero_de_argumentos; i++)
		sacar_de_pila();
	contador_de_programa = (Instruccion *) apuntador_de_marco->direccion_de_retorno;
	--apuntador_de_marco;
	regresando = 1;
}

void argumento()
{
	if(DEBUG) {
		printw("argumento\n");
		refresh();
	}

	Dato_de_pila dato;
	dato.valor = *obtener_argumento();
	meter_a_pila(dato);
}

void asignar_argumento()
{
	if(DEBUG) {
		printw("asignar_argumento\n");
		refresh();
	}

	Dato_de_pila dato;
	dato = sacar_de_pila();
	meter_a_pila(dato);
	*obtener_argumento() = dato.valor;
}

void imprimir_cadena()
{
	if(DEBUG) {
		printw("imrpimir_cadena\n");
		refresh();
	}

	printw("%s \n\n", (char *) *contador_de_programa++);
	refresh();
}
