/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_FNT_PARSER_TAB_H_INCLUDED
# define YY_YY_FNT_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    VARIABLE = 259,
    CONSTANTE = 260,
    INDEFINIDO = 261,
    MIENTRAS = 262,
    FUNCION_PRE = 263,
    SI = 264,
    SINO = 265,
    FIN = 266,
    CICLO = 267,
    IMPRIMIR = 268,
    CADENA = 269,
    FUNCION = 270,
    FUNC = 271,
    PROCEDIMIENTO = 272,
    PROC = 273,
    REGRESAR = 274,
    LEER = 275,
    ARGUMENTO = 276,
    A_INCREMENTO = 277,
    A_DECREMENTO = 278,
    A_MULT = 279,
    A_DIVISION = 280,
    A_POTENCIA = 281,
    A_P_ESCALAR = 282,
    CONDICIONAL = 283,
    BICONDICIONAL = 284,
    DISYUNCION = 285,
    DISYUNCION_EXCLUSIVA = 286,
    CONJUNCION = 287,
    MAQ = 288,
    MAI = 289,
    MEQ = 290,
    MEI = 291,
    IG = 292,
    DIS = 293,
    NEGATIVO = 294,
    NEGACION = 295,
    P_ESCALAR = 296,
    INC_UNITARIO = 297,
    DEC_UNITARIO = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "fnt/parser.y" /* yacc.c:1909  */

        Simbolo *simbolo;
        Instruccion *instruccion;
        int num_args;

#line 104 "fnt/parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FNT_PARSER_TAB_H_INCLUDED  */
