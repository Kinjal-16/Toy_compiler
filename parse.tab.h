
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUM = 258,
     ID = 259,
     STR = 260,
     EQUALS = 261,
     NOT_EQUALS = 262,
     NOT = 263,
     LESS_THAN = 264,
     LESS_THAN_EQUALS = 265,
     GREATER_THAN = 266,
     GREATER_THAN_EQUALS = 267,
     OPENING_PARENTHESIS = 268,
     CLOSING_PARENTHESIS = 269,
     OPENING_CURLY_BRACES = 270,
     CLOSING_CURLY_BRACES = 271,
     PLUS = 272,
     MINUS = 273,
     MULTIPLY = 274,
     MOD = 275,
     DIVIDE = 276,
     IF = 277,
     THEN = 278,
     ELSE = 279,
     TRUE = 280,
     FALSE = 281,
     SEMICOL = 282,
     TYPE = 283,
     STRUCT = 284,
     VOID = 285,
     PRINTF = 286,
     ASSIGN = 287,
     FULLSTOP = 288,
     COMMA = 289,
     FOR = 290,
     RETURN = 291,
     EQU = 292,
     AND = 293,
     OR = 294,
     UMINUS = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "parse.y"
 
  char *id;
  int a;
  char *string;



/* Line 1676 of yacc.c  */
#line 100 "parse.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


