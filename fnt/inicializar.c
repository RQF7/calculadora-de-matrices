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
