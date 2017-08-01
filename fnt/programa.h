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

#ifndef __PROGRAMA_H__
#define __PROGRAMA_H__

#include "simbolo.h"
#include "matriz.h"

#define DEBUG 0

/* Funciones globales */
void error_en_ejecucion (char *mensaje, char *detalle);

typedef union Dato_de_pila {
	Matriz *valor;
	Simbolo *simbolo;
} Dato_de_pila;

typedef void (*Instruccion)();
#define DETENER (Instruccion) 0
extern Instruccion programa[];
extern Instruccion *apuntador_de_programa;

void iniciar_codificacion();
Dato_de_pila sacar_de_pila();
void meter_a_pila(Dato_de_pila d);
Instruccion *codificar(Instruccion instruccion);
void ejecutar(Instruccion *instruccion);
void definir(Simbolo *simbolo);
Matriz **obtener_argumento();

void asignar();
void asignar_default();
void imprimir();
void imprimir_exp();
void evaluar();
void meter_variable();
void meter_constante();
void ejecutar_funcion_programa();
void sumar();
void restar();
void multiplicar();
void dividir();
void elevar_a_potencia();
void elevar_a_potencia_escalar();
void negar();
void transponer();
void incremento_unitario();
void decremento_unitario();
void iniciar_vector();
void continuar_vector();
void iniciar_vvectores();
void continuar_vvectores();
void terminar_construccion();
void instruccion_vacia();
void voltear_operandos();
void codigo_si();
void codigo_mientras();
void codigo_ciclo();
void mayor_que();
void mayor_o_igual();
void menor_que();
void menor_o_igual();
void igual_a();
void distinto_de();
void disyuncion();
void disyuncion_exclusiva();
void conjuncion();
void condicional();
void bicondicional();
void negacion();
void instruccion_imprimir();
void llamada();
void regreso_de_funcion();
void regreso_de_procedimiento();
void regresar();
void argumento();
void asignar_argumento();
void imprimir_cadena();
//void leer_variable();

#endif
