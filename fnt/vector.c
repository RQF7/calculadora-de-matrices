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

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

Vector *nuevo_vector(mpz_t valor)
{
	Vector *resultado;
	resultado = malloc(sizeof(Vector));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	Contenedor *contenedor = nuevo_contenedor();
	mpz_set(contenedor->valor, valor);

	resultado->primero = contenedor;
	resultado->ultimo = contenedor;
	resultado->num_elementos = 1;
	return resultado;
}

Vector *agregar_a_vector(Vector *vector, mpz_t valor)
{
	Contenedor *auxiliar;
	Contenedor *contenedor = nuevo_contenedor();
	mpz_set(contenedor->valor, valor);
	mpz_clear(valor);

	auxiliar = vector->primero;
	vector->primero = contenedor;
	contenedor->siguiente = auxiliar;
	auxiliar->anterior = contenedor;

	vector->num_elementos++;
	return vector;
}

void liberar_vector(Vector *vector)
{
	Contenedor *iterador, *auxiliar;
	auxiliar = iterador = vector->primero;
	while (auxiliar != NULL) {
		auxiliar = auxiliar->siguiente;
		mpz_clear(iterador->valor);
		free(iterador);
		iterador = auxiliar;
	}
	free(vector);
}

Contenedor *nuevo_contenedor()
{
	Contenedor *resultado;
	resultado = malloc(sizeof(Contenedor));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	resultado->siguiente = NULL;
	resultado->anterior = NULL;
	mpz_init(resultado->valor);
	return resultado;
}
