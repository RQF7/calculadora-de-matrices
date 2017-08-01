/* vector_str.c
 * Operaciones sobre vector de cadenas.
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

#include "vector_str.h"
#include <stdio.h>
#include <stdlib.h>

Vector_str *nuevo_vector_str(char *cadena)
{
	Vector_str *resultado;
	resultado = malloc(sizeof(Vector_str));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	Contenedor_str *contenedor = nuevo_contenedor_str();
	contenedor->cadena = cadena;

	resultado->primero = contenedor;
	resultado->ultimo = contenedor;
	resultado->num_elementos = 1;
	return resultado;
}

Vector_str *agregar_a_vector_str(Vector_str *vector, char *cadena)
{
	Contenedor_str *auxiliar;
	Contenedor_str *contenedor = nuevo_contenedor_str();
	contenedor->cadena = cadena;

	auxiliar = vector->primero;
	vector->primero = contenedor;
	contenedor->siguiente = auxiliar;
	auxiliar->anterior = contenedor;

	vector->num_elementos++;
	return vector;
}

void liberar_vector_str(Vector_str *vector)
{
	Contenedor_str *iterador, *auxiliar;
	auxiliar = iterador = vector->primero;
	while (auxiliar != NULL) {
		auxiliar = auxiliar->siguiente;
		free(iterador->cadena);
		free(iterador);
		iterador = auxiliar;
	}
	free(vector);
}

Contenedor_str *nuevo_contenedor_str()
{
	Contenedor_str *resultado;
	resultado = malloc(sizeof(Contenedor_str));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	resultado->siguiente = NULL;
	resultado->anterior = NULL;
	resultado->cadena = 0;
	return resultado;
}
