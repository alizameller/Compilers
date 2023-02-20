/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |
|                                                                                                                  |
\-----------------------------------------------------------------------------------------------------------------*/

/* Prologue */

%code requires {
  #include "ast-manual.h"
  int yylex(void);
  void yyerror(char *s);
}
%define parse.error verbose

/* YYSTYPE union */
%union { 
	struct numinfo numInfo;
  struct stringinfo stringInfo; 
	char char_literal; 
  union astnode *astnode_p; 
}

%start primary_expression

/* Tokens */
%token<stringInfo> IDENT 
%token<char_literal> CHARLIT 
%token<stringInfo> STRING 
%token<numInfo> NUMBER 
%token INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ EQEQ NOTEQ
       LOGAND LOGOR TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ SHREQ
       ANDEQ OREQ XOREQ SIZEOF ELLIPSIS AUTO BREAK CASE CHAR CONST 
       CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO 
       IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED 
       STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE 
       WHILE _BOOL _COMPLEX _IMAGINARY TOKEOF

/* Bison Expressions */
%type<astnode_p>	primary_expression 
/*
                  postfix_expression 
                  argument_expression_list
                  unary_expression
                  unary_operator
                  cast_expression
                  multiplicative_expression
                  additive_expression
                  shift_expression
                  relational_expression
                  equality_expression
                  AND_expression
                  exclusive_OR_expression
                  inclusive_OR_expression
                  logical_AND_expression
                  logical_OR_expression
                  conditional_expression
                  assignment_expression
                  assignment_operator
                  expression 
                  constant_expression
                  */

/* Grammar rules */
%%

primary_expression: 
      IDENT {$$ = new_astnode_ident(IDENT_NODE, $1.string_literal);
              printf("Ident is %s\n", $<astnode_p>$->str.string_literal); 
              }
    | NUMBER {$$ = new_astnode_num(NUMBER_NODE, $1.value.int_val);
              printf("Number is %d\n", $<astnode_p>$->num.number); 
              }
    | CHARLIT {$$ = new_astnode_char(CHARLIT_NODE, $1);
              printf("Char is %c\n", $<astnode_p>$->charlit.char_literal); 
              }
    | STRING {$$ = new_astnode_string(STRING_NODE, $1.string_literal);
              printf("String is %s\n", $<astnode_p>$->str.string_literal); 
              }
    | '('primary_expression')' {$$ = $2;}
    | primary_expression 
    ;
/*
postfix_expression: primary_expression
    | postfix_expression '[' expression']' 
    | postfix_expression '(' argument_expression_list ')' //look at opt 
    | postfix_expression '.' IDENT
    | postfix_expression INDSEL IDENT
    | postfix_expression PLUSPLUS
    | postfix_expression MINUSMINUS
    //| '(' type_name ')' '{' initializer_list '}'
    //| '(' type_name ')' '{' initializer_list ',' '}'
    ;

argument_expression_list: assignment_expression
    | argument_expression_list ',' assignment_expression
    ;

unary_expression: postfix_expression
  | PLUSPLUS unary_expression
  | MINUSMINUS unary_expression 
  | unary_operator cast_expression 
  | SIZEOF unary_expression 
//  | SIZEOF '(' type_name ')'
  ;

constant_expression: conditional_expression; 

expression: assignment_expression
  | expression ',' assignment_expression
  ;

assignment_operator: '=' | TIMESEQ | DIVEQ | MODEQ | PLUSEQ | MINUSEQ 
  | SHLEQ | SHREQ | ANDEQ | XOREQ | OREQ

assignment_expression: conditional_expression
  | unary_expression assignment_operator assignment_expression
  ;

conditional_expression: logical_OR_expression
  | logical_OR_expression '?' expression ':' conditional_expression
  ;

logical_OR_expression: logical_AND_expression
  | logical_OR_expression LOGOR logical_AND_expression
  ;

logical_AND_expression: inclusive_OR_expression
  | logical_AND_expression LOGAND inclusive_OR_expression
  ;

inclusive_OR_expression: exclusive_OR_expression
  | inclusive_OR_expression '|' exclusive_OR_expression
  ;

exclusive_OR_expression: AND_expression
  | exclusive_OR_expression '^' AND_expression
  ;

AND_expression: equality_expression
  | AND_expression '&' equality_expression
  ;

equality_expression: relational_expression
  | equality_expression EQEQ relational_expression
  | equality_expression NOTEQ relational_expression
  ;

relational_expression: shift_expression
  | relational_expression '<' shift_expression
  | relational_expression '>' shift_expression
  | relational_expression LTEQ shift_expression
  | relational_expression GTEQ shift_expression
  ;

shift_expression: additive_expression
  | shift_expression SHL additive_expression 
  | shift_expression SHR additive_expression

additive_expression: multiplicative_expression
  | additive_expression '+' multiplicative_expression
  | additive_expression '_' multiplicative_expression


multiplicative_expression: cast_expression
  | multiplicative_expression '*' cast_expression
  | multiplicative_expression '/' cast_expression
  | multiplicative_expression '%' cast_expression
  ;

cast_expression: unary_expression
//  | '(' type_name ')' cast_expression
  ;

unary_operator: '&'
  | '*'
  | '+'
  | '-'
  | '~'
  | '!'
  ;

//initializer_list:
//type_name: *** WHAT DO I DO ABOUT THIS ONE ***
*/
%%
int main() {
  yydebug = 1;
  while(1) {
    yyparse();
  }; 
  return 0;
}

void yyerror (s) 
char *s;
{  /* Called by yyparse on error */
  printf ("%s\n", s);
}

