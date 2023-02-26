/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |
|       - T̶E̶R̶N̶E̶R̶Y̶                                                                                                  |
|       - O̶R̶D̶E̶R̶ O̶F̶ O̶P̶E̶R̶A̶T̶I̶O̶N̶S̶                                                                                      |
|       - F̶I̶X̶ "̶s̶y̶n̶t̶a̶x̶ e̶r̶r̶o̶r̶"̶ b̶u̶g̶ o̶n̶ s̶e̶c̶o̶n̶d̶ i̶n̶p̶u̶t̶                                                                   |
|       - functions                                                                                                | 
|       - n̶u̶m̶b̶e̶r̶ t̶y̶p̶e̶s̶                                                                                             |
\-----------------------------------------------------------------------------------------------------------------*/

/* Prologue */
%{
int yylex();
void yyerror(char *s);
%}

%code requires {
  #include "ast-manual.h"
}

/* YYSTYPE union */
%union { 
    struct numinfo numInfo;
    struct stringinfo stringInfo; 
    char char_literal; 
    union astnode *astnode_p; 
    int operator; 
}

/* Tokens */
%token<stringInfo> IDENT 
%token<char_literal> CHARLIT 
%token<stringInfo> STRING 
%token<numInfo> NUMBER 
%token<operator> INDSEL PLUSPLUS MINUSMINUS LTEQ GTEQ EQEQ NOTEQ
        LOGAND LOGOR SHL SHR TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ 
        SHREQ ANDEQ OREQ XOREQ SIZEOF ELLIPSIS AUTO BREAK CASE CHAR 
        CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR 
        GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN SHORT SIGNED 
        STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE 
        WHILE _BOOL _COMPLEX _IMAGINARY TOKEOF

/* Bison Expressions */
%type<astnode_p>primary_expression 
                postfix_expression 
                argument_expression_list
                unary_expression
%type<operator> unary_operator
%type<astnode_p> cast_expression
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
%type<operator> assignment_operator
%type<astnode_p> expression 
                constant_expression
%type<operator>  type_name

/* Grammar rules */
%left <operator> ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%left LOGOR
%left LOGAND
%left <operator> '|'
%left <operator> '^'
%left <operator> '&'
%left EQEQ NOTEQ
%left '<' '>' LTEQ GTEQ
%left SHL SHR
%left <operator> '+' '-'
%left <operator> '*' '/' '%'
%right SIZEOF '!' '~' 
%left PLUSPLUS MINUSMINUS INDSEL '(' ')' '[' ']'
%left IF
%left ELSE

%%

start : expression
    | start expression
    ;

expression: assignment_expression {$$ = $1;}
    | expression ',' assignment_expression {$$ = new_astnode_binop(',', $1, $3);}
    | expression ';' {printAST($1, 0);}
    ;

primary_expression: IDENT {$$ = new_astnode_ident(IDENT_NODE, $1.string_literal);
              //printf("Ident is %s\n", $<astnode_p>$->str.string_literal); 
              }
        | NUMBER {$$ = new_astnode_num(NUMBER_NODE, $1);
                    //printf("Number is %d\n", $<astnode_p>$->num.number); 
                    }
        | CHARLIT {$$ = new_astnode_char(CHARLIT_NODE, $1);
                    //printf("Char is %c\n", $<astnode_p>$->charlit.char_literal); 
                    }
        | STRING {$$ = new_astnode_string(STRING_NODE, $1.string_literal);
                    //printf("String is %s\n", $<astnode_p>$->str.string_literal); 
                    }
        | '('expression')' {$$ = $2;} 
        ;

postfix_expression: primary_expression {$$ = $1;}
    | postfix_expression '[' expression']' { // E1[E2] is identical to (*((E1)+(E2))) 
                                            astnode *astnode_temp = new_astnode_binop('+', $1, $3);
                                            $$ = new_astnode_unop('*', astnode_temp);                           
    }
    //| postfix_expression '(' argument_expression_list ')' /* This causes S/R conflict */
    | postfix_expression '.' IDENT {astnode *astnode_ident = new_astnode_ident(IDENT_NODE, $3.string_literal);
                                    $$ = new_astnode_binop('.', $1, astnode_ident); 
                                    // free?
    }
    | postfix_expression INDSEL IDENT { // E1->E2 is identical to (*E1).E2
                                      astnode *astnode_temp = new_astnode_unop('*', $1);
                                      astnode *astnode_ident = new_astnode_ident(IDENT_NODE, $3.string_literal);
                                      $$ = new_astnode_binop('.', astnode_temp, astnode_ident);
    }
    //| postfix_expression PLUSPLUS {$$ = new_astnode_unop(PLUSPLUS, $1);} /* This causes a S/R conflict! */
    | postfix_expression MINUSMINUS {$$ = new_astnode_unop(MINUSMINUS, $1);}
    | '(' type_name ')' '{' initializer_list '}'
    | '(' type_name ')' '{' initializer_list ',' '}'
    ;

cast_expression: unary_expression
  | '(' type_name ')' cast_expression
  ;

type_name: CHAR {$$ = CHAR;}
  | INT {$$ = INT;}
  | LONG {$$ = LONG;}
  | DOUBLE {$$ = DOUBLE;}
  | FLOAT {$$ = FLOAT;}
  ;

unary_operator: '&' {$$ = '&';}
  | '*' {$$ = '*';}
  | '+' {$$ = '+';}
  | '-' {$$ = '-';}
  | '~' {$$ = '~';}
  | '!' {$$ = '!';}
  ;

unary_expression: postfix_expression {$$ = $1;}
  | PLUSPLUS unary_expression {$$ = new_astnode_unop(PLUSPLUS, $2);}
  //| MINUSMINUS unary_expression {$$ = new_astnode_unop(MINUSMINUS, $2);} /* This causes S/R conflict */
  | unary_operator cast_expression {$$ = new_astnode_unop($1, $2);}
  //| SIZEOF unary_expression {$$ = new_astnode_unop(SIZEOF, $2);}
  //| SIZEOF '(' type_name ')' {$$ = new_astnode_unop(SIZEOF, $3);} 
  ;

multiplicative_expression: cast_expression {$$ = $1;}
  //| multiplicative_expression '*' cast_expression {$$ = new_astnode_binop('*', $1, $3);} /* This causes S/R conflict */
  | multiplicative_expression '/' cast_expression {$$ = new_astnode_binop('/', $1, $3);}
  | multiplicative_expression '%' cast_expression {$$ = new_astnode_binop('%', $1, $3);}
  ;

additive_expression: multiplicative_expression {$$ = $1;}
  //| additive_expression '+' multiplicative_expression {$$ = new_astnode_binop('+', $1, $3);} /* This causes S/R conflict */
  //| additive_expression '_' multiplicative_expression {$$ = new_astnode_binop('-', $1, $3);} /* This causes S/R conflict */
  ;

shift_expression: additive_expression {$$ = $1;}
  | shift_expression SHL additive_expression {$$ = new_astnode_binop(SHL, $1, $3);}
  | shift_expression SHR additive_expression {$$ = new_astnode_binop(SHR, $1, $3);}
  ;

relational_expression: shift_expression {$$ = $1;}
  | relational_expression '<' shift_expression {$$ = new_astnode_binop('<', $1, $3);}
  | relational_expression '>' shift_expression {$$ = new_astnode_binop('>', $1, $3);}
  | relational_expression LTEQ shift_expression {$$ = new_astnode_binop(LTEQ, $1, $3);}
  | relational_expression GTEQ shift_expression {$$ = new_astnode_binop(GTEQ, $1, $3);}
  ;

equality_expression: relational_expression {$$ = $1;}
  | equality_expression EQEQ relational_expression {$$ = new_astnode_binop(EQEQ, $1, $3);}
  | equality_expression NOTEQ relational_expression {$$ = new_astnode_binop(NOTEQ, $1, $3);}
  ;

AND_expression: equality_expression {$$ = $1;}
  //| AND_expression '&' equality_expression {$$ = new_astnode_binop('&', $1, $3);} /* This causes S/R conflict */
  ;

exclusive_OR_expression: AND_expression {$$ = $1;}
  | exclusive_OR_expression '^' AND_expression {$$ = new_astnode_binop('^', $1, $3);}
  ;

inclusive_OR_expression: exclusive_OR_expression {$$ = $1;}
  | inclusive_OR_expression '|' exclusive_OR_expression {$$ = new_astnode_binop('|', $1, $3);}
  ;

logical_AND_expression: inclusive_OR_expression {$$ = $1;}
  | logical_AND_expression LOGAND inclusive_OR_expression {$$ = new_astnode_binop(LOGAND, $1, $3);}
  ;

logical_OR_expression: logical_AND_expression {$$ = $1;}
| logical_OR_expression LOGOR logical_AND_expression {$$ = new_astnode_binop(LOGOR, $1, $3);}
;

conditional_expression: logical_OR_expression {$$ = $1;}
  | logical_OR_expression '?' expression ':' conditional_expression {$$ = new_astnode_ternop('?', ':', $1, $3, $5);}
  ;

assignment_expression: conditional_expression {$$ = $1;}
  | unary_expression assignment_operator assignment_expression {$$ = new_astnode_binop($2, $1, $3);}
  ; 

assignment_operator: '=' {$$ = '=';}
  | TIMESEQ {$$ = TIMESEQ;}
  | DIVEQ {$$ = DIVEQ;} 
  | MODEQ {$$ = MODEQ;} 
  | PLUSEQ {$$ = PLUSEQ;}
  | MINUSEQ {$$ = MINUSEQ;}
  | SHLEQ {$$ = SHLEQ;}
  | SHREQ {$$ = SHREQ;}
  | ANDEQ {$$ = ANDEQ;}
  | XOREQ {$$ = XOREQ;}
  | OREQ {$$ = OREQ;}
  ;

argument_expression_list: assignment_expression {$$ = $1;}
    | argument_expression_list ',' assignment_expression {$$ = new_astnode_binop(',', $1, $3);}
    ; 

constant_expression: conditional_expression; 

initializer_list:
;

%%


void printBinop(int operator){
    if(operator == '=') {
        printf("ASSIGNMENT\n"); 
    } else if(operator >= 267 && operator <= 270){
        printf("COMPARISON OP ");
    } else if(operator >= 271 && operator <= 284){
        printf("ASSIGNMENT COMPOUND (");
    } 
    switch(operator){
        case LTEQ:
            printf("<");
            break;
        case GTEQ:
            printf(">");
            break;
        case EQEQ:
            printf("=");
            break;
        case NOTEQ:
            printf("!");
            break;
        case LOGAND:
            printf("&&\n");
            break;
        case LOGOR:
            printf("||\n");
            break;
        case SHL:
            printf("<<");
            break;
        case SHR:
            printf(">>");
            break;
        case TIMESEQ:
            printf("*");
            break;
        case DIVEQ:
            printf("/");
            break;
        case MODEQ:
            printf("%%");
            break;
        case PLUSEQ:
            printf("+");
            break;
        case MINUSEQ:
            printf("-");
            break;
        case SHLEQ:
            printf("<<");
            break;
        case SHREQ:
            printf(">>");
            break;
        case ANDEQ:
            printf("&");
            break;
        case OREQ:
            printf("|");
            break;
        case XOREQ:
            printf("^");
            break;
    }

    if(operator >= 267 && operator <= 270){
        printf("=\n");
    } else if(operator >= 271 && operator <= 282){
        printf(")\n");
    } 
}

void printNum(struct numinfo numInfo){
    switch(numInfo.meta) {
            case(0):
            case(1):
                printf("int)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(2):
            case(3):
                printf("long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(4):
            case(5):
                printf("long long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(6):
                printf("double)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(7):
                printf("float)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(8):
                printf("long double)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
    }
}

void printAST(union astnode* node, int indent) {
    for (int i = 0; i < indent; i++){
        printf("\t");
    }

    switch(node->generic.type){
        case UNOP_NODE: 
            printf("UNARY OP %c\n", node->unop.operator);
            printAST(node->unop.operand, indent+1); 
            break;
        case BINOP_NODE:
            if ((node->binop.operator >= 265 && node->binop.operator <= 282) || node->binop.operator == '=') {
                printBinop(node->binop.operator); 
            } else {
                printf("BINARY OP %c\n", node->binop.operator);
            }
            printAST(node->binop.left, indent+1); 
            printAST(node->binop.right, indent+1); 
            break;
        case TERNOP_NODE:
            printf("TERNARY OP, IF:\n");
	        printAST(node->ternop.left, indent+1);
            printf("THEN:\n");
            printAST(node->ternop.middle, indent+1);
	        printf("ELSE:\n");
            printAST(node->ternop.right, indent+1);
            break;
        case NUMBER_NODE:
            printf("CONSTANT: (type=");
            printNum(node->num.numInfo);
            break;
        case IDENT_NODE:
            printf("IDENT %s\n", node->id.ident);
            break;
        case STRING_NODE:
            printf("STRING %s\n", node->str.string_literal);
            break;
        case CHARLIT_NODE:
            printf("CHARLIT %c\n", node->charlit.char_literal);
            break;
    }
    free(node); 
}
int main(){
  //yydebug = 1;
  int t;
  while(!(t = yyparse())){

  };
}

void yyerror(char *str) {
  fprintf(stderr,"error: %s\n",str);
}

