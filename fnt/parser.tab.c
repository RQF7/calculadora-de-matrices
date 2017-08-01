/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "fnt/parser.y" /* yacc.c:339  */


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


#line 99 "fnt/parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 51 "fnt/parser.y" /* yacc.c:355  */

        Simbolo *simbolo;
        Instruccion *instruccion;
        int num_args;

#line 189 "fnt/parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FNT_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "fnt/parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      52,    53,    42,    40,    58,    41,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    51,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    43,    44,    46,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    96,    98,   100,   102,   103,   104,
     105,   109,   111,   113,   116,   119,   122,   125,   128,   132,
     135,   140,   141,   142,   144,   146,   149,   151,   153,   156,
     162,   165,   168,   172,   176,   179,   180,   181,   184,   186,
     187,   190,   191,   192,   193,   194,   196,   197,   199,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   226,   229,   230,   233,   234,   235,   238,   241,
     242,   243,   244,   247,   247,   250,   250,   255,   256,   257,
     260,   261,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "VARIABLE", "CONSTANTE",
  "INDEFINIDO", "MIENTRAS", "FUNCION_PRE", "SI", "SINO", "FIN", "CICLO",
  "IMPRIMIR", "CADENA", "FUNCION", "FUNC", "PROCEDIMIENTO", "PROC",
  "REGRESAR", "LEER", "ARGUMENTO", "'='", "A_INCREMENTO", "A_DECREMENTO",
  "A_MULT", "A_DIVISION", "A_POTENCIA", "A_P_ESCALAR", "CONDICIONAL",
  "BICONDICIONAL", "DISYUNCION", "DISYUNCION_EXCLUSIVA", "CONJUNCION",
  "MAQ", "MAI", "MEQ", "MEI", "IG", "DIS", "'+'", "'-'", "'*'", "NEGATIVO",
  "NEGACION", "'^'", "P_ESCALAR", "'\\''", "INC_UNITARIO", "DEC_UNITARIO",
  "'\\n'", "';'", "'('", "')'", "':'", "'/'", "'['", "']'", "','",
  "$accept", "lista", "asignacion", "declaracion", "condicion", "mientras",
  "si", "ciclo", "final", "exp_interior", "lsdeclaracion", "expresion",
  "matriz", "vectores", "vector", "comienzo", "lsimprimir", "definicion",
  "$@1", "$@2", "id_funcion", "lsargumento", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    61,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
      43,    45,    42,   294,   295,    94,   296,    39,   297,   298,
      10,    59,    40,    41,    58,    47,    91,    93,    44
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,   115,  -126,   -28,  -126,   250,  -126,  -126,   -24,  -126,
    -126,   184,  -126,    39,  -126,    39,   227,    22,   227,   227,
    -126,   227,   227,    36,  -126,   227,   227,   227,   285,  -126,
     -20,  -126,   227,   227,   227,   227,   227,   227,   227,  -126,
    -126,   227,  -126,  -126,   255,   -10,     3,  -126,  -126,  -126,
    -126,     6,  -126,   393,   227,   -41,   -41,   312,   393,   -48,
       8,  -126,    11,     9,   393,    34,    -9,    14,   393,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,  -126,  -126,  -126,  -126,    51,
     227,  -126,   393,   393,   393,   393,   393,   393,   393,   339,
     208,   227,    46,   227,    52,   393,  -126,   227,  -126,   227,
     393,  -126,    55,    57,   227,   418,   418,   441,   441,   463,
     102,   102,   102,   102,   102,   102,    48,    48,   -41,   -41,
     -41,  -126,   393,  -126,  -126,   393,   393,    -7,    56,     4,
      58,     8,   393,  -126,  -126,    59,  -126,   227,    63,  -126,
      67,   165,   165,   227,   393,    62,    75,  -126,    76,  -126,
     366,   119,    81,  -126,  -126,  -126,  -126,    83,    88,   165,
     165,    89,  -126,  -126,  -126,  -126,   165,   165,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    42,    43,    44,    31,     0,    32,
      33,     0,    78,     0,    78,     0,    23,    45,     0,     0,
       3,     0,     0,    46,     9,     0,     0,    35,     0,    41,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,    80,    46,    21,    22,     0,    87,    88,    89,
      83,     0,    85,    24,     0,    56,    67,     0,    75,     0,
      73,     7,     0,     0,    30,     0,    46,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    70,    71,     5,     0,
       0,     4,    11,    13,    14,    15,    16,    17,    18,     0,
       0,    90,     0,    90,     0,    12,    55,     0,    72,     0,
      76,     8,     0,     0,    35,    66,    68,    64,    69,    65,
      58,    59,    60,    61,    62,    63,    49,    50,    51,    53,
      54,     6,    52,    47,    82,    81,    91,     0,     0,     0,
       0,    74,    77,    38,    38,     0,    48,     0,     0,    25,
       0,     0,     0,    35,    92,     0,     0,    34,     0,    26,
       0,    27,     0,    38,    38,    40,    39,     0,     0,     0,
       0,     0,    38,    84,    86,    38,     0,     0,    29,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,     0,   140,   128,  -126,  -126,  -126,   -85,  -112,
    -125,    -1,  -126,  -126,    38,   141,  -126,  -126,  -126,  -126,
     143,    60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    43,   158,    63,    25,    26,    27,   159,    67,
     151,   160,    29,    59,    60,    46,    45,    30,   102,   104,
      50,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    23,   145,   107,    83,    84,    85,    86,    87,   108,
      44,     4,     5,     6,    90,    53,     8,    55,    56,   152,
      57,    58,    31,    12,    64,    64,    68,    66,    41,    17,
      91,    92,    93,    94,    95,    96,    97,    98,   169,   170,
      99,   162,   -36,    47,    54,   -36,   146,   176,   100,    18,
     177,   147,    19,   105,    48,   101,    49,   149,   103,   110,
      21,   111,   147,   112,    22,   114,   109,   161,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   173,   174,    61,    62,   113,   132,
      82,   178,   179,    83,    84,    85,    86,    87,   138,   135,
     136,   131,   136,    90,   140,   143,    58,   144,   142,   148,
     153,   150,   163,    68,    66,     2,     3,   155,     4,     5,
       6,   156,     7,     8,     9,   164,   165,    10,    11,   167,
      12,    13,    14,    15,    16,   168,    17,   171,   172,   175,
     110,    24,    80,    81,    82,   141,   154,    83,    84,    85,
      86,    87,    68,    66,    65,    51,    18,    90,    52,    19,
       0,     0,     0,   139,     0,    20,     0,    21,     4,     5,
       6,    22,     7,     8,     9,     0,   157,    10,    11,     0,
      12,     0,    14,     0,    16,     0,    17,     4,     5,     6,
       0,     0,     8,     0,     0,     0,     0,     0,    42,    12,
       0,     0,     0,     0,     0,    17,    18,     0,     0,    19,
       0,     4,     5,     6,     0,     0,     8,    21,     0,     0,
       0,    22,   134,    12,     0,    18,     0,     0,    19,    17,
       4,     5,     6,     0,     0,     8,    21,     0,     0,     0,
      22,     0,    12,     0,     0,     0,     0,     0,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,     0,     0,     0,    18,     0,
       0,    19,    32,    33,    34,    35,    36,    37,    38,    21,
       0,     0,     0,    22,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    39,    40,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
      90,     0,     0,   -79,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,   106,     0,    90,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,    83,    84,    85,    86,    87,     0,
       0,     0,   133,     0,    90,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,    83,    84,    85,    86,    87,   166,     0,     0,     0,
       0,    90,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,    90,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    90,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,    90,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,    90
};

static const yytype_int16 yycheck[] =
{
       1,     1,   114,    51,    45,    46,    47,    48,    49,    57,
      11,     3,     4,     5,    55,    16,     8,    18,    19,   144,
      21,    22,    50,    15,    25,    26,    27,    27,    52,    21,
      50,    32,    33,    34,    35,    36,    37,    38,   163,   164,
      41,   153,    51,     4,    22,    54,    53,   172,    58,    41,
     175,    58,    44,    54,    15,    52,    17,    53,    52,    60,
      52,    50,    58,    54,    56,    51,    58,   152,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   169,   170,    50,    51,    54,    90,
      42,   176,   177,    45,    46,    47,    48,    49,    52,   100,
     101,    50,   103,    55,    52,    50,   107,    50,   109,    53,
      51,    53,    50,   114,   114,     0,     1,    54,     3,     4,
       5,    54,     7,     8,     9,    50,    50,    12,    13,    10,
      15,    16,    17,    18,    19,    54,    21,    54,    50,    50,
     141,     1,    40,    41,    42,   107,   147,    45,    46,    47,
      48,    49,   153,   153,    26,    14,    41,    55,    15,    44,
      -1,    -1,    -1,   103,    -1,    50,    -1,    52,     3,     4,
       5,    56,     7,     8,     9,    -1,    11,    12,    13,    -1,
      15,    -1,    17,    -1,    19,    -1,    21,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    21,    41,    -1,    -1,    44,
      -1,     3,     4,     5,    -1,    -1,     8,    52,    -1,    -1,
      -1,    56,    14,    15,    -1,    41,    -1,    -1,    44,    21,
       3,     4,     5,    -1,    -1,     8,    52,    -1,    -1,    -1,
      56,    -1,    15,    -1,    -1,    -1,    -1,    -1,    21,    41,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    41,    -1,
      -1,    44,    22,    23,    24,    25,    26,    27,    28,    52,
      -1,    -1,    -1,    56,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    48,    49,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    53,    -1,    55,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    55,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    55,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    -1,    55,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,     0,     1,     3,     4,     5,     7,     8,     9,
      12,    13,    15,    16,    17,    18,    19,    21,    41,    44,
      50,    52,    56,    61,    62,    64,    65,    66,    70,    71,
      76,    50,    22,    23,    24,    25,    26,    27,    28,    48,
      49,    52,    14,    61,    70,    75,    74,     4,    15,    17,
      79,    74,    79,    70,    22,    70,    70,    70,    70,    72,
      73,    50,    51,    63,    70,    63,    61,    68,    70,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    45,    46,    47,    48,    49,    50,    51,
      55,    50,    70,    70,    70,    70,    70,    70,    70,    70,
      58,    52,    77,    52,    78,    70,    53,    51,    57,    58,
      70,    50,    54,    54,    51,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    50,    70,    53,    14,    70,    70,    80,    52,    80,
      52,    73,    70,    50,    50,    68,    53,    58,    53,    53,
      53,    69,    69,    51,    70,    54,    54,    11,    62,    67,
      70,    67,    68,    50,    50,    50,    50,    10,    54,    69,
      69,    54,    50,    67,    67,    50,    69,    69,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    65,    66,    67,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    72,    73,    73,    73,    74,    75,
      75,    75,    75,    77,    76,    78,    76,    79,    79,    79,
      80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     4,     3,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     1,     2,     5,     6,     6,    11,    10,
       1,     1,     1,     1,     1,     0,     1,     1,     0,     3,
       3,     1,     1,     1,     1,     1,     1,     4,     5,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       2,     2,     3,     1,     3,     1,     2,     3,     0,     1,
       1,     3,     3,     0,     9,     0,     9,     1,     1,     1,
       0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 95 "fnt/parser.y" /* yacc.c:1646  */
    { printw("Expresión> "); refresh(); }
#line 1475 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "fnt/parser.y" /* yacc.c:1646  */
    { printw("\nExpresión> ");
                                                          refresh(); }
#line 1482 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(asignar_default, imprimir_exp, DETENER);
                                                          return 1; }
#line 1489 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(asignar_default, instruccion_vacia, DETENER);
                                                          return 1; }
#line 1496 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "fnt/parser.y" /* yacc.c:1646  */
    { codificar2(imprimir, DETENER); return 1; }
#line 1502 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "fnt/parser.y" /* yacc.c:1646  */
    { codificar2(instruccion_vacia, DETENER); return 1; }
#line 1508 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(DETENER); return 1; }
#line 1514 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "fnt/parser.y" /* yacc.c:1646  */
    { yyerrok; printw("\nExpresión> ");
                                                          refresh(); }
#line 1521 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1528 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "fnt/parser.y" /* yacc.c:1646  */
    { solo_definicion("$"); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar2(asignar_argumento, (Instruccion) (long int) (yyvsp[-2].num_args)); }
#line 1535 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, sumar); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1543 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, restar); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1551 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 119 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, multiplicar); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1559 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, dividir); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1567 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 125 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, elevar_a_potencia); (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1575 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-2].simbolo), evaluar);
                                                          codificar2(voltear_operandos, elevar_a_potencia_escalar);
                                                          (yyval.instruccion) = (yyvsp[0].instruccion);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-2].simbolo), asignar); }
#line 1584 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-1].simbolo), evaluar);
                                                          codificar(incremento_unitario);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-1].simbolo), asignar);}
#line 1592 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "fnt/parser.y" /* yacc.c:1646  */
    { codificar3(meter_variable, (Instruccion)(yyvsp[-1].simbolo), evaluar);
                                                          codificar(decremento_unitario);
                                                          codificar3(meter_variable, (Instruccion) (yyvsp[-1].simbolo), asignar); }
#line 1600 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(instruccion_imprimir); (yyval.instruccion) = (yyvsp[0].instruccion); }
#line 1606 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[0].instruccion); }
#line 1612 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "fnt/parser.y" /* yacc.c:1646  */
    { solo_definicion("return");
                                                          codificar(regreso_de_procedimiento); }
#line 1619 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "fnt/parser.y" /* yacc.c:1646  */
    { solo_definicion("return");
                                                          codificar(regreso_de_funcion); (yyval.instruccion) = (yyvsp[0].instruccion); }
#line 1626 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "fnt/parser.y" /* yacc.c:1646  */
    {
                                                          (yyval.instruccion) = (yyvsp[-3].instruccion);
                                                          codificar3(llamada, (Instruccion) (yyvsp[-4].simbolo), (Instruccion) (long int) (yyvsp[-1].num_args)); }
#line 1634 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 149 "fnt/parser.y" /* yacc.c:1646  */
    {
                                                          ((yyvsp[-5].instruccion))[1] = (Instruccion)(yyvsp[-1].instruccion); ((yyvsp[-5].instruccion))[2] = (Instruccion)(yyvsp[0].instruccion); }
#line 1641 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 151 "fnt/parser.y" /* yacc.c:1646  */
    {
                                                          ((yyvsp[-5].instruccion))[1] = (Instruccion)(yyvsp[-1].instruccion); ((yyvsp[-5].instruccion))[3] = (Instruccion)(yyvsp[0].instruccion); }
#line 1648 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 153 "fnt/parser.y" /* yacc.c:1646  */
    {
                                                          ((yyvsp[-10].instruccion))[1] = (Instruccion)(yyvsp[-6].instruccion); ((yyvsp[-10].instruccion))[2] = (Instruccion)(yyvsp[-1].instruccion);
                                                          ((yyvsp[-10].instruccion))[3] = (Instruccion)(yyvsp[0].instruccion); }
#line 1656 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 156 "fnt/parser.y" /* yacc.c:1646  */
    {
                                                          ((yyvsp[-9].instruccion))[1] = (Instruccion)(yyvsp[-1].instruccion); ((yyvsp[-9].instruccion))[2] = (Instruccion)(yyvsp[0].instruccion);
                                                          ((yyvsp[-9].instruccion))[3] = (Instruccion)(yyvsp[-8].instruccion); ((yyvsp[-9].instruccion))[4] = (Instruccion)(yyvsp[-6].instruccion);
                                                          ((yyvsp[-9].instruccion))[5] = (Instruccion)(yyvsp[-4].instruccion); }
#line 1665 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(DETENER); (yyval.instruccion) = (yyvsp[0].instruccion); }
#line 1671 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 165 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar3(codigo_mientras, DETENER, DETENER); }
#line 1677 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 168 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar(codigo_si);
                                                          codificar3(DETENER, DETENER, DETENER); }
#line 1684 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 172 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar3(codigo_ciclo, DETENER, DETENER);
                                                          codificar3(DETENER, DETENER, DETENER); }
#line 1691 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 176 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(DETENER); (yyval.instruccion) = apuntador_de_programa; }
#line 1697 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = apuntador_de_programa; }
#line 1703 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(DETENER); }
#line 1709 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(DETENER); }
#line 1715 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "fnt/parser.y" /* yacc.c:1646  */
    {  printw("\t"); refresh();
                                                          (yyval.instruccion) = apuntador_de_programa; }
#line 1722 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "fnt/parser.y" /* yacc.c:1646  */
    { printw("\t"); refresh(); }
#line 1728 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 187 "fnt/parser.y" /* yacc.c:1646  */
    { printw("\t"); refresh(); }
#line 1734 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar2(meter_constante, (Instruccion) (yyvsp[0].simbolo)); }
#line 1740 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 192 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar3(meter_variable, (Instruccion) (yyvsp[0].simbolo), evaluar); }
#line 1746 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 193 "fnt/parser.y" /* yacc.c:1646  */
    { codificar2(meter_constante, (Instruccion) (yyvsp[0].simbolo)); }
#line 1752 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 194 "fnt/parser.y" /* yacc.c:1646  */
    { solo_definicion("$");
                                                          (yyval.instruccion) = codificar2(argumento, (Instruccion) (long int) (yyvsp[0].num_args)); }
#line 1759 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 197 "fnt/parser.y" /* yacc.c:1646  */
    { codificar2(ejecutar_funcion_programa,
                                                          (Instruccion)(yyvsp[-3].simbolo)->u.funcion); }
#line 1766 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[-3].instruccion);
                                                          codificar3(llamada, (Instruccion)(yyvsp[-4].simbolo), (Instruccion) (long int) (yyvsp[-1].num_args));}
#line 1773 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 201 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(sumar); }
#line 1779 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 202 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(restar); }
#line 1785 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 203 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(multiplicar); }
#line 1791 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 204 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(dividir); }
#line 1797 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 205 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(elevar_a_potencia); }
#line 1803 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 206 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(elevar_a_potencia_escalar); }
#line 1809 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 207 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[-1].instruccion); }
#line 1815 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 208 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[0].instruccion); codificar(negar); }
#line 1821 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 209 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(transponer); }
#line 1827 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 210 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(mayor_que); }
#line 1833 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 211 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(mayor_o_igual); }
#line 1839 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 212 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(menor_que); }
#line 1845 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 213 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(menor_o_igual); }
#line 1851 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 214 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(igual_a); }
#line 1857 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 215 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(distinto_de); }
#line 1863 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 216 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(disyuncion); }
#line 1869 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 217 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(conjuncion); }
#line 1875 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 218 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(condicional); }
#line 1881 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 219 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = (yyvsp[0].instruccion); codificar(negacion); }
#line 1887 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 220 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(bicondicional); }
#line 1893 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 221 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(disyuncion_exclusiva); }
#line 1899 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 222 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(incremento_unitario); }
#line 1905 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 223 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(decremento_unitario); }
#line 1911 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 226 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar(terminar_construccion); }
#line 1917 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 229 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(iniciar_vvectores); }
#line 1923 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 230 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(continuar_vvectores); }
#line 1929 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 233 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(iniciar_vector); }
#line 1935 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 234 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(continuar_vector); }
#line 1941 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 235 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(continuar_vector); }
#line 1947 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 238 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = apuntador_de_programa; }
#line 1953 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 241 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(instruccion_imprimir); }
#line 1959 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 242 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.instruccion) = codificar2(imprimir_cadena, (Instruccion) (yyvsp[0].simbolo)); }
#line 1965 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 243 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(instruccion_imprimir); }
#line 1971 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 244 "fnt/parser.y" /* yacc.c:1646  */
    { codificar2(imprimir_cadena, (Instruccion) (yyvsp[0].simbolo)); }
#line 1977 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 247 "fnt/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].simbolo)->tipo = FUNCION; dentro_de_definicion = 1; }
#line 1983 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 248 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(regreso_de_procedimiento); definir((yyvsp[-7].simbolo));
                                                          dentro_de_definicion = 0; }
#line 1990 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 250 "fnt/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].simbolo)->tipo = PROCEDIMIENTO; dentro_de_definicion = 1; }
#line 1996 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 251 "fnt/parser.y" /* yacc.c:1646  */
    { codificar(regreso_de_procedimiento); definir((yyvsp[-7].simbolo));
                                                          dentro_de_definicion = 0; }
#line 2003 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 260 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.num_args) = 0; }
#line 2009 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 261 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.num_args) = 1; }
#line 2015 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 262 "fnt/parser.y" /* yacc.c:1646  */
    { (yyval.num_args) = (yyvsp[-2].num_args) + 1; }
#line 2021 "fnt/parser.tab.c" /* yacc.c:1646  */
    break;


#line 2025 "fnt/parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 264 "fnt/parser.y" /* yacc.c:1906  */


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
