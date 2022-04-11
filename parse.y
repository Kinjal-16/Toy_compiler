%{
	#include <stdio.h>
  #include <stdlib.h>
  #include ""
  int yyerror(const char *msg);
  int yylex();
%}

%union { 
  char *id; 
}

%token NUM VALID 
%token ID STR FOR RETURN 
%token TYPE EQUALS NOT_EQUALS STRUCT VOID PRINTF NOT ASSIGN LESS_THAN LESS_THAN_EQUALS
%token DIVIDE GREATER_THAN GREATER_THAN_EQUALS OPENING_PARENTHESIS CLOSING_PARENTHESIS 
%token OPENING_CURLY_BRACES CLOSING_CURLY_BRACES FULLSTOP COMMA PLUS MINUS MULTIPLY 
%token EQU MOD AND OR IF THEN ELSE TRUE FALSE SEMICOL
%right "lexp"
%right EQUALS 
%left  ASSIGN FULLSTOP
%nonassoc OR AND MOD NOT_EQUALS GREATER_THAN GREATER_THAN_EQUALS LESS_THAN_EQUALS LESS_THAN
%left MULTIPLY DIVIDE 
%left PLUS MINUS
%left UMINUS NOT





 
%%

prog: proc progm
  | struct progm

progm: 
  | proc progm
  | struct progm
;

proc: return_type ID OPENING_PARENTHESIS zeroOrMoreDeclarations CLOSING_PARENTHESIS OPENING_CURLY_BRACES zeroOrMoreDeclarations CLOSING_CURLY_BRACES
;

struct: STRUCT ID OPENING_CURLY_BRACES oneOrMoreDeclarations CLOSING_CURLY_BRACES     
;

zeroOrMoreDeclarations: 
  | declaration
  | declaration COMMA zeroOrMoreDeclarations
;

oneOrMoreDeclarations: declaration 
  | declaration COMMA oneOrMoreDeclarations
;




declaration: type ID 
;

stmt: FOR OPENING_PARENTHESIS ID ASSIGN expr SEMICOL expr SEMICOL stmt CLOSING_PARENTHESIS  OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
  | PRINTF OPENING_PARENTHESIS STR CLOSING_PARENTHESIS SEMICOL
  | RETURN expr SEMICOL
  | OPENING_CURLY_BRACES stmt_seq CLOSING_CURLY_BRACES
  | TYPE ID SEMICOL
  | lexp EQUALS expr SEMICOL
  | ID ASSIGN expr SEMICOL
  | ID  OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | ID ASSIGN ID OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
;

/*
if_stmt: IF OPENING_PARENTHESIS expr CLOSING_PARENTHESIS THEN OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
  | IF OPENING_PARENTHESIS expr CLOSING_PARENTHESIS THEN OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES ELSE OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
;*/
exprs: 
    | expr COMMA exprs
;



expr : NUM
| STR
|TRUE
|FALSE
|expr op expr
|MINUS expr %prec UMINUS
|NOT expr
|lexp
|OPENING_PARENTHESIS expr CLOSING_PARENTHESIS
;

op: PLUS|MINUS|MULTIPLY|DIVIDE|MOD|AND|OR|EQUALS|GREATER_THAN|GREATER_THAN_EQUALS|LESS_THAN|LESS_THAN_EQUALS|NOT_EQUALS
stmt_seq:
  | stmt stmt_seq
;

type: TYPE
  | ID 
;

return_type: TYPE 
  | VOID
;
/*
expr: addsub
  | '-' expr
  | '!' expr

addsub: factor
  | expr '+' expr
  | expr '-' expr
;

factor: equality
  | expr '*' expr
  | expr '/' expr
;

equality: term 
  | expr OR expr
  | expr MOD expr
  | expr AND expr
;

term: NUMBER
  | STRINGLITERAL
  | TRUE
  | FALSE
  | lexp
  | '(' expr ')'
;
*/
lexp: ID
  | ID FULLSTOP lexp
;


%%

/* user code */

int main(int argc, char *argv[])
{

  if (argc !=2) {
    return 1; 
  }

     FILE *fp;
    fp = fopen("input.txt","r");
    yyin = fp;

  int parse = yyparse();
  fclose(yyin);
  display_table();

  if(parse == 0)
  {
    printf("Parser: VALID\n");
  } 

  return 0;
}

int yyerror(const char *msg){
	fprintf(stderr, "%s\n", msg);
  exit(1);
}






