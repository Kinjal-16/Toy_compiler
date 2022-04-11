%{
    #include <string.h>
    #include "parse.tab.h"
    const char * yycopy;
    const char * yycopy2;
    int value;
    int value2;
        /* definition */
%}

%%


[ \t\n]                                   ;
"//".*                                    ;
"##".*                                    ;
bool                    {return TYPE;}
int                     {return TYPE;}
true                    {return TRUE;}
false                   {return FALSE;}
void                    {return VOID;}
printf                  {return PRINTF;}
string                  {return TYPE;}
struct                  {return STRUCT;}
if                      {return IF;}
then                    {return THEN;}
else                    {return ELSE;}
for                     {return FOR;}
return                  {return RETURN;}
and                      {return AND;}
mod                       {return MOD;}
or                       {return OR;}


[a-zA-Z_][a-zA-Z0-9_]*   {return ID;}
[0-9]+ {
    yycopy = strdup( yytext);
    if(yyleng < 5)
        {return NUM;}
    else
    {
        if(yyleng == 5)
        {
            int x =  yycopy[yyleng-1]- '0';
            int y=  yycopy[0]- '0';
            if(y>3)
                printf("Error \n");
            else
            {
                if(y==3)
                { 
                    if(x>7)
                        printf("Error \n");
                    else 
                        {return NUM;}
                }
                else 
                    {return NUM;}
            }
        }
        else 
            printf("Error \n");
    }
      }
[a-zA-Z0-9_-][0-9a-zaA-Z_-]+ printf("ERROR");
";"                      {return SEMICOL;}
"!"                     {return NOT;}
"="                    {return ASSIGN;}
"=="                   {return EQUALS;}
"!="                    {return NOT_EQUALS;}
"<"                    {return LESS_THAN;}
"<="                   {return LESS_THAN_EQUALS;}
">"                     {return GREATER_THAN;}
">="                   {return GREATER_THAN_EQUALS;}
"("                    {return OPENING_PARENTHESIS;};
")"                     {return CLOSING_PARENTHESIS;}
"{"                     {return OPENING_CURLY_BRACES;}
"}"                    {return CLOSING_CURLY_BRACES;}
"."                     {return FULLSTOP;}
","                    {return COMMA;}
"+"                    {return PLUS;}
"-"                    {return MINUS;}
"*"                     {return MULTIPLY;}
"/"                     {return DIVIDE;}

\"(\\([abfnrtv][^'"?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])*\"   { /* Valid string */ } {return STR;}
\"(\\([abfnrtv'"?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])/\\  { /* ERROR escape sequence */ } printf("ERROR ");yyterminate();
\"(\\([abfnrtv'?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])*   { /* Missing terminating quote */ }  printf("ERROR ");yyterminate();

.                      printf("ERROR ");yyterminate(); 

%%
yywrap() {}