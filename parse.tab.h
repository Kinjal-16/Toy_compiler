
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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 75 "parse.y"
 
  char *id;
  int a;
  char *string;



/* Line 1676 of yacc.c  */
#line 102 "parse.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


