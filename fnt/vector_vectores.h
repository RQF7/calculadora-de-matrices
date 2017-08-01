/* vector_vectores.h
 * Estructura de vector de vectores.
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

#ifndef __VECTOR_VECTORES_H__
#define __VECTOR_VECTORES_H__

#include "vector.h"

typedef struct VVectores_contenedor {
	Vector *vector;
	struct VVectores_contenedor* anterior;
	struct VVectores_contenedor* siguiente;
} VVectores_contenedor;

typedef struct VVectores {
	int num_elementos;
	struct VVectores_contenedor* primero;
	struct VVectores_contenedor* ultimo;
} VVectores;

VVectores *nuevo_vvectores (Vector *vector);
VVectores *agregar_a_vvectores (VVectores *vvectores, Vector *vector);
void liberar_vvectores (VVectores *vvectores);

#endif
