/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |
|                                                                                                                  |
\-----------------------------------------------------------------------------------------------------------------*/

/* Proglogue */
%{
#include "ast.c"
int yyerror(char *s);
int yylex(void);
%}

/* Bison declarations */
%start	input 

/* YYSTYPE union */
%union {
    struct numtype number;
    char *string;
    char *ident;
    int operator;
    struct astnode *astnode_p;
}

/* Tokens */
%token<ident> IDENT 
%token<string> CHARLIT 
%token<string> STRING 
%token<number> NUMBER 
%token<operator> INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ
                 LOGAND LOGOR TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ SHREQ
                ANDEQ OREQ XOREQ SIZEOF
/*
%token<operator> ELLIPSIS AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE 
                 ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER 
                 RESTRICT RETURN SHORT SIGNED STATIC STRUCT SWITCH TYPEDEF UNION 
                 UNSIGNED VOID VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY
*/

/* Bison Expressions */
%type<astnode_p>	primary-expression 
                  postfix-expression 
                  argument-expression-list
                  unary-expression
                  unary-operator
                  cast-expression
                  multiplicative-expression
                  additive-expression
                  shift-expression
                  relational-expression
                  equality-expression
                  AND-expression
                  exclusive-OR-expression
                  inclusive-OR-expression
                  logical-AND-expression
                  logical-OR-expression
                  conditional-expression
                  assignment-expression
                  assignment-operator
                  expression 
                  constant-expression

/* Grammar rules */
%%

primary-expression: IDENT {$$ = new_astnode_ident($1);}
    | NUMBER {$$ = new_astnode_num($1);}
    | CHARLIT {$$ = new_astnode_char($1);}
    | STRING {$$ = new_astnode_string($1);}
    | '('expression')'
    ;

postfix-expression: primary-expression
    | postfix-expression '[' expression']' 
    | postfix-expression '(' argument-expression-list ')' //look at opt 
    | postfix-expression '.' IDENT
    | postfix-expression INDSEL IDENT
    | postfix-expression PLUSPLUS
    | postfix-expression MINUSMINUS
    //| '(' type-name ')' '{' initializer-list '}'
    //| '(' type-name ')' '{' initializer-list ',' '}'
    ;

argument-expression-list: assignment-expression
    | argument-expression-list ',' assignment-expression
    ;

unary-expression: postfix-expression
  | PLUSPLUS unary-expression
  | MINUSMINUS unary-expression 
  | unary-operator cast-expression 
  | SIZEOF unary-expression 
//  | SIZEOF '(' type-name ')'
  ;

constant-expression: conditional-expression; 

expression: assignment-expression
  | expression ',' assignment-expression
  ;

assignment-operator: '=' | TIMESEQ | DIVEQ | MODEQ | PLUSEQ | MINUSEQ 
  | SHLEQ | SHREQ | ANDEQ | XOREQ | OREQ

assignment-expression: conditional-expression
  | unary-expression assignment-operator assignment-expression
  ;

conditional-expression: logical-OR-expression
  | logical-OR-expression '?' expression ':' conditional-expression
  ;

logical-OR-expression: logical-AND-expression
  | logical-OR-expression LOGOR logical-AND-expression
  ;

logical-AND-expression: inclusive-OR-expression
  | logical-AND-expression LOGAND inclusive-OR-expression
  ;

inclusive-OR-expression: exclusive-OR-expression
  | inclusive-OR-expression '|' exclusive-OR-expression
  ;

exclusive-OR-expression: AND-expression
  | exclusive-OR-expression '^' AND-expression
  ;

AND-expression: equality-expression
  | AND-expression '&' equality-expression
  ;

equality-expression: relational-expression
  | equality-expression EQEQ relational-expression
  | equality-expression NOTEQ relational-expression
  ;

relational-expression: shift-expression
  | relational-expression '<' shift-expression
  | relational-expression '>' shift-expression
  | relational-expression LTEQ shift-expression
  | relational-expression GTEQ shift-expression
  ;

shift-expression: additive-expression
  | shift-expression SHL additive-expression 
  | shift-expression SHR additive-expression

additive-expression: multiplicative-expression
  | additive-expression '+' multiplicative-expression
  | additive-expression '-' multiplicative-expression


multiplicative-expression: cast-expression
  | multiplicative-expression '*' cast-expression
  | multiplicative-expression '/' cast-expression
  | multiplicative-expression '%' cast-expression
  ;

cast-expression: unary-expression
//  | '(' type-name ')' cast-expression
  ;

unary-operator: '&'
  | '*'
  | '+'
  | '-'
  | '~'
  | '!'
  ;

//initializer-list:
//type-name: *** WHAT DO I DO ABOUT THIS ONE ***

%%

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}

