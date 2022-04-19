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
int m=0;
sublist *hey;
int flag2=1;
char * returnStore;
int ret=0;
char *jk;
int kin=0;
int pin=0;
int sig=0;
init(char *name, char *type){
 
  li=putable(name,type,li,str);
  
}
checkinit(){
  sublist *ptr;
   
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
#line 126 "parse.y"
{ 
  char *id;
  int a;
  char *string;
}
/* Line 193 of yacc.c.  */
#line 311 "parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 324 "parse.tab.c"

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
#define YYLAST   302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    13,    16,    17,    24,
      33,    34,    49,    55,    59,    63,    67,    72,    77,    83,
      91,    93,    94,   101,   102,   112,   114,   116,   117,   119,
     121,   125,   128,   131,   133,   137,   141,   143,   145,   146,
     148,   150,   153,   156,   158,   162,   164,   166,   168,   170,
     171,   175,   177,   179,   181,   183,   185,   187,   189,   191,
     192,   194,   198,   200,   204,   205,   208,   211,   214,   216,
     218,   220,   222,   224,   226,   228,   230,   232,   234,   236,
     238,   240,   242,   244,   246,   248,   250,   252,   254,   256,
     258,   259,   262,   264,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    49,    46,    -1,    47,    46,    -1,    -1,
      49,    46,    -1,    47,    46,    -1,    -1,    32,     4,    19,
      48,    63,    20,    -1,    60,     4,    17,    62,    18,    19,
      64,    20,    -1,    -1,    37,    17,     4,    34,    55,    31,
      56,    31,    50,    18,    19,    51,    64,    20,    -1,    33,
      17,     5,    18,    31,    -1,    38,    55,    31,    -1,    19,
      68,    20,    -1,    61,     4,    31,    -1,    70,    34,    58,
      31,    -1,     4,    34,    55,    31,    -1,     4,    17,    59,
      18,    31,    -1,     4,    34,     4,    17,    59,    18,    31,
      -1,    53,    -1,    -1,    53,    28,    19,    52,    64,    20,
      -1,    -1,    26,    17,    55,    18,    54,    27,    19,    64,
      20,    -1,     5,    -1,     3,    -1,    -1,    29,    -1,    30,
      -1,    55,    66,    55,    -1,    22,    55,    -1,    12,    55,
      -1,    70,    -1,    17,    55,    18,    -1,    57,    67,    57,
      -1,     5,    -1,     3,    -1,    -1,    29,    -1,    30,    -1,
      22,    57,    -1,    12,    57,    -1,    69,    -1,    17,    57,
      18,    -1,     5,    -1,     3,    -1,    29,    -1,    30,    -1,
      -1,    55,    36,    59,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,     6,    -1,     7,    -1,     8,    -1,     4,
      -1,    -1,    65,    -1,    65,    36,    62,    -1,    65,    -1,
      65,    36,    63,    -1,    -1,    53,    64,    -1,    50,    64,
      -1,    61,     4,    -1,    21,    -1,    22,    -1,    23,    -1,
      25,    -1,    24,    -1,    40,    -1,    41,    -1,    10,    -1,
      15,    -1,    16,    -1,    13,    -1,    14,    -1,    11,    -1,
      24,    -1,    40,    -1,    41,    -1,    10,    -1,    15,    -1,
      16,    -1,    13,    -1,    14,    -1,    11,    -1,    -1,    50,
      68,    -1,     4,    -1,     4,    -1,     4,    35,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   155,   155,   156,   157,   158,   159,   160,   160,   178,
     201,   201,   219,   220,   221,   222,   223,   227,   228,   229,
     230,   231,   231,   256,   256,   278,   285,   290,   291,   297,
     303,   304,   305,   306,   307,   312,   329,   336,   341,   342,
     348,   354,   355,   356,   357,   360,   361,   362,   363,   366,
     367,   369,   371,   373,   375,   378,   379,   380,   382,   385,
     386,   387,   389,   390,   392,   393,   394,   398,   410,   410,
     410,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     414,   415,   449,   462,   463
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
  "UMINUS", "\"lexp\"", "$accept", "prog", "progm", "struct", "@1", "proc",
  "stmt", "@2", "@3", "if_stmt", "@4", "expr", "boolop", "exprtt",
  "expTem", "exprs", "return_type", "type", "zeroOrMoreDeclarations",
  "oneOrMoreDeclarations", "zeroOrMoreStatements", "declaration", "op",
  "bools", "stmt_seq", "blexp", "lexp", 0
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
       0,    44,    45,    45,    46,    46,    46,    48,    47,    49,
      51,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    52,    50,    54,    53,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    64,    64,    64,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     2,     0,     6,     8,
       0,    14,     5,     3,     3,     3,     4,     4,     5,     7,
       1,     0,     6,     0,     9,     1,     1,     0,     1,     1,
       3,     2,     2,     1,     3,     3,     1,     1,     0,     1,
       1,     2,     2,     1,     3,     1,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     0,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    51,    52,    53,    54,     0,     0,     4,     4,     0,
       0,     1,     3,     4,     4,     2,     0,     7,     6,     5,
      59,     0,    58,    55,    56,    57,     0,     0,    60,     0,
      62,    67,     0,    59,     8,     0,    64,    61,    63,    58,
      90,     0,     0,     0,    27,    64,    20,     0,     0,     0,
      27,    27,     0,    90,    20,     0,    27,     0,     0,    26,
      93,    25,    27,    27,    27,    28,    29,     0,    33,    66,
       0,    65,     0,     9,     0,     0,     0,    93,     0,    94,
      91,    14,     0,     0,     0,    32,     0,    31,    75,    80,
      78,    79,    76,    77,    68,    69,    70,    72,    71,    13,
      73,    74,    27,    21,    15,    46,    45,    47,    48,     0,
      27,     0,    27,    17,    23,     0,    27,    34,    30,    64,
      16,    50,    18,     0,     0,    12,     0,     0,     0,     0,
      38,    22,    19,    64,    37,    92,    36,    38,    38,    38,
      39,    40,     0,     0,    43,     0,    42,     0,    41,     0,
      84,    89,    87,    88,    85,    86,    81,    82,    83,    38,
      24,    44,     0,    35,     0,    10,    64,     0,    11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    12,    13,    21,    14,    45,   166,   119,    46,
     124,    75,   142,   143,   109,    76,     9,    47,    27,    29,
      48,    28,   102,   159,    55,   144,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
      14,  -132,  -132,  -132,  -132,    50,    57,    14,    14,    67,
      53,  -132,  -132,    14,    14,  -132,    59,  -132,  -132,  -132,
     132,   132,  -132,  -132,  -132,  -132,    81,    63,    60,    83,
      68,  -132,    86,   132,  -132,   132,    30,  -132,  -132,     8,
      30,    69,    89,    93,   249,    30,     7,   107,    95,    82,
     238,   269,   115,    30,    99,   108,   249,   124,   133,  -132,
     109,  -132,   249,   249,   249,  -132,  -132,    77,  -132,  -132,
     123,  -132,   112,  -132,    36,    37,   127,    47,   110,  -132,
    -132,  -132,   142,   128,   113,  -132,   163,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,   249,  -132,  -132,  -132,  -132,  -132,  -132,   117,
     238,   118,   238,  -132,  -132,   130,   249,  -132,   206,    30,
    -132,  -132,  -132,   136,   135,  -132,   184,   139,   137,   150,
     272,  -132,  -132,    30,  -132,  -132,  -132,   272,   272,   272,
    -132,  -132,   140,   224,  -132,   152,  -132,   157,  -132,    30,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   272,
    -132,  -132,   162,  -132,   151,  -132,    30,   169,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,    66,   190,  -132,   191,   -37,  -132,  -132,   -35,
    -132,   -32,  -132,  -131,  -132,   -83,  -132,    74,   159,   158,
     -44,    34,  -132,  -132,   143,  -132,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      49,    69,    71,    53,    49,    54,   146,   147,   148,    49,
      49,    39,    67,    23,    24,    25,    53,    49,    54,    78,
       1,     2,     3,     4,    82,    50,    40,   121,   163,   123,
      85,    86,    87,    41,    39,    70,    23,    24,    25,   105,
      42,   106,    51,    52,    43,    44,     5,    88,    89,    40,
      90,    91,    92,    93,    10,    30,    41,    11,    94,    95,
      96,    97,    98,    42,   112,   107,   108,    43,    44,    30,
     118,    16,    17,   110,    15,   127,    20,   100,   101,    18,
      19,    32,    52,    49,   126,    31,    56,    88,    89,   145,
      90,    91,    92,    93,    26,    26,    33,    49,    94,    95,
      96,    97,    98,    34,    35,    36,    57,    26,    99,    26,
      58,    72,   162,    49,    54,    73,    74,   100,   101,    79,
      88,    89,   167,    90,    91,    92,    93,    70,    81,    83,
      49,    94,    95,    96,    97,    98,    22,    84,    23,    24,
      25,   113,   103,   104,    52,   111,   115,   116,   120,   122,
     100,   101,    88,    89,   128,    90,    91,    92,    93,   131,
     114,   125,   129,    94,    95,    96,    97,    98,   132,   133,
     165,   149,   160,    88,    89,   161,    90,    91,    92,    93,
     164,   117,   100,   101,    94,    95,    96,    97,    98,   168,
       7,     8,    37,    38,    88,    89,    80,    90,    91,    92,
      93,     0,     0,   100,   101,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,   130,    88,    89,     0,    90,
      91,    92,    93,     0,   100,   101,     0,    94,    95,    96,
      97,    98,     0,     0,   150,   151,     0,   152,   153,   154,
     155,    59,    60,    61,     0,     0,   100,   101,   156,     0,
      62,     0,    59,    60,    61,    63,   -49,     0,     0,     0,
      64,    62,     0,     0,   157,   158,    63,    65,    66,     0,
       0,    64,    59,    77,    61,   134,   135,   136,    65,    66,
       0,    62,     0,     0,   137,     0,    63,     0,     0,   138,
       0,    64,     0,     0,   139,     0,     0,     0,    65,    66,
       0,   140,   141
};

static const yytype_int16 yycheck[] =
{
      36,    45,    46,    40,    40,    40,   137,   138,   139,    45,
      46,     4,    44,     6,     7,     8,    53,    53,    53,    51,
       6,     7,     8,     9,    56,    17,    19,   110,   159,   112,
      62,    63,    64,    26,     4,    28,     6,     7,     8,     3,
      33,     5,    34,    35,    37,    38,    32,    10,    11,    19,
      13,    14,    15,    16,     4,    21,    26,     0,    21,    22,
      23,    24,    25,    33,    17,    29,    30,    37,    38,    35,
     102,     4,    19,    36,     8,   119,    17,    40,    41,    13,
      14,    18,    35,   119,   116,     4,    17,    10,    11,   133,
      13,    14,    15,    16,    20,    21,    36,   133,    21,    22,
      23,    24,    25,    20,    36,    19,    17,    33,    31,    35,
      17,     4,   149,   149,   149,    20,    34,    40,    41,     4,
      10,    11,   166,    13,    14,    15,    16,    28,    20,     5,
     166,    21,    22,    23,    24,    25,     4,     4,     6,     7,
       8,    31,    19,    31,    35,    18,    18,    34,    31,    31,
      40,    41,    10,    11,    18,    13,    14,    15,    16,    20,
      18,    31,    27,    21,    22,    23,    24,    25,    31,    19,
      19,    31,    20,    10,    11,    18,    13,    14,    15,    16,
      18,    18,    40,    41,    21,    22,    23,    24,    25,    20,
       0,     0,    33,    35,    10,    11,    53,    13,    14,    15,
      16,    -1,    -1,    40,    41,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    10,    11,    -1,    13,
      14,    15,    16,    -1,    40,    41,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    10,    11,    -1,    13,    14,    15,
      16,     3,     4,     5,    -1,    -1,    40,    41,    24,    -1,
      12,    -1,     3,     4,     5,    17,    18,    -1,    -1,    -1,
      22,    12,    -1,    -1,    40,    41,    17,    29,    30,    -1,
      -1,    22,     3,     4,     5,     3,     4,     5,    29,    30,
      -1,    12,    -1,    -1,    12,    -1,    17,    -1,    -1,    17,
      -1,    22,    -1,    -1,    22,    -1,    -1,    -1,    29,    30,
      -1,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    32,    45,    47,    49,    60,
       4,     0,    46,    47,    49,    46,     4,    19,    46,    46,
      17,    48,     4,     6,     7,     8,    61,    62,    65,    63,
      65,     4,    18,    36,    20,    36,    19,    62,    63,     4,
      19,    26,    33,    37,    38,    50,    53,    61,    64,    70,
      17,    34,    35,    50,    53,    68,    17,    17,    17,     3,
       4,     5,    12,    17,    22,    29,    30,    55,    70,    64,
      28,    64,     4,    20,    34,    55,    59,     4,    55,     4,
      68,    20,    55,     5,     4,    55,    55,    55,    10,    11,
      13,    14,    15,    16,    21,    22,    23,    24,    25,    31,
      40,    41,    66,    19,    31,     3,     5,    29,    30,    58,
      36,    18,    17,    31,    18,    18,    34,    18,    55,    52,
      31,    59,    31,    59,    54,    31,    55,    64,    18,    27,
      31,    20,    31,    19,     3,     4,     5,    12,    17,    22,
      29,    30,    56,    57,    69,    64,    57,    57,    57,    31,
      10,    11,    13,    14,    15,    16,    24,    40,    41,    67,
      20,    18,    50,    57,    18,    19,    51,    64,    20
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
#line 160 "parse.y"
    {
  temp = (char *)malloc(strlen(str)+14);
  rem=(char *)malloc(20);
  char *temp2 =(char *)malloc(20);
  strcat(temp,str);
  strcat(temp,"struct");
  sprintf(temp2, "%d", m);
  strcat(rem,"struct");
  strcat(rem, temp2);
  strcat(temp,temp2);
  m++;
  str=temp;

;}
    break;

  case 8:
#line 173 "parse.y"
    {
  temp=strremove(temp,rem);
  str=temp;

  install((yyvsp[(2) - (6)].string),"null");  procedure = (yyvsp[(2) - (6)].string);checkinit();;}
    break;

  case 9:
#line 178 "parse.y"
    {
  if(checkReturn(jk,current)==1 && strcmp(jk,"void")!=0)
  {
    errors++;
  
  }
  else 
  {

    if(strcmp(jk,"void")==0 && ret>=1)
      errors++;
  }
  ret=0;
  
  
  
  ;procedure = (yyvsp[(2) - (8)].string);checkinit();;}
    break;

  case 10:
#line 201 "parse.y"
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

  case 11:
#line 215 "parse.y"
    {
  temp=strremove(temp,rem);
  str=temp;
  ;}
    break;

  case 13:
#line 220 "parse.y"
    {returnStore=v;memset(ar, 0, 1000);point=0;current=returnT(v,current);ret++;;}
    break;

  case 15:
#line 222 "parse.y"
    {installattributes((yyvsp[(2) - (3)].string),t);;}
    break;

  case 16:
#line 223 "parse.y"
    {
    if(hey!=NULL)
      if(strcmp(v,hey->type)!=0)
        errors++;memset(ar, 0, 1000);point=0;;}
    break;

  case 17:
#line 227 "parse.y"
    {init((yyvsp[(1) - (4)].string),v);memset(ar, 0, 1000);point=0;;}
    break;

  case 21:
#line 231 "parse.y"
    {
  temp = (char *)malloc(strlen(str)+14);
  rem=(char *)malloc(20);
  char *temp2 =(char *)malloc(20);
  strcat(temp,str);
  strcat(temp,"else");
  sprintf(temp2, "%d", sig);
  strcat(rem,"else");
  strcat(rem, temp2);
  strcat(temp,temp2);
  sig++;
  str=temp;
  
  
  ;}
    break;

  case 22:
#line 245 "parse.y"
    {
  
  temp=strremove(temp,rem);
  str=temp;

  
  ;}
    break;

  case 23:
#line 256 "parse.y"
    {

  
  temp = (char *)malloc(strlen(str)+14);
  rem=(char *)malloc(20);
  char *temp2 =(char *)malloc(20);
  strcat(temp,str);
  strcat(temp,"if");
  sprintf(temp2, "%d", kin);
  strcat(rem,"if");
  strcat(rem, temp2);
  strcat(temp,temp2);
  kin++;
  str=temp;
  

;}
    break;

  case 24:
#line 272 "parse.y"
    {
  temp=strremove(temp,rem);
  str=temp;
  
  ;}
    break;

  case 25:
#line 278 "parse.y"
    {v="string";

  
    ar[point]=v;
    point++;
  
;}
    break;

  case 26:
#line 285 "parse.y"
    {v="int";
  ar[point]=v;
    point++;
  
  ;}
    break;

  case 28:
#line 291 "parse.y"
    {v="bool";
  
  
    ar[point]="bool";
    point++;
  ;}
    break;

  case 29:
#line 297 "parse.y"
    {v="bool";


    ar[point]=v;
    point++;
  ;}
    break;

  case 31:
#line 304 "parse.y"
    {memset(ar, 0, 1000);point=0;;}
    break;

  case 32:
#line 305 "parse.y"
    {memset(ar, 0, 1000);point=0;;}
    break;

  case 34:
#line 307 "parse.y"
    {memset(ar, 0, 1000);point=0;;}
    break;

  case 35:
#line 312 "parse.y"
    {
  
    char *z=ar[0];
  for(int i=0;i<point;i++)
  {
    if(strcmp(z,ar[i])!=0)
    {
      errors++;
      break;
    }
  }
  memset(ar, 0, 1000);point=0;
;}
    break;

  case 36:
#line 329 "parse.y"
    {v="string";

  
    ar[point]=v;
    point++;
  
;}
    break;

  case 37:
#line 336 "parse.y"
    {v="int";
  ar[point]=v;
    point++;
  
  ;}
    break;

  case 39:
#line 342 "parse.y"
    {v="bool";
  
  
    ar[point]="bool";
    point++;
  ;}
    break;

  case 40:
#line 348 "parse.y"
    {v="bool";


    ar[point]=v;
    point++;
  ;}
    break;

  case 41:
#line 354 "parse.y"
    {memset(ar, 0, 1000);point=0;;}
    break;

  case 45:
#line 360 "parse.y"
    {v="string";;}
    break;

  case 46:
#line 361 "parse.y"
    {v="int"; ;}
    break;

  case 47:
#line 362 "parse.y"
    {v="bool";;}
    break;

  case 48:
#line 363 "parse.y"
    {v="bool";;}
    break;

  case 51:
#line 369 "parse.y"
    {jk = (yyvsp[(1) - (1)].string);
;}
    break;

  case 52:
#line 371 "parse.y"
    {jk = (yyvsp[(1) - (1)].string);
;}
    break;

  case 53:
#line 373 "parse.y"
    {jk = (yyvsp[(1) - (1)].string);
;}
    break;

  case 54:
#line 375 "parse.y"
    {jk = "void";
 
;}
    break;

  case 55:
#line 378 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 56:
#line 379 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 57:
#line 381 "parse.y"
    {t = (yyvsp[(1) - (1)].string);;}
    break;

  case 58:
#line 383 "parse.y"
    {t=(yyvsp[(1) - (1)].string);;}
    break;

  case 67:
#line 398 "parse.y"
    { installattributes((yyvsp[(2) - (2)].string),t);   ;}
    break;

  case 92:
#line 449 "parse.y"
    {
  if(get((yyvsp[(1) - (1)].string),current)==1)
  {
      errors++;
  }
  else 
  {
    sublist *pqr=getTemp((yyvsp[(1) - (1)].string),current);
    ar[point]=pqr->type;
    point++;
  }
;}
    break;

  case 94:
#line 464 "parse.y"
    {



  if(get((yyvsp[(1) - (3)].string),current)==1)
  {
      errors++;
  }
  else 
  {

    sublist *pqr=getTemp((yyvsp[(1) - (3)].string),current);



    
    
    
    sublist *pqrs=getlist(pqr->type);
    if(pqrs==0)
    {
      errors++;
    }
    else 
    {
    if(get((yyvsp[(3) - (3)].string),pqrs)==1)
    {
      flag=0;
    
      errors++;
      yyerror;
    }
    else 
    {
     
      sublist *aeou = getTemp((yyvsp[(3) - (3)].string),pqrs);

      
      hey=aeou;
      
      ar[point]=pqr->type;
      point++;
    }
    }
  }
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2106 "parse.tab.c"
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


#line 513 "parse.y"


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









