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
     NUM = 258,
     ID = 259,
     STR = 260,
     INT = 261,
     BOOL = 262,
     STRING = 263,
     VOID = 264,
     EQUALS = 265,
     NOT_EQUALS = 266,
     NOT = 267,
     LESS_THAN = 268,
     LESS_THAN_EQUALS = 269,
     GREATER_THAN = 270,
     GREATER_THAN_EQUALS = 271,
     OPENING_PARENTHESIS = 272,
     CLOSING_PARENTHESIS = 273,
     OPENING_CURLY_BRACES = 274,
     CLOSING_CURLY_BRACES = 275,
     PLUS = 276,
     MINUS = 277,
     MULTIPLY = 278,
     MOD = 279,
     DIVIDE = 280,
     IF = 281,
     THEN = 282,
     ELSE = 283,
     TRUE = 284,
     FALSE = 285,
     SEMICOL = 286,
     STRUCT = 287,
     PRINTF = 288,
     ASSIGN = 289,
     FULLSTOP = 290,
     COMMA = 291,
     FOR = 292,
     RETURN = 293,
     EQU = 294,
     AND = 295,
     OR = 296,
     UMINUS = 297
   };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define STR 260
#define INT 261
#define BOOL 262
#define STRING 263
#define VOID 264
#define EQUALS 265
#define NOT_EQUALS 266
#define NOT 267
#define LESS_THAN 268
#define LESS_THAN_EQUALS 269
#define GREATER_THAN 270
#define GREATER_THAN_EQUALS 271
#define OPENING_PARENTHESIS 272
#define CLOSING_PARENTHESIS 273
#define OPENING_CURLY_BRACES 274
#define CLOSING_CURLY_BRACES 275
#define PLUS 276
#define MINUS 277
#define MULTIPLY 278
#define MOD 279
#define DIVIDE 280
#define IF 281
#define THEN 282
#define ELSE 283
#define TRUE 284
#define FALSE 285
#define SEMICOL 286
#define STRUCT 287
#define PRINTF 288
#define ASSIGN 289
#define FULLSTOP 290
#define COMMA 291
#define FOR 292
#define RETURN 293
#define EQU 294
#define AND 295
#define OR 296
#define UMINUS 297




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

 #include <stdio.h>
 #include<string.h>

 #include <stdlib.h>
 #include "S_table.h"
 #include "intable.h"
 extern FILE *yyin;
 extern int yylex();
int errors=0;
char *procedure;
char *t;
sublist *current;
char returnType;
char *v;
intable *li=NULL;
int i=0;
int j=0;
int k=0;
char *str="main";
char *temp;
char *rem;
int flag=0;
char *ar[1000];
int point=0;
init(char *name, char *type){
 
  li=putable(name,type,li,str);
  
}
checkinit(){
  sublist *ptr;
   displayTable();
   displayList(li);
  for (ptr = current; ptr != (sublist *)0; ptr = (sublist *)ptr->next)
  {
    char *saumya=ptr->scope;
    

    
    li=getable(li,ptr->name,ptr->type,saumya);
    if(li==NULL)
      break;

  }
  if(li!=NULL)
    errors++;
  
  current=0;
  current = (sublist *)0;
  
}

char *strremove(char *str, const char *sub) {
    size_t len = strlen(sub);
    if (len > 0) {
        char *p = str;
        while ((p = strstr(p, sub)) != NULL) {
            memmove(p, p + len, strlen(p + len) + 1);
        }
    }
    return str;
}
install ( char *sym_name,char *type )
{  symrec *s;
   s = getsym (sym_name);
   if (s == 0){
        s = putsym (sym_name,type,current);
        
   }
   else {
     
   	errors++;

   }
}
installattributes(char *sym_name,char *type){
  
 
  if(get(sym_name,current)==0)
  {
    errors++;
    
  }
  else 
  {
    current=put(sym_name,type,current,str);
  }
  
}

void checkReturnValid(char *name)
{
  if(checkReturn(name,current)==0)
  {
    errors++;
  }
  else
  {
    current=returnT(name,current);
  }
}
void checkEmpty()
{
  
  if(li!=0)
    errors++;
}



  int yyerror(const char *msg);
  int yylex();




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 118 "parse.y"
{ 
  char *id;
  int a;
  char *string;
}
/* Line 193 of yacc.c.  */
#line 303 "parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 316 "parse.tab.c"

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    16,    22,    31,
      32,    47,    53,    57,    61,    65,    70,    75,    81,    89,
      91,   100,   102,   104,   105,   107,   109,   113,   116,   119,
     121,   125,   129,   131,   133,   135,   137,   140,   143,   145,
     149,   150,   154,   156,   158,   160,   162,   164,   166,   168,
     169,   171,   175,   177,   181,   182,   185,   188,   191,   193,
     195,   197,   199,   201,   203,   205,   207,   209,   211,   213,
     215,   217,   219,   221,   223,   225,   227,   229,   231,   233,
     235,   236,   239,   241
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    48,    46,    -1,    47,    46,    -1,    -1,
      48,    46,    -1,    47,    46,    -1,    32,     4,    19,    59,
      20,    -1,    56,     4,    17,    58,    18,    19,    60,    20,
      -1,    -1,    37,    17,     4,    34,    52,    31,    53,    31,
      49,    18,    19,    50,    60,    20,    -1,    33,    17,     5,
      18,    31,    -1,    38,    52,    31,    -1,    19,    64,    20,
      -1,    57,     4,    31,    -1,    65,    34,    52,    31,    -1,
       4,    34,    52,    31,    -1,     4,    17,    55,    18,    31,
      -1,     4,    34,     4,    17,    55,    18,    31,    -1,    51,
      -1,    26,    17,    53,    18,    27,    19,    60,    20,    -1,
       5,    -1,     3,    -1,    -1,    29,    -1,    30,    -1,    52,
      62,    52,    -1,    22,    52,    -1,    12,    52,    -1,    65,
      -1,    17,    52,    18,    -1,    54,    63,    54,    -1,     3,
      -1,     5,    -1,    29,    -1,    30,    -1,    22,    52,    -1,
      12,    52,    -1,    65,    -1,    17,    52,    18,    -1,    -1,
      52,    36,    55,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,     6,    -1,     7,    -1,     8,    -1,    -1,    61,
      -1,    61,    36,    58,    -1,    61,    -1,    61,    36,    59,
      -1,    -1,    51,    60,    -1,    49,    60,    -1,    57,     4,
      -1,    21,    -1,    22,    -1,    23,    -1,    25,    -1,    24,
      -1,    40,    -1,    41,    -1,    10,    -1,    15,    -1,    16,
      -1,    13,    -1,    14,    -1,    11,    -1,    24,    -1,    40,
      -1,    41,    -1,    10,    -1,    15,    -1,    16,    -1,    13,
      -1,    14,    -1,    11,    -1,    -1,    49,    64,    -1,     4,
      -1,     4,    35,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   148,   149,   150,   151,   152,   153,   160,
     160,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     190,   192,   199,   203,   204,   210,   216,   224,   225,   226,
     227,   229,   234,   235,   236,   237,   238,   239,   240,   241,
     243,   244,   246,   248,   250,   252,   254,   255,   256,   259,
     260,   261,   263,   264,   266,   267,   268,   270,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     286,   287,   321,   322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "STR", "INT", "BOOL",
  "STRING", "VOID", "EQUALS", "NOT_EQUALS", "NOT", "LESS_THAN",
  "LESS_THAN_EQUALS", "GREATER_THAN", "GREATER_THAN_EQUALS",
  "OPENING_PARENTHESIS", "CLOSING_PARENTHESIS", "OPENING_CURLY_BRACES",
  "CLOSING_CURLY_BRACES", "PLUS", "MINUS", "MULTIPLY", "MOD", "DIVIDE",
  "IF", "THEN", "ELSE", "TRUE", "FALSE", "SEMICOL", "STRUCT", "PRINTF",
  "ASSIGN", "FULLSTOP", "COMMA", "FOR", "RETURN", "EQU", "AND", "OR",
  "UMINUS", "\"lexp\"", "$accept", "prog", "progm", "struct", "proc",
  "stmt", "@1", "if_stmt", "expr", "boolop", "exprtt", "exprs",
  "return_type", "type", "zeroOrMoreDeclarations", "oneOrMoreDeclarations",
  "zeroOrMoreStatements", "declaration", "op", "bools", "stmt_seq", "lexp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    47,    48,    50,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    60,    60,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     5,     8,     0,
      14,     5,     3,     3,     3,     4,     4,     5,     7,     1,
       8,     1,     1,     0,     1,     1,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     1,     2,     2,     1,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     0,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    42,    43,    44,    45,     0,     0,     4,     4,     0,
       0,     1,     3,     4,     4,     2,     0,     0,     6,     5,
      49,    46,    47,    48,     0,     0,    52,     0,    50,    57,
       7,     0,     0,    49,    53,    54,    51,     0,    80,     0,
       0,     0,    23,    54,    19,     0,     0,     0,    23,    23,
       0,    80,    19,     0,     0,     0,     0,    22,    82,    21,
      23,    23,    23,    24,    25,     0,    29,    56,    55,     0,
       8,    23,     0,     0,    82,     0,    83,    81,    13,    32,
      33,    23,    23,    23,    34,    35,     0,     0,    38,     0,
       0,    28,     0,    27,    65,    70,    68,    69,    66,    67,
      58,    59,    60,    62,    61,    12,    63,    64,    23,    14,
       0,    23,     0,    23,    16,    37,     0,    36,     0,    74,
      79,    77,    78,    75,    76,    71,    72,    73,     0,     0,
      23,    30,    26,    15,    41,    17,     0,    39,     0,    31,
      11,     0,     0,    54,     0,    18,     0,     0,    20,     0,
       0,     0,     9,    54,     0,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    12,    13,    14,    43,   153,    44,    72,    86,
      87,    73,     9,    45,    27,    25,    46,    26,   108,   128,
      53,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
      30,   -57,   -57,   -57,   -57,     3,    12,    30,    30,    29,
      21,   -57,   -57,    30,    30,   -57,    26,    44,   -57,   -57,
      44,   -57,   -57,   -57,    54,    24,    27,    41,    28,   -57,
     -57,    44,    48,    44,   -57,    23,   -57,   -12,    23,    56,
      57,    58,   312,    23,    23,    80,    67,    63,   296,   316,
      84,    23,   -57,    69,   327,    85,    87,   -57,    66,   -57,
     312,   312,   312,   -57,   -57,    55,   -57,   -57,   -57,    61,
     -57,   312,   111,    88,   -15,   143,   -57,   -57,   -57,   -57,
     -57,   312,   312,   312,   -57,   -57,    93,    89,   -57,    98,
      64,   -57,   175,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   312,   -57,
     196,   296,    76,   296,   -57,    60,   228,    60,    90,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   327,    92,
     312,   -57,   271,   -57,   -57,   -57,   101,   -57,   109,   -57,
     -57,   249,   100,    23,   327,   -57,   117,   107,   -57,    23,
     121,   122,   -57,    23,   120,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,    40,   142,   144,   -37,   -57,   -34,   -36,    -1,
      17,   -56,   -57,     1,   113,   118,   -33,     8,   -57,   -57,
      97,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -41
static const yytype_int16 yytable[] =
{
      47,    51,   113,    47,    52,    48,    65,    10,    47,    47,
      67,    68,    11,    75,    51,    76,    47,    52,    24,    88,
      50,    24,    49,    50,    91,    92,    93,    37,    28,    21,
      22,    23,    24,    16,    24,   110,     1,     2,     3,     4,
      17,    28,    38,    20,    30,   115,   116,   117,    15,    39,
      21,    22,    23,    18,    19,   134,    40,   136,    29,    32,
      41,    42,     5,    31,    33,    94,    95,    35,    96,    97,
      98,    99,   132,    54,    55,    56,   100,   101,   102,   103,
     104,   100,   101,   102,    69,   104,   105,    70,    58,    78,
      89,    90,   109,    88,   141,   106,   107,    71,   130,   119,
     120,    50,   121,   122,   123,   124,   112,   135,    47,    88,
     146,   118,   150,   125,    47,    52,   129,   138,    47,   142,
     154,    94,    95,   140,    96,    97,    98,    99,   143,   126,
     127,   145,   100,   101,   102,   103,   104,   148,   149,   151,
     155,   152,     7,   147,     8,   139,    36,   111,    77,    34,
       0,   106,   107,    94,    95,     0,    96,    97,    98,    99,
       0,     0,     0,     0,   100,   101,   102,   103,   104,     0,
       0,     0,     0,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,    94,    95,     0,    96,    97,
      98,    99,     0,   131,     0,     0,   100,   101,   102,   103,
     104,     0,     0,     0,     0,     0,    94,    95,     0,    96,
      97,    98,    99,     0,     0,   106,   107,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   107,    94,    95,
       0,    96,    97,    98,    99,     0,   137,     0,     0,   100,
     101,   102,   103,   104,     0,     0,     0,     0,     0,    94,
      95,     0,    96,    97,    98,    99,     0,     0,   106,   107,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
     144,    94,    95,     0,    96,    97,    98,    99,     0,   106,
     107,     0,   100,   101,   102,   103,   104,     0,     0,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,     0,
       0,   106,   107,    61,   -40,    57,    58,    59,    62,    57,
      74,    59,     0,     0,    60,    63,    64,     0,    60,    61,
      79,    58,    80,    61,    62,     0,     0,     0,    62,    81,
       0,    63,    64,     0,    82,    63,    64,     0,     0,    83,
       0,     0,     0,     0,     0,     0,    84,    85
};

static const yytype_int16 yycheck[] =
{
      35,    38,    17,    38,    38,    17,    42,     4,    43,    44,
      43,    44,     0,    49,    51,    50,    51,    51,    17,    54,
      35,    20,    34,    35,    60,    61,    62,     4,    20,     6,
       7,     8,    31,     4,    33,    71,     6,     7,     8,     9,
      19,    33,    19,    17,    20,    81,    82,    83,     8,    26,
       6,     7,     8,    13,    14,   111,    33,   113,     4,    18,
      37,    38,    32,    36,    36,    10,    11,    19,    13,    14,
      15,    16,   108,    17,    17,    17,    21,    22,    23,    24,
      25,    21,    22,    23,     4,    25,    31,    20,     4,    20,
       5,     4,    31,   128,   130,    40,    41,    34,    34,    10,
      11,    35,    13,    14,    15,    16,    18,    31,   143,   144,
     143,    18,   149,    24,   149,   149,    18,    27,   153,    18,
     153,    10,    11,    31,    13,    14,    15,    16,    19,    40,
      41,    31,    21,    22,    23,    24,    25,    20,    31,    18,
      20,    19,     0,   144,     0,   128,    33,    36,    51,    31,
      -1,    40,    41,    10,    11,    -1,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    10,    11,    -1,    13,    14,
      15,    16,    -1,    18,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    40,    41,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    10,    11,
      -1,    13,    14,    15,    16,    -1,    18,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    40,    41,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    10,    11,    -1,    13,    14,    15,    16,    -1,    40,
      41,    -1,    21,    22,    23,    24,    25,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    40,    41,    17,    18,     3,     4,     5,    22,     3,
       4,     5,    -1,    -1,    12,    29,    30,    -1,    12,    17,
       3,     4,     5,    17,    22,    -1,    -1,    -1,    22,    12,
      -1,    29,    30,    -1,    17,    29,    30,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    32,    45,    47,    48,    56,
       4,     0,    46,    47,    48,    46,     4,    19,    46,    46,
      17,     6,     7,     8,    57,    59,    61,    58,    61,     4,
      20,    36,    18,    36,    59,    19,    58,     4,    19,    26,
      33,    37,    38,    49,    51,    57,    60,    65,    17,    34,
      35,    49,    51,    64,    17,    17,    17,     3,     4,     5,
      12,    17,    22,    29,    30,    52,    65,    60,    60,     4,
      20,    34,    52,    55,     4,    52,    65,    64,    20,     3,
       5,    12,    17,    22,    29,    30,    53,    54,    65,     5,
       4,    52,    52,    52,    10,    11,    13,    14,    15,    16,
      21,    22,    23,    24,    25,    31,    40,    41,    62,    31,
      52,    36,    18,    17,    31,    52,    52,    52,    18,    10,
      11,    13,    14,    15,    16,    24,    40,    41,    63,    18,
      34,    18,    52,    31,    55,    31,    55,    18,    27,    54,
      31,    52,    18,    19,    31,    31,    60,    53,    20,    31,
      49,    18,    19,    50,    60,    20
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
        case 7:
#line 152 "parse.y"
    {install((yyvsp[(2) - (5)].string),"null");  procedure = (yyvsp[(2) - (5)].string);;}
    break;

  case 8:
#line 153 "parse.y"
    {install((yyvsp[(2) - (8)].string),t);procedure = (yyvsp[(2) - (8)].string);checkinit();;}
    break;

  case 9:
#line 160 "parse.y"
    {
  temp = (char *)malloc(strlen(str)+4);
  rem=(char *)malloc(20);
  char *temp2 =(char *)malloc(20);
  strcat(temp,str);
  strcat(temp,"for");
  sprintf(temp2, "%d", i);
  strcat(rem,"for");
  strcat(rem, temp2);
  strcat(temp,temp2);
  i++;
  str=temp;
  

;}
    break;

  case 10:
#line 174 "parse.y"
    {
  temp=strremove(temp,rem);
  str=temp;
  ;}
    break;

  case 12:
#line 179 "parse.y"
    {printf("Return");memset(ar, 0, 1000);point=0;}
    break;

  case 14:
#line 181 "parse.y"
    {installattributes((yyvsp[(2) - (3)].string),t);;}
    break;

  case 15:
#line 182 "parse.y"
    {memset(ar, 0, 1000);point=0;;}
    break;

  case 16:
#line 183 "parse.y"
    {init((yyvsp[(1) - (4)].string),v);memset(ar, 0, 1000);point=0;;}
    break;

  case 21:
#line 192 "parse.y"
    {v="string";

  
    ar[point]=v;
    point++;
  
;}
    break;

  case 22:
#line 199 "parse.y"
    {v="int";
  
  
  ;}
    break;

  case 24:
#line 204 "parse.y"
    {v="bool";
  
  
    ar[point]="bool";
    point++;
  ;}
    break;

  case 25:
#line 210 "parse.y"
    {v="bool";


    ar[point]=v;
    point++;
  ;}
    break;

  case 26:
#line 216 "parse.y"
    {

printf("%s",ar[1]);
printf("%s",ar[0]);



;}
    break;

  case 32:
#line 234 "parse.y"
    {v="int";;}
    break;

  case 33:
#line 235 "parse.y"
    {v="string";;}
    break;

  case 34:
#line 236 "parse.y"
    {v="bool";;}
    break;

  case 35:
#line 237 "parse.y"
    {v="bool";;}
    break;

  case 42:
#line 246 "parse.y"
    {t = (yyvsp[(1) - (1)].string);
;}
    break;

  case 43:
#line 248 "parse.y"
    {t = (yyvsp[(1) - (1)].string);
;}
    break;

  case 44:
#line 250 "parse.y"
    {t = (yyvsp[(1) - (1)].string);
;}
    break;

  case 45:
#line 252 "parse.y"
    {t = (yyvsp[(1) - (1)].string);
;}
    break;

  case 46:
#line 254 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 47:
#line 255 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 48:
#line 257 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 57:
#line 270 "parse.y"
    { installattributes((yyvsp[(2) - (2)].string),t);   ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1859 "parse.tab.c"
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


#line 326 "parse.y"


int main (int argc, char *argv[]){

    
 
    // parsing
    int flag;
    yyin = fopen(argv[1], "r");
    flag = yyparse();
    fclose(yyin);
 
    

    

    if(errors>0)
{
    yyerror("Invalid");
    }
  if(flag == 0 )
  {
    printf("VALID\n");
  }

    return 0;
}
int yyerror(const char *msg){
	fprintf(stderr, "%s\n", "ERROR");
  exit(1);
}









