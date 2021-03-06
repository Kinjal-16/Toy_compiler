%{
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


%}

%union { 
  char *id;
  int a;
  char *string;
}

%token NUM
%token<string> ID STR INT BOOL STRING VOID
%token EQUALS NOT_EQUALS NOT LESS_THAN LESS_THAN_EQUALS GREATER_THAN GREATER_THAN_EQUALS
%token OPENING_PARENTHESIS CLOSING_PARENTHESIS OPENING_CURLY_BRACES CLOSING_CURLY_BRACES
%token PLUS MINUS MULTIPLY MOD DIVIDE
%token IF THEN ELSE TRUE FALSE SEMICOL STRUCT PRINTF ASSIGN FULLSTOP COMMA FOR RETURN
%token EQU  AND OR

%right EQUALS 
%left  ASSIGN FULLSTOP
%nonassoc OR AND MOD NOT_EQUALS GREATER_THAN GREATER_THAN_EQUALS LESS_THAN_EQUALS LESS_THAN
%left MULTIPLY DIVIDE 
%left PLUS MINUS
%left UMINUS NOT

%right "lexp"



 
%%


prog: proc progm
  | struct progm
progm:
  | proc progm
  | struct progm
struct: STRUCT ID OPENING_CURLY_BRACES  {
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

}  oneOrMoreDeclarations CLOSING_CURLY_BRACES {
  temp=strremove(temp,rem);
  str=temp;

  install($2,"null");  procedure = $2;checkinit();}  
proc: return_type ID OPENING_PARENTHESIS zeroOrMoreDeclarations CLOSING_PARENTHESIS OPENING_CURLY_BRACES zeroOrMoreStatements CLOSING_CURLY_BRACES {
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
  
  
  
  ;procedure = $2;checkinit();}
;
/*
statement:stmt
	| prog
;*/

stmt: FOR OPENING_PARENTHESIS ID ASSIGN expr SEMICOL boolop SEMICOL  stmt CLOSING_PARENTHESIS  OPENING_CURLY_BRACES {
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
  

} zeroOrMoreStatements CLOSING_CURLY_BRACES  {
  temp=strremove(temp,rem);
  str=temp;
  }
  | PRINTF OPENING_PARENTHESIS STR CLOSING_PARENTHESIS SEMICOL
  | RETURN expr SEMICOL {returnStore=v;memset(ar, 0, 1000);point=0;current=returnT(v,current);ret++;}
  | OPENING_CURLY_BRACES stmt_seq CLOSING_CURLY_BRACES
  | type ID SEMICOL    {installattributes($2,t);}
  | lexp ASSIGN expTem SEMICOL {
    if(hey!=NULL)
      if(strcmp(v,hey->type)!=0)
        errors++;memset(ar, 0, 1000);point=0;}
  | ID ASSIGN expr SEMICOL {init($1,v);memset(ar, 0, 1000);point=0;}
  | ID  OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | ID ASSIGN ID OPENING_PARENTHESIS exprs CLOSING_PARENTHESIS SEMICOL
  | if_stmt
  | if_stmt ELSE OPENING_CURLY_BRACES  {
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
  
  
  } zeroOrMoreStatements CLOSING_CURLY_BRACES {
  
  temp=strremove(temp,rem);
  str=temp;

  
  } 
  

;

if_stmt: IF OPENING_PARENTHESIS expr CLOSING_PARENTHESIS {

  
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
  

}  THEN OPENING_CURLY_BRACES zeroOrMoreStatements CLOSING_CURLY_BRACES {
  temp=strremove(temp,rem);
  str=temp;
  
  } 
; 
expr :STR     {v="string";

  
    ar[point]=v;
    point++;
  
}
| NUM {v="int";
  ar[point]=v;
    point++;
  
  }
| 
|TRUE   {v="bool";
  
  
    ar[point]="bool";
    point++;
  }
|FALSE   {v="bool";


    ar[point]=v;
    point++;
  } 
|expr op expr 
|MINUS expr %prec UMINUS {memset(ar, 0, 1000);point=0;}
|NOT expr  {memset(ar, 0, 1000);point=0;}
|lexp
|OPENING_PARENTHESIS expr CLOSING_PARENTHESIS {memset(ar, 0, 1000);point=0;}
;



boolop:exprtt bools exprtt{
  
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
}
;



exprtt :STR{v="string";

  
    ar[point]=v;
    point++;
  
}
| NUM {v="int";
  ar[point]=v;
    point++;
  
  }
| 
|TRUE   {v="bool";
  
  
    ar[point]="bool";
    point++;
  }
|FALSE   {v="bool";


    ar[point]=v;
    point++;
  } 
|MINUS exprtt %prec UMINUS {memset(ar, 0, 1000);point=0;}
|NOT exprtt 
|blexp
|OPENING_PARENTHESIS exprtt CLOSING_PARENTHESIS
;

expTem:STR{v="string";}
| NUM {v="int"; }
|TRUE   {v="bool";}
|FALSE   {v="bool";} 
;

exprs: 
    | expr COMMA exprs
;
return_type: INT {jk = $1;
};
  |BOOL{jk = $1;
};
  |STRING {jk = $1;
};
  |VOID  {jk = "void";
 
};
type: INT {t = $1;}
  |BOOL {t = $1;}
  |STRING
{t = $1;}
  |ID 
  {t=$1;}
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


declaration: type ID   { installattributes($2,t);   }
;

returnexp:ID
|NUM {v="int";}
| STR     {v="string";}
|TRUE   {v="bool";}
|FALSE   {v="bool";} 
|OPENING_PARENTHESIS returnexp CLOSING_PARENTHESIS
;


op: PLUS|MINUS|MULTIPLY|DIVIDE|MOD|AND|OR|EQUALS|GREATER_THAN|GREATER_THAN_EQUALS|LESS_THAN|LESS_THAN_EQUALS|NOT_EQUALS
;
bools: MOD|AND|OR|EQUALS|GREATER_THAN|GREATER_THAN_EQUALS|LESS_THAN|LESS_THAN_EQUALS|NOT_EQUALS
;
stmt_seq:
  | stmt stmt_seq
;




blexp: ID {
  if(get($1,current)==1)
  {
      errors++;
  }
  else 
  {
    sublist *pqr=getTemp($1,current);
    ar[point]=pqr->type;
    point++;
  }
}
;
lexp: ID
| ID FULLSTOP ID
{



  if(get($1,current)==1)
  {
      errors++;
  }
  else 
  {

    sublist *pqr=getTemp($1,current);



    
    
    
    sublist *pqrs=getlist(pqr->type);
    if(pqrs==0)
    {
      errors++;
    }
    else 
    {
    if(get($3,pqrs)==1)
    {
      flag=0;
    
      errors++;
      yyerror;
    }
    else 
    {
     
      sublist *aeou = getTemp($3,pqrs);

      
      hey=aeou;
      
      ar[point]=pqr->type;
      point++;
    }
    }
  }
}
;


%%

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








