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
