%{
 #include <stdio.h>
 #include<string.h>

 #include <stdlib.h>
 #include "S_table.h"
 extern FILE *yyin;
 extern int yylex();
int errors=0;
bool itis=false;
char *procedure;
install ( char *sym_name,char *type )
{  symrec *s;
   s = getsym (sym_name);
   if (s == 0)
        s = putsym (sym_name,type);
   else {
   	errors++;

   }
}
installattributes(char *sym_name,car *type){
  sublist *s ;
  s= getlist(char *symname);
  if(s==0)
  {
    error++;
  }
  else
  {
  put(sym_name,type,s);
  }
}
context_check( char *sym_name )
{ if ( getsym( sym_name ) == 0 )
     printf( "%s is an undeclared identifier\n", sym_name );
}
  int yyerror(const char *msg);
  int yylex();

%}

%union { 
  char *id;
  int a;
  char *string;
}

%token NUM
%token<string> ID STR TYPE
%token EQUALS NOT_EQUALS NOT LESS_THAN LESS_THAN_EQUALS GREATER_THAN GREATER_THAN_EQUALS
%token OPENING_PARENTHESIS CLOSING_PARENTHESIS OPENING_CURLY_BRACES CLOSING_CURLY_BRACES
%token PLUS MINUS MULTIPLY MOD DIVIDE
%token IF THEN ELSE TRUE FALSE SEMICOL STRUCT  VOID PRINTF ASSIGN FULLSTOP COMMA FOR RETURN
%token EQU  AND OR

%right EQUALS 
%left  ASSIGN FULLSTOP
%nonassoc OR AND MOD NOT_EQUALS GREATER_THAN GREATER_THAN_EQUALS LESS_THAN_EQUALS LESS_THAN
%left MULTIPLY DIVIDE 
%left PLUS MINUS
%left UMINUS NOT

%right "lexp"



 
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

prog: proc progm
  | struct progm
progm:
  | proc progm
  | struct progm
struct: STRUCT ID OPENING_CURLY_BRACES oneOrMoreDeclarations CLOSING_CURLY_BRACES {install($2);  procedure = $2; itis=true;}  
proc: return_type ID OPENING_PARENTHESIS zeroOrMoreDeclarations CLOSING_PARENTHESIS OPENING_CURLY_BRACES zeroOrMoreStatements CLOSING_CURLY_BRACES {install($2);   }
;  {procedure = $2;itis=false;}

/*
statement:stmt
	| prog
;*/

stmt: FOR OPENING_PARENTHESIS ID ASSIGN expr SEMICOL expr SEMICOL stmt CLOSING_PARENTHESIS  OPENING_CURLY_BRACES stmt CLOSING_CURLY_BRACES
  | PRINTF OPENING_PARENTHESIS STR CLOSING_PARENTHESIS SEMICOL
  | RETURN expr SEMICOL
  | OPENING_CURLY_BRACES stmt_seq CLOSING_CURLY_BRACES
  | declaration SEMICOL
  | lexp ASSIGN expr SEMICOL
  | ID ASSIGN expr SEMICOL
  | ID  OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | ID ASSIGN ID OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | if_stmt

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
return_type: INT
  |BOOL
  |STRING
  | VOID
;
type: INT
  |BOOL
  |STRING
  | VOID
 ;
zeroOrMoreDeclarations:
   | declaration
   | declaration COMMA zeroOrMoreDeclarations
 ;
oneOrMoreDeclarations: declaration
  | declaration COMMA oneOrMoreDeclarations
;
zeroOrMoreStatements:
  | if_stmt zeroOrMoreStatements
  | stmt zeroOrMoreStatements
;
declaration: type ID  {install($2);   }
;



op: PLUS|MINUS|MULTIPLY|DIVIDE|MOD|AND|OR|EQUALS|GREATER_THAN|GREATER_THAN_EQUALS|LESS_THAN|LESS_THAN_EQUALS|NOT_EQUALS
stmt_seq:
  | stmt stmt_seq
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
 if(errors>0)
{
	yyerror("Invalid");
	}
  if(parse == 0 )
  {
    printf("Parser: VALID\n");
  }

  return 0;


}
int yyerror(const char *msg){
	fprintf(stderr, "%s\n", "My error");
  exit(1);
}








