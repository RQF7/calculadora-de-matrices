/* vector_str.h
 * Estrucntura de vector de cadenas.
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
