/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 119 "parse.y"
{ 
  char *id;
  int a;
  char *string;
}
/* Line 1529 of yacc.c.  */
#line 139 "parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

