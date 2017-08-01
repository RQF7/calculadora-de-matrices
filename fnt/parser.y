/* parser.y
 * Método main de programa.
 * Especificación de analizador sintáctico.
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

%{

#include "programa.h"
#include "matriz.h"
#include "vector_vectores.h"
#include "vector.h"
#include "simbolo.h"
#include "inicializar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <curses.h>
#include <locale.h>

#define codificar2(c1, c2)      codificar(c1); codificar(c2)
#define codificar3(c1, c2, c3)  codificar(c1); codificar(c2); codificar(c3)

int yylex ();
void comprobacion(Simbolo *simbolo);
void actualizar_res(Matriz *matriz);
void yyerror (char *mensaje);
void peligro (char *mensaje, char *detalle);
void error_en_ejecucion (char *mensaje, char *detalle);
void error_matrices_catch ();
void iniciar_ncurses();
void solo_definicion(char *mensaje);

int dentro_de_definicion = 0;

%}

%union {
        Simbolo *simbolo;
        Instruccion *instruccion;
        int num_args;
}

%token <simbolo>   NUMERO
%token <simbolo>   VARIABLE
%token <simbolo>   CONSTANTE
%token <simbolo>   INDEFINIDO
%token <simbolo>   MIENTRAS
%token <simbolo>   FUNCION_PRE
%token <simbolo>   SI
%token <simbolo>   SINO
%token <simbolo>   FIN
%token <simbolo>   CICLO
%token <simbolo>   IMPRIMIR
%token <simbolo>   CADENA
%token <simbolo>   FUNCION FUNC
%token <simbolo>   PROCEDIMIENTO PROC
%token <simbolo>   REGRESAR
%token <simbolo>   LEER
%token <num_args>  ARGUMENTO
%type  <instruccion> declaracion asignacion condicion matriz exp_interior comienzo
%type  <instruccion> mientras si final lsdeclaracion lsimprimir expresion ciclo
%type  <simbolo> id_funcion
%type  <num_args> lsargumento
%right '=' A_INCREMENTO A_DECREMENTO
%right A_MULT A_DIVISION
%right A_POTENCIA A_P_ESCALAR
%left CONDICIONAL BICONDICIONAL
%left DISYUNCION DISYUNCION_EXCLUSIVA
%left CONJUNCION
%left MAQ MAI MEQ MEI IG DIS
%left '+' '-'
%left '*'
%left NEGATIVO NEGACION
%right '^' P_ESCALAR
%right '\''
%right INC_UNITARIO DEC_UNITARIO

%%

lista:          /* nada */
        |       lista '\n'                              { printw("Expresión> "); refresh(); }
        |       lista definicion '\n'                   { printw("\nExpresión> ");
                                                          refresh(); }
        |       lista expresion '\n'                    { codificar3(asignar_default, imprimir_exp, DETENER);
                                                          return 1; }
        |       lista expresion ';' '\n'                { codificar3(asignar_default, instruccion_vacia, DETENER);
                                                          return 1; }
        |       lista asignacion '\n'                   { codificar2(imprimir, DETENER); return 1; }
        |       lista asignacion ';' '\n'               { codificar2(instruccion_vacia, DETENER); return 1; }
        |       lista declaracion                       { codificar(DETENER); return 1; }
        |       lista error '\n'                        { yyerrok; printw("\nExpresión> ");
                                                          refresh(); }
        ;

asignacion:     VARIABLE '=' expresion                  { $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       ARGUMENTO '=' expresion                 { solo_definicion("$"); $$ = $3;
                                                          codificar2(asignar_argumento, (Instruccion) (long int) $1); }
        |       VARIABLE A_INCREMENTO expresion         { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, sumar); $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE A_DECREMENTO expresion         { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, restar); $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE A_MULT expresion               { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, multiplicar); $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE A_DIVISION expresion           { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, dividir); $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE A_POTENCIA expresion           { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, elevar_a_potencia); $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE A_P_ESCALAR expresion          { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar2(voltear_operandos, elevar_a_potencia_escalar);
                                                          $$ = $3;
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        |       VARIABLE INC_UNITARIO                   { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar(incremento_unitario);
                                                          codificar3(meter_variable, (Instruccion) $1, asignar);}
        |       VARIABLE DEC_UNITARIO                   { codificar3(meter_variable, (Instruccion)$1, evaluar);
                                                          codificar(decremento_unitario);
                                                          codificar3(meter_variable, (Instruccion) $1, asignar); }
        ;

declaracion:    IMPRIMIR expresion                      { codificar(instruccion_imprimir); $$ = $2; }
        |       IMPRIMIR lsimprimir                     { $$ = $2; }
        |       REGRESAR                                { solo_definicion("return");
                                                          codificar(regreso_de_procedimiento); }
        |       REGRESAR expresion                      { solo_definicion("return");
                                                          codificar(regreso_de_funcion); $$ = $2; }
        |       PROCEDIMIENTO comienzo '(' lsargumento ')' {
                                                          $$ = $2;
                                                          codificar3(llamada, (Instruccion) $1, (Instruccion) (long int) $4); }
        |       mientras condicion ':' '\n' lsdeclaracion final {
                                                          ($1)[1] = (Instruccion)$5; ($1)[2] = (Instruccion)$6; }
        |       si condicion ':' '\n' lsdeclaracion final {
                                                          ($1)[1] = (Instruccion)$5; ($1)[3] = (Instruccion)$6; }
        |       si condicion ':' '\n' lsdeclaracion final SINO ':' '\n' lsdeclaracion final {
                                                          ($1)[1] = (Instruccion)$5; ($1)[2] = (Instruccion)$10;
                                                          ($1)[3] = (Instruccion)$11; }
        |       ciclo exp_interior ';' exp_interior ';' exp_interior ':' '\n' lsdeclaracion final {
                                                          ($1)[1] = (Instruccion)$9; ($1)[2] = (Instruccion)$10;
                                                          ($1)[3] = (Instruccion)$2; ($1)[4] = (Instruccion)$4;
                                                          ($1)[5] = (Instruccion)$6; }
        ;

condicion:      expresion                               { codificar(DETENER); $$ = $1; }
        ;

mientras:       MIENTRAS                                { $$ = codificar3(codigo_mientras, DETENER, DETENER); }
        ;

si:             SI                                      { $$ = codificar(codigo_si);
                                                          codificar3(DETENER, DETENER, DETENER); }
        ;

ciclo:          CICLO                                   { $$ = codificar3(codigo_ciclo, DETENER, DETENER);
                                                          codificar3(DETENER, DETENER, DETENER); }
        ;

final:          FIN                                     { codificar(DETENER); $$ = apuntador_de_programa; }
        ;

exp_interior:   /* nada */                              { $$ = apuntador_de_programa; }
        |       asignacion                              { codificar(DETENER); }
        |       expresion                               { codificar(DETENER); }
        ;

lsdeclaracion:  /* nada */                              {  printw("\t"); refresh();
                                                          $$ = apuntador_de_programa; }
        |       lsdeclaracion expresion '\n'            { printw("\t"); refresh(); }
        |       lsdeclaracion declaracion '\n'          { printw("\t"); refresh(); }
        ;

expresion:      matriz
        |       NUMERO                                  { $$ = codificar2(meter_constante, (Instruccion) $1); }
        |       VARIABLE                                { $$ = codificar3(meter_variable, (Instruccion) $1, evaluar); }
        |       CONSTANTE                               { codificar2(meter_constante, (Instruccion) $1); }
        |       ARGUMENTO                               { solo_definicion("$");
                                                          $$ = codificar2(argumento, (Instruccion) (long int) $1); }
        |       asignacion
        |       FUNCION_PRE '(' expresion ')'           { codificar2(ejecutar_funcion_programa,
                                                          (Instruccion)$1->u.funcion); }
        |       FUNCION comienzo '(' lsargumento ')'    { $$ = $2;
                                                          codificar3(llamada, (Instruccion)$1, (Instruccion) (long int) $4);}
        |       expresion '+' expresion                 { codificar(sumar); }
        |       expresion '-' expresion                 { codificar(restar); }
        |       expresion '*' expresion                 { codificar(multiplicar); }
        |       expresion '/' expresion                 { codificar(dividir); }
        |       expresion '^' expresion                 { codificar(elevar_a_potencia); }
        |       expresion P_ESCALAR expresion           { codificar(elevar_a_potencia_escalar); }
        |       '(' expresion ')'                       { $$ = $2; }
        |       '-' expresion %prec NEGATIVO            { $$ = $2; codificar(negar); }
        |       expresion '\''                          { codificar(transponer); }
        |       expresion MAQ expresion                 { codificar(mayor_que); }
        |       expresion MAI expresion                 { codificar(mayor_o_igual); }
        |       expresion MEQ expresion                 { codificar(menor_que); }
        |       expresion MEI expresion                 { codificar(menor_o_igual); }
        |       expresion IG expresion                  { codificar(igual_a); }
        |       expresion DIS expresion                 { codificar(distinto_de); }
        |       expresion DISYUNCION expresion          { codificar(disyuncion); }
        |       expresion CONJUNCION expresion          { codificar(conjuncion); }
        |       expresion CONDICIONAL expresion         { codificar(condicional); }
        |       NEGACION expresion                      { $$ = $2; codificar(negacion); }
        |       expresion BICONDICIONAL expresion       { codificar(bicondicional); }
        |       expresion DISYUNCION_EXCLUSIVA expresion { codificar(disyuncion_exclusiva); }
        |       expresion INC_UNITARIO                  { codificar(incremento_unitario); }
        |       expresion DEC_UNITARIO                  { codificar(decremento_unitario); }
        ;

matriz:         '[' vectores ']'                        { $$ = codificar(terminar_construccion); }
        ;

vectores:       vector                                  { codificar(iniciar_vvectores); }
        |       vectores ';' vector                     { codificar(continuar_vvectores); }
        ;

vector:         expresion                               { codificar(iniciar_vector); }
        |       vector expresion                        { codificar(continuar_vector); }
        |       vector ',' expresion                    { codificar(continuar_vector); }
        ;

comienzo:       /* nada */                              { $$ = apuntador_de_programa; }
        ;

lsimprimir:     expresion                               { codificar(instruccion_imprimir); }
        |       CADENA                                  { $$ = codificar2(imprimir_cadena, (Instruccion) $1); }
        |       lsimprimir ',' expresion                { codificar(instruccion_imprimir); }
        |       lsimprimir ',' CADENA                   { codificar2(imprimir_cadena, (Instruccion) $3); }
        ;

definicion:     FUNC id_funcion                         { $2->tipo = FUNCION; dentro_de_definicion = 1; }
                '(' ')' ':' '\n' lsdeclaracion final    { codificar(regreso_de_procedimiento); definir($2);
                                                          dentro_de_definicion = 0; }
        |       PROC id_funcion                         { $2->tipo = PROCEDIMIENTO; dentro_de_definicion = 1; }
                '(' ')' ':' '\n' lsdeclaracion final    { codificar(regreso_de_procedimiento); definir($2);
                                                          dentro_de_definicion = 0; }
        ;

id_funcion:     VARIABLE
        |       FUNCION
        |       PROCEDIMIENTO
        ;

lsargumento:    /* nada */                              { $$ = 0; }
        |       expresion                               { $$ = 1; }
        |       lsargumento ',' expresion               { $$ = $1 + 1; }

%%

jmp_buf punto_de_inicio;
char *nombre_programa;
int numero_de_linea = 1;
extern int *linea;
extern Instruccion *programa_base;

int main (int agrc, char *argv[])
{
        iniciar_ncurses();
        nombre_programa = argv[0];
        inicializar();
        signal(SIGUSR1, error_matrices_catch);
        setjmp(punto_de_inicio);
        printw("\nExpresión> "); refresh();
        for(iniciar_codificacion(); yyparse(); iniciar_codificacion()){
                ejecutar(programa_base);
                printw("Expresión> "); refresh();
        }
        endwin();
        free(linea);
        return 0;
}

void iniciar_ncurses()
{
        int x, y;
        setlocale(LC_ALL, "");
        initscr();
        getmaxyx(stdscr, y, x);
        raw();
        keypad(stdscr, TRUE);
        idlok(stdscr, TRUE);
        wsetscrreg(stdscr, 0, y);
        scrollok(stdscr, TRUE);
        noecho();
        start_color();
        use_default_colors();
        init_pair(1, COLOR_BLUE, -1);
        init_pair(2, COLOR_RED, -1);
        linea = malloc(sizeof(int) * x);
        char *lin1 = "Calculadora de matrices";
        char *lin2 = "Ricardo Quezada Figueroa";
        char *lin3 = "Compiladores";
        char *lin4 = "ESCOM - IPN";
        char *lin5 = "Presiona <Enter> para iniciar";
        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        mvprintw(y/2 - 2, (x - strlen(lin1)) / 2, "%s", lin1);
        attroff(COLOR_PAIR(1));
        attroff(A_BOLD);
        mvprintw(y/2 - 1, (x - strlen(lin2)) / 2, "%s", lin2);
        mvprintw(y/2 - 0, (x - strlen(lin3)) / 2, "%s", lin3);
        mvprintw(y/2 + 1, (x - strlen(lin4)) / 2, "%s", lin4);
        mvprintw(y - 1, (x - strlen(lin5)) / 2, "%s", lin5);
        refresh();
        getch();
        clear();
        move(0, 0);
        refresh();
}

void comprobacion(Simbolo *simbolo)
{
        if(simbolo->tipo == INDEFINIDO)
                error_en_ejecucion("Variable no definida", simbolo->nombre);
}

void actualizar_res(Matriz *matriz)
{
        Simbolo *simbolo = buscar("res");
        simbolo->u.valor = matriz;
}

void yyerror (char *mensaje)
{
        peligro(mensaje, (char *) 0);
}

void peligro (char *mensaje, char *detalle)
{
        attron(COLOR_PAIR(2));
        printw("%s: %s.\n", nombre_programa, mensaje);
        if (detalle)
                printw(" %s. ", detalle);
        printw("Cerca de la línea %d.\n", numero_de_linea);
        attroff(COLOR_PAIR(2));
        refresh();
}

void error_en_ejecucion (char *mensaje, char *detalle)
{
        peligro(mensaje, detalle);
        longjmp(punto_de_inicio, 0);
}

void error_matrices_catch ()
{
        error_en_ejecucion("Excepción de operación con matrices", (char *) 0);
}

void solo_definicion (char *mensaje)
{
        if(!dentro_de_definicion)
                error_en_ejecucion(mensaje, "usado fuera de definición");
}
