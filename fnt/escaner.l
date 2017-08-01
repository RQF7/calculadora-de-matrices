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

%{

#include "vector_str.h"
#include "matriz.h"
#include "simbolo.h"
#include "programa.h"
#include "parser.tab.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>
#include <gmp.h>

extern int numero_de_linea;
int *linea;
static Vector_str *historial = NULL;

int filtro_entrada();
char *reducir_cadena(char *cadena);
void agregar_a_historial(int longitud);
void borrar(int posicion);
int yywrap ();

#define YY_INPUT(buf,result,max_size) \
int contador = filtro_entrada(); \
for(int i=0; i<contador; i++) \
        buf[i] = linea[i]; \
result = contador; \

%}

%%

 /* Espacios en blanco */
[ \t]                           { ; }

 /* Expresiones de salida */
"salir"                         { printw("Hasta la próxima.\n"); liberar_vector_str(historial); return 0; }
<<EOF>>                         { printw("\nHasta la próxima.\n"); return 0; }

 /* Impresión */
"imprimir"                      { return IMPRIMIR; }

 /* Operadores de asignación */
"+="                            { return A_INCREMENTO; }
"-="                            { return A_DECREMENTO; }
"*="                            { return A_MULT; }
"/="                            { return A_DIVISION; }
"^="                            { return A_POTENCIA; }
".^="                           { return A_P_ESCALAR; }

 /* Incrementos/decrementos unitarios */
"++"                            { return INC_UNITARIO; }
"--"                            { return DEC_UNITARIO; }

 /* Operadores lógicos */
">"                             { return MAQ; }
">="                            { return MAI; }
"<"                             { return MEQ; }
"<="                            { return MEI; }
"=="                            { return IG; }
"!="                            { return DIS; }
"->"                            { return CONDICIONAL; }
"<->"                           { return BICONDICIONAL; }
"y"                             { return CONJUNCION; }
"o"                             { return DISYUNCION; }
"^^"                            { return DISYUNCION_EXCLUSIVA; }
"!"                             { return NEGACION; }

 /* Palabras reservadas */
"mientras"                      { return MIENTRAS; }
"si"                            { return SI; }
"sino"                          { return SINO; }
"ciclo"                         { return CICLO; }
"fin"                           { return FIN; }
"funcion"                       { return FUNC; }
"procedimiento"                 { return PROC; }
"regresar"                      { return REGRESAR; }

 /* Operadores compuestos */
".^"                            { return P_ESCALAR; }

 /* Número */
[0-9]+\.?|[0-9]*\.[0-9]*        { mpz_t d;
                                  mpz_init_set_str(d, yytext, 10);
                                  yylval.simbolo = instalar(strdup(""), NUMERO, nueva_matriz_escalar(d));
                                  return NUMERO; }

 /* Identificadores */
[a-zA-Z][a-zA-Z0-9]*            { Simbolo *simbolo;
                                  if((simbolo = buscar(yytext)) == 0)
                                        simbolo = instalar(strdup(yytext), INDEFINIDO, 0);
                                  yylval.simbolo = simbolo;
                                  return simbolo->tipo == INDEFINIDO ? VARIABLE : simbolo->tipo; }

 /* Argumentos */
$[0-9]+                         { yylval.num_args = atoi(yytext + 1);
                                  return ARGUMENTO; }

 /* Cadenas */
\".+\"                          { yylval.simbolo = (Simbolo *) reducir_cadena(strdup(yytext));
                                  return CADENA; }

 /* Saltos de línea */
[\n]                            { numero_de_linea++; return '\n'; }

 /* Todo lo demás */
.                               { return yytext[0]; }

%%

char *reducir_cadena(char *cadena)
{
        for(int i=0; i<strlen(cadena) - 2; i++)
                cadena[i] = cadena[i+1];
        cadena[strlen(cadena) - 2] = 0;
        return cadena;
}

int filtro_entrada()
{
        int x, y;
        int contador = 0;
        getyx(stdscr, y, x);
        int previos = x;
        Contenedor_str *iterador = NULL;

        if(historial != NULL)
                iterador = historial->primero;

        while(1) {

                getyx(stdscr, y, x);
                int caracter = getch();
                if(caracter == KEY_LEFT){
                        if(x == previos) continue;
                        move(y, x - 1);
                        refresh();
                        continue;
                }

                if(caracter == KEY_RIGHT){
                        if(x - previos == contador) continue;
                        move(y, x + 1);
                        refresh();
                        continue;
                }

                if(caracter == KEY_UP){
                        if(iterador == NULL) continue;
                        for(int i=x; i>previos; i--) {
                                move(y, i - 1);
                                delch();
                                refresh();
                        }
                        for(contador=0; contador<strlen(iterador->cadena); contador++) {
                                linea[contador] = iterador->cadena[contador];
                                addch(linea[contador]);
                                refresh();
                        }
                        if(iterador->siguiente != NULL)
                                iterador = iterador->siguiente;
                }

                if(caracter == KEY_DOWN){
                        for(int i=x; i>previos; i--) {
                                move(y, i- 1);
                                delch();
                                refresh();
                        }
                        contador = 0;
                        if(iterador == NULL) continue;
                        if(iterador->anterior != NULL)
                                iterador = iterador->anterior;
                        else continue;
                        for(contador=0; contador<strlen(iterador->cadena); contador++) {
                                linea[contador] = iterador->cadena[contador];
                                addch(linea[contador]);
                                refresh();
                        }
                }

                if(caracter == 127){ //Borrar
                        if(x == previos) continue;
                        move(y, x - 1);
                        contador--;
                        borrar(x - previos - 1);
                        delch();
                        refresh();
                        continue;
                }

                if(caracter == 9) { //TAB
                        if(x - previos == contador){
                                for(int i=0; i<8; i++) {
                                        linea[contador] = ' ';
                                        contador++;
                                        addch(' ');
                                        refresh();
                                }
                        }
                }

                if(isprint(caracter)) {

                        if(x - previos == contador){
                                linea[contador] = caracter;
                                contador++;
                                addch(caracter);
                                refresh();
                        }else{
                                int respaldo = x;
                                contador++;
                                while(x - previos != contador){
                                        int aux = linea[x - previos];
                                        linea[x - previos] = caracter;
                                        addch(caracter);
                                        caracter = aux;
                                        x++;
                                }
                                move(y, respaldo + 1);
                        }

                }

                if(caracter == '\n') {
                        linea[contador] = caracter;
                        contador++;
                        if(x - previos == contador)
                                addch(caracter);
                        else
                                mvaddch(y, previos + contador, caracter);
                        if(contador > 1)
                                agregar_a_historial(contador);
                        return contador;
                }
        }
}

void agregar_a_historial(int longitud)
{
        char *nueva_cadena = malloc(sizeof(char) * longitud);
        for(int i=0; i<longitud-1; i++)
                nueva_cadena[i] = linea[i];
        nueva_cadena[longitud -1] = 0;
        if(historial == NULL)
                historial = nuevo_vector_str(nueva_cadena);
        else
                agregar_a_vector_str(historial, nueva_cadena);
}

void borrar(int posicion)
{
        int aux, num_elementos;
        getmaxyx(stdscr, aux, num_elementos);
        for(int i = posicion; posicion < num_elementos - 1; posicion++)
                linea[posicion] = linea[posicion + 1];
}

int yywrap ()
{
        return 1;
}
