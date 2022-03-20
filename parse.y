%define api.prefix {Toy_compiler}
%define api.parser.class {parser}
%define api.parser.public
%define parse.error verbose

%code imports{
  import java.io.InputStream;
  import java.io.InputStreamReader;
  import java.io.Reader;
  import java.io.IOException;
}

%code {
  public static void main(String args[]) throws IOException {
    lex lexer = new lex(System.in);
    Toy_compiler parser = new Toy_compiler(lexer);
    if(parser.parse())
      System.out.println("VALID");
    return;
  }
}

%token TBOOL,TEQUAL,TCEQ,TCNE,TCLT,TCLE,TCGT,TCGE,TLPAREN,TRPAREN,TLBRACE,TRBRACE,TDOT,TCOMMA,TPLUS,TMINUS,TMUL,TWORD,TNUM,TIDENTIFIER

%%
< stmt > ::= for ( < id > = < expr >; < expr > ; < statement >) < statement >
 | if ( < expr >) then < statement >
 | if ( < expr >) then < statement > else < statement >
 | printf ( < string >);
 | return < expr >;
 | { < statement - seq > }
 | < type > <id >; # variable declaration
 | <l - exp > = < expr >;
 | <id >( < expr > ,...);
 | id = <id >( < expr > ,...);

<exp> ::= <int - literal >
| < string - literal >
| true
| false
| <exp > <op > <exp >
| - <exp >
| ! <exp >
| <l - exp >
| ( <exp > )
;

<op > ::= + | - | * | / | mod | and | or | == | > | < | >= | <= | !=

<l - exp > ::= <id > | <id > . <l - exp >
<pgm > ::= < proc > <pgm’>
| < struct > <pgm >
<pgm’> ::= # empty sequence
| <proc> <pgm’>
| <struct> <pgm’>






%%

class lexer implements Toy_compiler.parser {
  InputStreamReader it;
  Yylex yylex;

  public CNF3Lexer(InputStream is){
    it = new InputStreamReader(is);
    yylex = new Yylex(it);
  }

  @Override
  public void yyerror (String s){
    System.err.println(s +" ERROR");
  }

  @Override
  public Object getLVal() {
    return null;
  }

  @Override
  public int yylex () throws IOException{
    return yylex.yylex();
  }
}