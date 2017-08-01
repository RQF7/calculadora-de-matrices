/* inicializar.c
 * Módulo de inicialización de tabla de símbolos.
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

#include "simbolo.h"
#include "programa.h"
#include "parser.tab.h"
#include <math.h>
#include <string.h>
#include <gmp.h>
#include <ncurses.h>

//static struct {
//	char *nombre;
//	double valor;
//} constantes[] = {
//	{"PI", 		3.14159265358979323846},
//	{"E", 		2.71828182845904523536},
//	{"GAMMA",	0.57721566490153286060},	/* Euler */
//	{"DEG", 	57.29577951308232087680},	/* deg/radian */
//	{"PHI", 	1.61803398874989484820},	/* golden ratio */
//	{0, 		0.0}
//};

static struct {
	char *nombre;
	double (*funcion)();
} funciones[] = {
	{"sin", 	sin},
	{"cos", 	cos},
	{"atan", 	atan},
	{"atan2",	atan},
	{"log", 	log},
	{"log10", 	log10},
	{"exp", 	exp},
	{"sqrt", 	sqrt},
	{"abs", 	fabs},
	{0, 		0}
};

static struct {
	char *nombre;
	int valor;
} palabras_clave[] = {
	{"si", 		SI},
	{"sino",	SINO},
	{"mientras",	MIENTRAS},
	{0,		0}
};

void inicializar()
{
	int indice;
	Simbolo *simbolo;

	/*for(indice = 0; constantes[indice].nombre; indice++)
		instalar(strdup(constantes[indice].nombre), CONSTANTE, nueva_matriz_escalar(constantes[indice].valor));*/
	for(indice = 0; funciones[indice].nombre; indice++){
		simbolo = instalar(strdup(funciones[indice].nombre), FUNCION_PRE, 0);
		simbolo->u.funcion = funciones[indice].funcion;
	}
	for(indice = 0; palabras_clave[indice].nombre; indice++)
		instalar(strdup(palabras_clave[indice].nombre), palabras_clave[indice].valor, 0);

	mpz_t res;
	mpz_init_set_ui(res, 1);
	instalar(strdup("res"), VARIABLE, nueva_matriz_escalar(res));
}
