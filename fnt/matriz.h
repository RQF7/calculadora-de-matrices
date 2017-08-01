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
