/* programa.h
 * Cabecera y estructuras de operaciones de programa.
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
