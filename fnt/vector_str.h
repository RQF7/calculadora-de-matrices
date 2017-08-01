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

#ifndef __VECTOR_STR_H__
#define __VECTOR_STR_H__

typedef struct Contenedor_str {
	char *cadena;
	struct Contenedor_str *siguiente;
	struct Contenedor_str *anterior;
} Contenedor_str;

typedef struct Vector_str {
	Contenedor_str *primero;
	Contenedor_str *ultimo;
	int num_elementos;
} Vector_str;

Vector_str *nuevo_vector_str(char *cadena);
Vector_str *agregar_a_vector_str(Vector_str *vector_str, char *cadena);
Contenedor_str *nuevo_contenedor_str();
void liberar_vector_str(Vector_str *vector);

#endif
