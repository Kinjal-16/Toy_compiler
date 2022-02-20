%{
    #include <string.h>
    int MAX_VALUE=2147483647;
    const char * yycopy;
    const char * yycopy2;
    int value;
    int value2;
        /* definition */
%}

%%


[ \t\n]                 ;
"//".*                    ;
"##".*                    ;
bool   printf("VALID \n");
int printf("VALID \n");
true printf("VALID \n");
false printf("VALID \n");
void printf("VALID \n");
printf printf("VALID \n");
string printf("VALID \n");
struct printf("VALID \n");
if printf("VALID \n");
then printf("VALID \n");
else printf("VALID \n");
for printf("VALID \n");
return printf("VALID \n");


[a-zA-Z_][a-zA-Z0-9_]*   printf("VALID ");
[0-9]+ {
    yycopy = strdup( yytext);
    if(yyleng < 10)
        printf("VALID \n");
    else
    {
        if(yyleng == 10)
        {
            int x =  yycopy[yyleng-1]- '0';
            int y=  yycopy[0]- '0';
            printf("%d \n",x);
            if(y>2)
                printf("Error \n");
            else
            {
                if(y==2)
                { 
                    if(x>7)
                        printf("Error \n");
                    else 
                        printf("VALID \n");
                }
                else 
                    printf("VALID \n");
            }
        }
        else 
            printf("Error \n");
    }
      }
[a-zA-Z0-9_-][0-9a-zaA-Z_-]+ printf("ERROR");


"="                    printf("VALID  ");
"=="                    printf("VALID  ");
"!="                    printf("VALID  ");
"<"                    printf("VALID  ");
"<="                    printf("VALID  ");
">"                     printf("VALID  ");
">="                   printf("VALID  ");
"("                    printf("VALID  ");
")"                     printf("VALID  ");
"{"                     printf("VALID  ");
"}"                    printf("VALID  ");
"."                     printf("VALID  ");
","                    printf("VALID  ");
"+"                    printf("VALID  ");
"-"                     printf("VALID   ");
"*"                      printf("VALID   ");
        
\"(\\([abfnrtv][^'"?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])\"   { / Valid string */ } printf("VALID ");
\"(\\([abfnrtv'"?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])/\\  { /* ERROR escape sequence */ } printf("ERROR ");yyterminate();
\"(\\([abfnrtv'?\n]|[0-7]{1,3}|x[[:xdigit:]]+|u[[:xdigit:]]{4}|U[[:xdigit:]]{8})|[^\\"\n])*   { /* Missing terminating quote */ }  printf("ERROR ");yyterminate();

.                      printf("ERROR ");yyterminate(); 

%%
int yywrap() {
 
}

 int main()
{
    printf("Enter a string ");
    yylex();
    return 0;
}