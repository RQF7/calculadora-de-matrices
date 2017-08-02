/* vector.c
 *
 * Operaciones sobre estructura de vector.
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
