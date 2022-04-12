%{
	#include <stdio.h>
	#include<string.h>

  #include <stdlib.h>
extern FILE *yyin;
extern int yylex();

  int yyerror(const char *msg);
  int yylex();
%}

%union { 
  char *id;
  int a;
  char *string;
}

%token NUM
%token<string> ID STR
%token EQUALS NOT_EQUALS NOT LESS_THAN LESS_THAN_EQUALS GREATER_THAN GREATER_THAN_EQUALS
%token OPENING_PARENTHESIS CLOSING_PARENTHESIS OPENING_CURLY_BRACES CLOSING_CURLY_BRACES
%token PLUS MINUS MULTIPLY MOD DIVIDE
%token IF THEN ELSE TRUE FALSE SEMICOL TYPE STRUCT  VOID PRINTF ASSIGN FULLSTOP COMMA FOR RETURN
%token EQU  AND OR
%right "lexp"
%right EQUALS 
%left  ASSIGN FULLSTOP
%nonassoc OR AND MOD NOT_EQUALS GREATER_THAN GREATER_THAN_EQUALS LESS_THAN_EQUALS LESS_THAN
%left MULTIPLY DIVIDE 
%left PLUS MINUS
%left UMINUS NOT





 
%%

/*prog: proc progm
  | struct progm

//progm:
  | proc progm
  | struct progm
;

proc: return_type ID OPENING_PARENTHESIS zeroOrMoreDeclarations CLOSING_PARENTHESIS OPENING_CURLY_BRACES zeroOrMoreDeclarations CLOSING_CURLY_BRACES
;

struct: STRUCT ID OPENING_CURLY_BRACES oneOrMoreDeclarations CLOSING_CURLY_BRACES     
;



*/

statement:stmt
	| proc
;

stmt: FOR OPENING_PARENTHESIS ID ASSIGN expr SEMICOL expr SEMICOL stmt CLOSING_PARENTHESIS  OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
  | PRINTF OPENING_PARENTHESIS STR CLOSING_PARENTHESIS SEMICOL
  | RETURN expr SEMICOL
  | OPENING_CURLY_BRACES stmt_seq CLOSING_CURLY_BRACES
  | type ID SEMICOL
  | lexp EQUALS expr SEMICOL
  | ID ASSIGN expr SEMICOL
  | ID  OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | ID ASSIGN ID OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | if_stmt

;
proc: return_type ID OPENING_PARENTHESIS zeroOrMoreDeclarations CLOSING_PARENTHESIS OPENING_CURLY_BRACES zeroOrMoreStatements CLOSING_CURLY_BRACES
;

if_stmt: IF OPENING_PARENTHESIS expr CLOSING_PARENTHESIS THEN OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
  | IF OPENING_PARENTHESIS expr CLOSING_PARENTHESIS THEN OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES ELSE OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
;
expr : NUM {printf("k");}
| STR
|TRUE
|FALSE{printf("valid")}
|expr op expr
|MINUS expr %prec UMINUS
|NOT expr
|lexp
|OPENING_PARENTHESIS expr CLOSING_PARENTHESIS
;

exprs: 
    | expr COMMA exprs
;

type: TYPE
  | ID
 ;
zeroOrMoreDeclarations:
   | declaration
   | declaration COMMA zeroOrMoreDeclarations
 ;

zeroOrMoreStatements:
  | if_stmt zeroOrMoreStatements
  | stmt zeroOrMoreStatements
;
declaration: type ID
;



op: PLUS|MINUS|MULTIPLY|DIVIDE|MOD|AND|OR|EQUALS|GREATER_THAN|GREATER_THAN_EQUALS|LESS_THAN|LESS_THAN_EQUALS|NOT_EQUALS
stmt_seq:
  | stmt stmt_seq
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

int main()
{


    FILE *fp;
    fp = fopen("input.txt","r");
    yyin = fp;

  int parse = yyparse();
  fclose(yyin);
 // display_table();

  if(parse == 0)
  {
    printf("Parser: VALID\n");
  }

  return 0;


}
int yyerror(){
	fprintf(stderr, "%s\n", "My error");
  exit(1);
}








