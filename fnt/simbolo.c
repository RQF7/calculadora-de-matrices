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

#include "matriz.h"
#include "simbolo.h"
#include "programa.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Simbolo *lista_simbolos = 0;

Simbolo *instalar (char *nombre, int tipo, Matriz *valor)
{
	Simbolo *nuevo = malloc(sizeof(Simbolo));
	if(!nuevo) {
		fprintf(stderr, "Memoria insuficiente.\n");
		exit(1);
	}

	nuevo->nombre = nombre;
	nuevo->tipo = tipo;
	nuevo->u.valor = valor;

	nuevo->siguiente = lista_simbolos;
	lista_simbolos = nuevo;
	return nuevo;
}

Simbolo *buscar (char *nombre)
{
	Simbolo *iterador;
	for(iterador = lista_simbolos; iterador != (Simbolo *) 0; iterador = iterador->siguiente)
		if(strcmp(iterador->nombre, nombre) == 0)
			return iterador;
	return 0;
}
