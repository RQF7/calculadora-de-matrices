/* simbolo.c
 * Operaciones sobre tabla de símbolos.
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
	for(iterador = lista_simbolos; iterador != (Simbolo *) 0; 
		iterador = iterador->siguiente)
		if(strcmp(iterador->nombre, nombre) == 0)
			return iterador;
	return 0;
}
