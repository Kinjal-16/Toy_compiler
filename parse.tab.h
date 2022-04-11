
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
     VALID = 259,
     ID = 260,
     STR = 261,
     FOR = 262,
     RETURN = 263,
     TYPE = 264,
     EQUALS = 265,
     NOT_EQUALS = 266,
     STRUCT = 267,
     VOID = 268,
     PRINTF = 269,
     NOT = 270,
     ASSIGN = 271,
     LESS_THAN = 272,
     LESS_THAN_EQUALS = 273,
     DIVIDE = 274,
     GREATER_THAN = 275,
     GREATER_THAN_EQUALS = 276,
     OPENING_PARENTHESIS = 277,
     CLOSING_PARENTHESIS = 278,
     OPENING_CURLY_BRACES = 279,
     CLOSING_CURLY_BRACES = 280,
     FULLSTOP = 281,
     COMMA = 282,
     PLUS = 283,
     MINUS = 284,
     MULTIPLY = 285,
     EQU = 286,
     MOD = 287,
     AND = 288,
     OR = 289,
     IF = 290,
     THEN = 291,
     ELSE = 292,
     TRUE = 293,
     FALSE = 294,
     SEMICOL = 295,
     UMINUS = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 9 "parse.y"
 
  char *id; 



/* Line 1676 of yacc.c  */
#line 99 "parse.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


