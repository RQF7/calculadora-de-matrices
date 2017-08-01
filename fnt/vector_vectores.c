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
