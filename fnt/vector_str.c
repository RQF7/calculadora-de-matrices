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
