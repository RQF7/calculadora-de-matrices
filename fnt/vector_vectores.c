/* vector_vectores.c
 * Operaciones sobre vector de vectores.
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

#include "vector_vectores.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

VVectores_contenedor *nuevo_contenedor_vvectores ();

VVectores *nuevo_vvectores (Vector *vector)
{
	VVectores *resultado;
	resultado = malloc(sizeof(VVectores));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	VVectores_contenedor *contenedor = nuevo_contenedor_vvectores();
	contenedor->vector = vector;

	resultado->num_elementos = 1;
	resultado->primero = contenedor;
	resultado->ultimo = contenedor;
	return resultado;
}

VVectores *agregar_a_vvectores (VVectores *vvector, Vector *vector)
{
	VVectores_contenedor *auxiliar, *contenedor;
	contenedor = nuevo_contenedor_vvectores();
	contenedor->vector = vector;

	auxiliar = vvector->ultimo;
	vvector->ultimo = contenedor;
	contenedor->anterior = auxiliar;
	auxiliar->siguiente = contenedor;

	vvector->num_elementos++;
	return vvector;
}

void liberar_vvectores (VVectores *vvector)
{
	VVectores_contenedor *it, *aux;
	aux = it = vvector->primero;
	while (aux != NULL) {
		aux = aux->siguiente;
		liberar_vector(it->vector);
		it = aux;
	}
	free(vvector);
}

VVectores_contenedor *nuevo_contenedor_vvectores ()
{
	VVectores_contenedor *resultado;
	resultado = malloc(sizeof(VVectores_contenedor));
	if(!resultado) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	resultado->vector = NULL;
	resultado->anterior = NULL;
	resultado->siguiente = NULL;
	return resultado;
}
