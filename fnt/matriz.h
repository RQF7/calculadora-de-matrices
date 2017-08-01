/* matriz.h
 * Cabecera de implementación de operaciones sobre matrices.
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

#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include "vector_vectores.h"
#include "vector.h"
#include <gmp.h>

typedef struct Matriz {
	int filas;
	int columnas;
	mpz_t **datos;
} Matriz;

Matriz *nueva_matriz(VVectores *vvectores);
Matriz *nueva_matriz_escalar(mpz_t escalar);
Matriz *suma_matrices(Matriz *a, Matriz *b);
Matriz *resta_matrices(Matriz *a, Matriz *b);
Matriz *multiplica_matrices(Matriz *a, Matriz *b);
Matriz *division_escalar(Matriz *a, Matriz *b);
Matriz *potencia_matrices(Matriz *a, Matriz *b);
Matriz *potencia_escalar(Matriz *a, Matriz *b);
Matriz *mayor_que_matrices(Matriz *a, Matriz *b);
Matriz *mayor_o_igual_matrices(Matriz *a, Matriz *b);
Matriz *menor_que_matrices(Matriz *a, Matriz *b);
Matriz *menor_o_igual_matrices(Matriz *a, Matriz *b);
Matriz *igual_a_matrices(Matriz *a, Matriz *b);
Matriz *distinto_de_matrices(Matriz *a, Matriz *b);
Matriz *disyuncion_matrices(Matriz *a, Matriz *b);
Matriz *disyuncion_exclusiva_matrices(Matriz *a, Matriz *b);
Matriz *conjuncion_matrices(Matriz *a, Matriz *b);
Matriz *condicional_matrices(Matriz *a, Matriz *b);
Matriz *bicondicional_matrices(Matriz *a, Matriz *b);
Matriz *negacion_matrices(Matriz *a);
int evaluar_matriz(Matriz *a);
Matriz *ejecutar_funcion(Matriz *matriz, double (*funcion)());
Matriz *transpuesta(Matriz *matriz);
void imprimir_matriz(Matriz *matriz);
void liberar_matriz(Matriz *matriz);
Vector *agregar_matriz_a_vector(Vector *vector, Matriz *matriz);
Vector *nuevo_vector_de_matriz(Matriz *matriz);

#endif
