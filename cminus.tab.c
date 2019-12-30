/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ELSE = 258,
     IF = 259,
     INT = 260,
     RETURN = 261,
     VOID = 262,
     WHILE = 263,
     ID = 264,
     NUM = 265,
     LTE = 266,
     GTE = 267,
     EQUAL = 268,
     NOTEQUAL = 269,
     IFX = 270
   };
#endif
/* Tokens.  */
#define ELSE 258
#define IF 259
#define INT 260
#define RETURN 261
#define VOID 262
#define WHILE 263
#define ID 264
#define NUM 265
#define LTE 266
#define GTE 267
#define EQUAL 268
#define NOTEQUAL 269
#define IFX 270




/* Copy the first part of user declarations.  */
#line 1 "cminus.y"
 
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "emitcode.h"
  #include "symtab.h"

  extern int yylineno;
  int yylex();
  void yyerror(const char *s);

  extern struct symbolAttributes parsedSymbolAttributes;

  extern struct symbolTable globalSymTab;
  extern struct symbolTable *CurrentScope;

  extern int LabelSeed;  // 标签计数器
  extern int NumOfParams;  // (函数)参数的个数
  extern int ArgList[3];  // 参数列表
  extern int ArgNum;  // 

  extern FILE *fp;
  int TextSection = 0; 


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "cminus.y"
{
   	int n;
  	char s[15];
}
/* Line 193 of yacc.c.  */
#line 156 "cminus.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 169 "cminus.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  110

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    29,    27,    21,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    16,
      25,    24,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    17,     2,    18,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    22,     2,    23,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    16,    20,
      27,    29,    31,    32,    33,    42,    44,    46,    50,    52,
      55,    60,    61,    67,    70,    71,    74,    75,    77,    79,
      81,    83,    85,    88,    90,    93,    94,   100,   105,   106,
     113,   115,   118,   122,   126,   128,   130,   135,   139,   141,
     143,   145,   147,   149,   151,   153,   157,   159,   161,   163,
     167,   169,   171,   173,   177,   179,   181,   183,   188,   190,
     191,   195
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    34,    -1,    -1,    34,    35,    -1,
      35,    -1,    36,    -1,    38,    -1,    37,     9,    16,    -1,
      37,     9,    17,    10,    18,    16,    -1,     5,    -1,     7,
      -1,    -1,    -1,    37,     9,    19,    39,    41,    20,    40,
      44,    -1,    42,    -1,     7,    -1,    42,    21,    43,    -1,
      43,    -1,    37,     9,    -1,    37,     9,    17,    18,    -1,
      -1,    22,    45,    46,    47,    23,    -1,    46,    36,    -1,
      -1,    47,    48,    -1,    -1,    49,    -1,    44,    -1,    50,
      -1,    53,    -1,    56,    -1,    57,    16,    -1,    16,    -1,
      52,    48,    -1,    -1,    52,    48,     3,    51,    48,    -1,
       4,    19,    57,    20,    -1,    -1,    55,    19,    57,    20,
      54,    48,    -1,     8,    -1,     6,    16,    -1,     6,    57,
      16,    -1,    58,    24,    57,    -1,    59,    -1,     9,    -1,
       9,    17,    57,    18,    -1,    61,    60,    61,    -1,    61,
      -1,    11,    -1,    25,    -1,    26,    -1,    12,    -1,    13,
      -1,    14,    -1,    61,    62,    63,    -1,    63,    -1,    27,
      -1,    28,    -1,    63,    64,    65,    -1,    65,    -1,    29,
      -1,    30,    -1,    19,    57,    20,    -1,    58,    -1,    66,
      -1,    10,    -1,     9,    19,    67,    20,    -1,    68,    -1,
      -1,    68,    21,    57,    -1,    57,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    54,    58,    59,    61,    62,    64,    68,
      76,    77,    80,    85,    80,    98,    98,   100,   101,   104,
     109,   123,   123,   131,   132,   134,   135,   137,   138,   139,
     140,   141,   143,   144,   147,   148,   148,   154,   163,   161,
     171,   175,   177,   191,   195,   198,   201,   210,   214,   218,
     218,   218,   218,   218,   218,   220,   224,   227,   228,   231,
     235,   238,   239,   242,   243,   248,   249,   254,   261,   261,
     263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "IF", "INT", "RETURN", "VOID",
  "WHILE", "ID", "NUM", "LTE", "GTE", "EQUAL", "NOTEQUAL", "IFX", "';'",
  "'['", "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "$accept", "program", "InitDataSection",
  "declaration_list", "declaration", "var_declaration", "type_specifier",
  "fun_declaration", "@1", "@2", "params", "param_list", "param",
  "compound_stmt", "@3", "local_declarations", "statement_list",
  "statement", "expression_stmt", "selection_stmt", "@4", "ifsubroutine",
  "iteration_stmt", "@5", "whilesubroutine", "return_stmt", "expression",
  "var", "simple_expression", "relop", "additive_expression", "addop",
  "term", "mulop", "factor", "call", "args", "arg_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,    59,    91,    93,    40,
      41,    44,   123,   125,    61,    60,    62,    43,    45,    42,
      47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    34,    34,    35,    35,    36,    36,
      37,    37,    39,    40,    38,    41,    41,    42,    42,    43,
      43,    45,    44,    46,    46,    47,    47,    48,    48,    48,
      48,    48,    49,    49,    50,    51,    50,    52,    54,    53,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    67,    67,
      68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     3,     6,
       1,     1,     0,     0,     8,     1,     1,     3,     1,     2,
       4,     0,     5,     2,     0,     2,     0,     1,     1,     1,
       1,     1,     2,     1,     2,     0,     5,     4,     0,     6,
       1,     2,     3,     3,     1,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     1,     0,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,    10,    11,     2,     5,     6,     0,
       7,     4,     0,     8,     0,    12,     0,     0,     0,    11,
       0,     0,    15,    18,     9,    19,    13,     0,     0,     0,
      17,    20,    21,    14,    24,    26,    23,     0,     0,     0,
       0,     0,    40,    45,    66,    33,     0,    22,    28,    25,
      27,    29,     0,    30,     0,    31,     0,    64,    44,    48,
      56,    60,    65,     0,    41,     0,     0,    69,     0,    34,
       0,    32,     0,    49,    52,    53,    54,    50,    51,    57,
      58,     0,     0,    61,    62,     0,     0,    42,     0,    71,
       0,    68,    63,    35,     0,    43,    64,    47,    55,    59,
      37,    46,    67,     0,     0,    38,    70,    36,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    17,    29,
      21,    22,    23,    48,    34,    35,    38,    49,    50,    51,
     104,    52,    53,   108,    54,    55,    56,    57,    58,    81,
      59,    82,    60,    85,    61,    62,    90,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int8 yypact[] =
{
     -71,     3,    11,   -71,   -71,   -71,    11,   -71,   -71,     1,
     -71,   -71,    39,   -71,    50,   -71,    -5,    34,    32,    47,
      35,    48,    33,   -71,   -71,    56,   -71,    11,    57,    52,
     -71,   -71,   -71,   -71,   -71,    11,   -71,    67,    -2,     7,
      58,    26,   -71,    42,   -71,   -71,    28,   -71,   -71,   -71,
     -71,   -71,    24,   -71,    59,   -71,    63,    60,   -71,    38,
      40,   -71,   -71,    28,   -71,    64,    28,    28,    61,    79,
      28,   -71,    28,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,    28,    28,   -71,   -71,    28,    65,   -71,    68,   -71,
      69,    62,   -71,   -71,    70,   -71,   -71,    44,    40,   -71,
     -71,   -71,   -71,    28,    24,   -71,   -71,   -71,    24,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,    81,    53,    -8,   -71,   -71,   -71,
     -71,   -71,    66,    71,   -71,   -71,   -71,   -51,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -41,   -70,   -71,   -71,
      10,   -71,    12,   -71,    13,   -71,   -71,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -17
static const yytype_int8 yytable[] =
{
      65,    69,    40,     3,    41,    68,    42,    43,    44,    20,
      12,    96,    96,    18,    45,    96,     4,    46,     5,    20,
      32,    47,    86,    13,    14,    88,    89,    37,    40,    94,
      41,    95,    42,    43,    44,    43,    44,    43,    44,     4,
      45,    19,    64,    46,    25,    46,    32,    46,    24,    73,
      74,    75,    76,   107,    27,    13,    14,   109,    15,    66,
      16,    67,   106,    77,    78,    79,    80,   -16,    26,    83,
      84,    79,    80,    28,    32,    31,    39,    63,    70,    71,
      87,    92,    93,   103,    72,   100,   101,    11,    36,   102,
     105,    97,     0,    30,    98,     0,     0,     0,    99,     0,
      33
};

static const yytype_int8 yycheck[] =
{
      41,    52,     4,     0,     6,    46,     8,     9,    10,    17,
       9,    81,    82,    18,    16,    85,     5,    19,     7,    27,
      22,    23,    63,    16,    17,    66,    67,    35,     4,    70,
       6,    72,     8,     9,    10,     9,    10,     9,    10,     5,
      16,     7,    16,    19,     9,    19,    22,    19,    16,    11,
      12,    13,    14,   104,    21,    16,    17,   108,    19,    17,
      10,    19,   103,    25,    26,    27,    28,    20,    20,    29,
      30,    27,    28,    17,    22,    18,     9,    19,    19,    16,
      16,    20,     3,    21,    24,    20,    18,     6,    35,    20,
      20,    81,    -1,    27,    82,    -1,    -1,    -1,    85,    -1,
      29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,     0,     5,     7,    34,    35,    36,    37,
      38,    35,     9,    16,    17,    19,    10,    39,    18,     7,
      37,    41,    42,    43,    16,     9,    20,    21,    17,    40,
      43,    18,    22,    44,    45,    46,    36,    37,    47,     9,
       4,     6,     8,     9,    10,    16,    19,    23,    44,    48,
      49,    50,    52,    53,    55,    56,    57,    58,    59,    61,
      63,    65,    66,    19,    16,    57,    17,    19,    57,    48,
      19,    16,    24,    11,    12,    13,    14,    25,    26,    27,
      28,    60,    62,    29,    30,    64,    57,    16,    57,    57,
      67,    68,    20,     3,    57,    57,    58,    61,    63,    65,
      20,    18,    20,    21,    51,    20,    57,    48,    54,    48
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 52 "cminus.y"
    {finalizeScope();;}
    break;

  case 3:
#line 54 "cminus.y"
    {fprintf(fp, "SECTION .data\n                                                \n");
						                   fprintf(fp, "ReturnMsg: db \"Return Value:%%i\", 10, 0\n");
                              ;}
    break;

  case 8:
#line 64 "cminus.y"
    {insertSymbol((yyvsp[(2) - (3)].s), parsedSymbolAttributes, VAR);
                                         strcpy((yyval.s), (yyvsp[(2) - (3)].s));
                                         resetparsedSymbolAttributes();
                                        ;}
    break;

  case 9:
#line 68 "cminus.y"
    {parsedSymbolAttributes.array = 1;
                                                     parsedSymbolAttributes.arrSize = (yyvsp[(4) - (6)].n);
                                                     insertSymbol((yyvsp[(2) - (6)].s), parsedSymbolAttributes, VAR);
                                                     strcpy((yyval.s), (yyvsp[(2) - (6)].s));
                                                     resetparsedSymbolAttributes();
                                                    ;}
    break;

  case 10:
#line 76 "cminus.y"
    {(yyval.n) = 0; parsedSymbolAttributes.type = 0;;}
    break;

  case 11:
#line 77 "cminus.y"
    {(yyval.n) = 1; parsedSymbolAttributes.type = 1;;}
    break;

  case 12:
#line 80 "cminus.y"
    {if(!TextSection++) fprintf(fp, "\nSECTION .text\nextern printf\n");
                                             emitDeclaration(FUNC, (yyvsp[(2) - (3)].s));
                                             /*funcBody = 1;*/
                                             initScope();
                                            ;}
    break;

  case 13:
#line 85 "cminus.y"
    {parsedSymbolAttributes.type = (yyvsp[(1) - (6)].n);
                                             parsedSymbolAttributes.parameters = NumOfParams;
                                             insertGlobalSymbol((yyvsp[(2) - (6)].s), parsedSymbolAttributes, FUNC);
											                       resetparsedSymbolAttributes();
                                             NumOfParams=0;
											                      ;}
    break;

  case 14:
#line 91 "cminus.y"
    {finalizeScope();
                                             if((yyvsp[(1) - (8)].n) == 1)
                                              	emitEpilogue();      
                                             releaseAllRegister();
                                            ;}
    break;

  case 17:
#line 100 "cminus.y"
    {NumOfParams++; ;}
    break;

  case 18:
#line 101 "cminus.y"
    {NumOfParams++; ;}
    break;

  case 19:
#line 104 "cminus.y"
    {parsedSymbolAttributes.parameters = NumOfParams + 1;
                                     parsedSymbolAttributes.initialized = 1;
                                     insertSymbol((yyvsp[(2) - (2)].s), parsedSymbolAttributes, VAR);
                                     resetparsedSymbolAttributes();
                                    ;}
    break;

  case 20:
#line 109 "cminus.y"
    {parsedSymbolAttributes.parameters = NumOfParams + 1;
                                     parsedSymbolAttributes.array = 1;
                                     parsedSymbolAttributes.initialized = 1;
                                     insertSymbol((yyvsp[(2) - (4)].s), parsedSymbolAttributes, VAR);
                                     resetparsedSymbolAttributes();
                                    ;}
    break;

  case 21:
#line 123 "cminus.y"
    {if(!inFunctionBody())
                                                            initScope();
                                                        ;}
    break;

  case 22:
#line 127 "cminus.y"
    {if(!inFunctionBody())
                          finalizeScope();;}
    break;

  case 23:
#line 131 "cminus.y"
    {emitDeclaration(VAR, (yyvsp[(2) - (2)].s));;}
    break;

  case 34:
#line 147 "cminus.y"
    {fprintf(fp, "EndIf%i:\n", (yyvsp[(1) - (2)].n));;}
    break;

  case 35:
#line 148 "cminus.y"
    {fprintf(fp, "jmp EndIfElse%i\n", (yyvsp[(1) - (3)].n));
                              					         fprintf(fp, "EndIf%i:\n", (yyvsp[(1) - (3)].n));
                      							            ;}
    break;

  case 36:
#line 151 "cminus.y"
    {fprintf(fp, "EndIfElse%i:\n", (yyvsp[(1) - (5)].n));;}
    break;

  case 37:
#line 154 "cminus.y"
    {(yyval.n) = LabelSeed; LabelSeed++;
                     					          fprintf(fp, "cmp %s, 1\n", regToString((yyvsp[(3) - (4)].n)));
                                        fprintf(fp, "jne EndIf%i\n", (yyval.n));
                                        releaseOneRegister();
                                       ;}
    break;

  case 38:
#line 163 "cminus.y"
    {fprintf(fp, "cmp %s, 1\n", regToString((yyvsp[(3) - (4)].n)));
                                     fprintf(fp, "jne EndWhile%i\n", (yyvsp[(1) - (4)].n));
                                     releaseOneRegister();
                                    ;}
    break;

  case 39:
#line 167 "cminus.y"
    {fprintf(fp, "jmp While%i\n", (yyvsp[(1) - (6)].n));
                                     fprintf(fp, "EndWhile%i:\n", (yyvsp[(1) - (6)].n));
                                    ;}
    break;

  case 40:
#line 171 "cminus.y"
    {(yyval.n) = LabelSeed; LabelSeed++; 
                            fprintf(fp, "While%i:\n", (yyval.n));
                           ;}
    break;

  case 41:
#line 175 "cminus.y"
    {emitEpilogue();;}
    break;

  case 42:
#line 177 "cminus.y"
    {if((yyvsp[(2) - (3)].n) == EAX){
										                    emitPrintReturn();
                                        emitEpilogue();
									                     }
                                       else{
                                        fprintf(fp, "mov eax, %s\n", regToString((yyvsp[(2) - (3)].n)));
										                    emitPrintReturn();
                                        emitEpilogue();
                                       }
                                       releaseOneRegister();
                                      ;}
    break;

  case 43:
#line 191 "cminus.y"
    {(yyval.n)=9;
                                     emitMemOp(STORE,(yyvsp[(1) - (3)].s),(yyvsp[(3) - (3)].n));
                                     releaseOneRegister();
                                    ;}
    break;

  case 44:
#line 195 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);;}
    break;

  case 45:
#line 198 "cminus.y"
    {lookup((yyvsp[(1) - (1)].s))->attr.references++; 
                             strcpy((yyval.s), (yyvsp[(1) - (1)].s));;}
    break;

  case 46:
#line 201 "cminus.y"
    {struct symbolEntry *tmp = lookup((yyvsp[(1) - (4)].s));
                             if(!tmp->attr.array)
                             printf("[Error]  %s is not an array", tmp->id);
                             tmp->attr.references++;
                             tmp->attr.regContainingArrIndex = (yyvsp[(3) - (4)].n);
                             strcpy((yyval.s), (yyvsp[(1) - (4)].s));
                            ;}
    break;

  case 47:
#line 210 "cminus.y"
    {(yyval.n)=(yyvsp[(1) - (3)].n);
                                                                    emitRelOp((yyvsp[(2) - (3)].n),(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));
                                                                    releaseOneRegister();
                                                                   ;}
    break;

  case 48:
#line 214 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);
                                                                   ;}
    break;

  case 49:
#line 218 "cminus.y"
    {(yyval.n)=LTEQU;;}
    break;

  case 50:
#line 218 "cminus.y"
    {(yyval.n)=LESS;;}
    break;

  case 51:
#line 218 "cminus.y"
    {(yyval.n)=GTR;;}
    break;

  case 52:
#line 218 "cminus.y"
    {(yyval.n)=GTEQU;;}
    break;

  case 53:
#line 218 "cminus.y"
    {(yyval.n)=EQU;;}
    break;

  case 54:
#line 218 "cminus.y"
    {(yyval.n)=NEQU;;}
    break;

  case 55:
#line 220 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (3)].n);
                                                         emitAluOp((yyvsp[(2) - (3)].n),(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));
                                                         releaseOneRegister();
                                                        ;}
    break;

  case 56:
#line 224 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);;}
    break;

  case 57:
#line 227 "cminus.y"
    {(yyval.n) = ADD;;}
    break;

  case 58:
#line 228 "cminus.y"
    {(yyval.n) = SUB;;}
    break;

  case 59:
#line 231 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (3)].n);
                             emitAluOp((yyvsp[(2) - (3)].n),(yyvsp[(1) - (3)].n),(yyvsp[(3) - (3)].n));
                             releaseOneRegister();
                            ;}
    break;

  case 60:
#line 235 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);;}
    break;

  case 61:
#line 238 "cminus.y"
    {(yyval.n) = MULT;;}
    break;

  case 62:
#line 239 "cminus.y"
    {(yyval.n) = DIV;;}
    break;

  case 63:
#line 242 "cminus.y"
    {(yyval.n) = (yyvsp[(2) - (3)].n);;}
    break;

  case 64:
#line 243 "cminus.y"
    {
                             (yyval.n) = nextFreeRegister();
                             emitMemOp(LOAD,(yyvsp[(1) - (1)].s),(yyval.n));
                            ;}
    break;

  case 65:
#line 248 "cminus.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);;}
    break;

  case 66:
#line 249 "cminus.y"
    {(yyval.n)=nextFreeRegister();
                             emitLoadConst((yyval.n), (yyvsp[(1) - (1)].n));
                            ;}
    break;

  case 67:
#line 254 "cminus.y"
    {
                         emitCall((yyvsp[(1) - (4)].s), ArgList);
                         (yyval.n)=nextFreeRegister();
                         NumOfParams=0;
                        ;}
    break;

  case 70:
#line 263 "cminus.y"
    {ArgList[NumOfParams++] = (yyvsp[(3) - (3)].n);;}
    break;

  case 71:
#line 264 "cminus.y"
    {ArgList[NumOfParams++] = (yyvsp[(1) - (1)].n);;}
    break;


/* Line 1267 of yacc.c.  */
#line 1812 "cminus.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 267 "cminus.y"


int main() 
{	
	fp = fopen ("out/output.asm", "w");

	if(!yyparse())
  {
    printf("\nParsing complete!\n");
  }	
	else
  {
    printf("\nParsing failed!\n");
  }
	fclose(fp);

  return 0;
}

void yyerror (char const *s)
{
  fprintf(stderr, "%s, line: %i\n", s, yylineno);
}



