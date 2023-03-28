/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |
|       - Symbol Table                                                                                             |
|       - AST nodes representing scalar types, pointers, arrays and functions                                      |
|       - "mini symbol table" for representing structure and union types                                           |
|       - system of "dumping" a given AST or portion of an AST to plain text (build on printAST)                   |
|                                                                                                                  |
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
%token<operator> INDSEL LOGAND LOGOR SHL SHR LTEQ GTEQ EQEQ NOTEQ
        PLUSPLUS MINUSMINUS TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ 
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
%type<astnode_p>function_call 
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
%type<operator> assignment_operator
%type<astnode_p>expression 
                constant_expression

/* Declarations */
%type<astnode_p>declaration_or_fndef 
                function_definition
                compound_statement
                decl_or_stmt_list
                decl_or_stmt
                declaration 
                statement
                declaration_specifiers 
                init_declarator_list 
                init_declarator
                storage_class_specifier 
                type_specifier 
                struct_or_union_specifier
%type<operator> struct_or_union 
%type<astnode_p>struct_declaration_list 
                struct_declaration 
                specifier_qualifier_list 
                struct_declarator_list 
                struct_declarator  
%type<operator> type_qualifier
%type<astnode_p>function_specifier 
                declarator 
                direct_declarator 
                pointer 
                type_qualifier_list
                type_name 
                abstract_declarator 
                direct_abstract_declarator 
                typedef_name
                initializer
%left <operator> ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%right <operator> '?' ":"
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
start: declaration_or_fndef
    | start declaration_or_fndef
    ; 

/* Expression Grammar */

/*
statement: expression ';' {printAST($1, 0);}
; */

expression: assignment_expression {$$ = $1;}
    | expression ',' assignment_expression {$$ = new_astnode_binop(',', $1, $3);}
    ;

primary_expression: IDENT {$$ = new_astnode_ident(IDENT_NODE, $1.string_literal); 
    }
    | NUMBER {$$ = new_astnode_num(NUMBER_NODE, $1);
    }
    | CHARLIT { 
                struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
                temp->meta = UNSIGNED_INT;
                temp->value.int_val = $1;
                $$ = new_astnode_num(NUMBER_NODE, *temp); 
    }
    | STRING {$$ = new_astnode_string(STRING_NODE, $1.string_literal);
    }
    | '('expression')' {$$ = $2;} 
    ;

postfix_expression: primary_expression {$$ = $1;}
    | postfix_expression '[' expression']' { // E1[E2] is identical to (*((E1)+(E2))) 
                                            union astnode *astnode_temp = new_astnode_binop('+', $1, $3);
                                            $$ = new_astnode_unop('*', astnode_temp);                           
    }
    | function_call {$$ = $1;}
    | postfix_expression '.' IDENT {union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, $3.string_literal);
                                    $$ = new_astnode_binop('.', $1, astnode_ident); 
    }
    | postfix_expression INDSEL IDENT { // E1->E2 is identical to (*E1).E2
                                      union astnode *astnode_temp = new_astnode_unop('*', $1);
                                      union astnode *astnode_ident = new_astnode_ident(IDENT_NODE, $3.string_literal);
                                      $$ = new_astnode_binop('.', astnode_temp, astnode_ident);
    }
    | postfix_expression PLUSPLUS {$$ = new_astnode_unop(PLUSPLUS, $1);}
    | postfix_expression MINUSMINUS {$$ = new_astnode_unop(MINUSMINUS, $1);}
    //| '(' type_name ')' '{' argument_expression_list '}'
    //| '(' type_name ')' '{' argument_expression_list ',' '}'
    ;

function_call: postfix_expression '(' argument_expression_list ')'   {$$ = new_astnode_func($1, $3);} 
    | postfix_expression '(' ')' {$$ = new_astnode_func($1, NULL);}
    ;

argument_expression_list: assignment_expression {
                                                union astnode *head = new_astnode_arg($1);
                                                $$ = init_list(head);
                                                }
    | argument_expression_list ',' assignment_expression {$$ = append_arg($1, $3);}
    ;      

/* type_name: CHAR {
            struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
            temp->meta = UNSIGNED_INT;
            temp->value.int_val = 1;
            $$ = new_astnode_num(NUMBER_NODE, *temp);}
    | INT { 
            struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
            temp->meta = UNSIGNED_INT;
            temp->value.int_val = 1;
            $$ = new_astnode_num(NUMBER_NODE, *temp);}
    | LONG {
            struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
            temp->meta = UNSIGNED_LONG;
            temp->value.int_val = 1;
            $$ = new_astnode_num(NUMBER_NODE, *temp);}
    | DOUBLE {
            struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
            temp->meta = DOUBLE_NUM;
            temp->value.float_val = 1;
            $$ = new_astnode_num(NUMBER_NODE, *temp);}
    | FLOAT {
            struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
            temp->meta = FLOAT_NUM;
            temp->value.float_val = 1;
            $$ = new_astnode_num(NUMBER_NODE, *temp);}
    ; */

unary_operator: '&' {$$ = '&';}
    | '*' {$$ = '*';}
    | '+' {$$ = '+';}
    | '-' {$$ = '-';}
    | '~' {$$ = '~';}
    | '!' {$$ = '!';}
    ;

cast_expression: unary_expression {$$ = $1;}
    | '(' type_name ')' cast_expression {$$ = new_astnode_binop('\0', $2, $4);} // I do not know how to handle this
    ; 

unary_expression: postfix_expression {$$ = $1;}
    | PLUSPLUS unary_expression { 
                                union astnode* one = astnode_one();
                                $$ = new_astnode_binop(PLUSEQ, $2, one);
    } 
    | MINUSMINUS unary_expression { 
                                union astnode* one = astnode_one();
                                $$ = new_astnode_binop(MINUSEQ, $2, one);
    }
    | unary_operator cast_expression {$$ = new_astnode_unop($1, $2);}
    | SIZEOF unary_expression {$$ = new_astnode_unop(SIZEOF, $2);}
    | SIZEOF '(' type_name ')' {$$ = new_astnode_unop(SIZEOF, $3);} 
    ;

multiplicative_expression: cast_expression {$$ = $1;}
    | multiplicative_expression '*' cast_expression {$$ = new_astnode_binop('*', $1, $3);} 
    | multiplicative_expression '/' cast_expression {$$ = new_astnode_binop('/', $1, $3);}
    | multiplicative_expression '%' cast_expression {$$ = new_astnode_binop('%', $1, $3);}
    ;

additive_expression: multiplicative_expression {$$ = $1;}
    | additive_expression '+' multiplicative_expression {$$ = new_astnode_binop('+', $1, $3);} 
    | additive_expression '_' multiplicative_expression {$$ = new_astnode_binop('-', $1, $3);} 
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
    | AND_expression '&' equality_expression {$$ = new_astnode_binop('&', $1, $3);}
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

constant_expression: conditional_expression; 

/* Declarations Grammar */
declaration_or_fndef: declaration  {printAST($1, 0);}
    | function_definition
    ;

function_definition: declaration_specifiers declarator compound_statement ';' {printAST($1, 0);}
    ;

compound_statement: '{' decl_or_stmt_list '}'
    ;

decl_or_stmt_list: decl_or_stmt  {$$ = $1;}
    | decl_or_stmt_list ',' decl_or_stmt
    ;

decl_or_stmt: declaration  {$$ = $1;}
    | statement  {$$ = $1;}
    ;

declaration: declaration_specifiers ';' {$$ = $1;}
    | declaration_specifiers init_declarator_list ';'
    ;

statement: compound_statement {$$ = $1;}
    | expression ';' 
    ;

declaration_specifiers: storage_class_specifier 
    | storage_class_specifier declaration_specifiers
    | type_specifier {$$ = new_astnode_declaration_spec(DECSPEC_NODE, $1, NONE_TYPE);}
    | type_specifier declaration_specifiers 
    | type_qualifier {$$ = new_astnode_declaration_spec(DECSPEC_NODE, UNKNOWN_TYPE, $1);}
    | type_qualifier declaration_specifiers
    | function_specifier 
    | function_specifier declaration_specifiers
    ;

init_declarator_list: init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator: declarator
    | declarator '=' initializer
    ;

storage_class_specifier: TYPEDEF {$$ = TYPEDEF;}
    | EXTERN {$$ = EXTERN;}
    | STATIC {$$ = STATIC;}
    | AUTO {$$ = AUTO;}
    | REGISTER {$$ = REGISTER;}
    ;

type_specifier: VOID {$$ = new_astnode_scalar(SCALAR_NODE, VOID_TYPE);}
    | CHAR {$$ = new_astnode_scalar(SCALAR_NODE, CHAR_TYPE);} 
    | SHORT {$$ = new_astnode_scalar(SCALAR_NODE, SHORT_TYPE);}
    | INT {$$ = new_astnode_scalar(SCALAR_NODE, INT_TYPE);}
    | LONG {$$ = new_astnode_scalar(SCALAR_NODE, LONG_TYPE);}
    | FLOAT {$$ = new_astnode_scalar(SCALAR_NODE, FLOAT_TYPE);}
    | DOUBLE {$$ = new_astnode_scalar(SCALAR_NODE, DOUBLE_TYPE);}
    | SIGNED {$$ = new_astnode_scalar(SCALAR_NODE, SIGNED_TYPE);}
    | UNSIGNED {$$ = new_astnode_scalar(SCALAR_NODE, UNSIGNED_TYPE);}
    | _BOOL {$$ = new_astnode_scalar(SCALAR_NODE, BOOL_TYPE);} 
    //| _COMPLEX {}
    | struct_or_union_specifier 
    /*| enum_specifier */
    /*| typedef_name */
    ;

struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}' 
    | struct_or_union IDENT 
    | struct_or_union IDENT '{' struct_declaration_list '}'
    ;

struct_or_union: STRUCT
    | UNION
    ;

struct_declaration_list: struct_declaration 
    | struct_declaration_list struct_declaration 
    ;

struct_declaration: specifier_qualifier_list ';'
    specifier_qualifier_list struct_declarator_list ';'
    ;

specifier_qualifier_list: type_specifier
    | type_specifier specifier_qualifier_list
    | type_qualifier 
    | type_qualifier specifier_qualifier_list
    ;

struct_declarator_list: struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

struct_declarator: declarator
    ;

type_qualifier: CONST {$$ = CONST_TYPE;}
    | RESTRICT {$$ = RESTRICT_TYPE;}
    | VOLATILE {$$ = VOLATILE_TYPE;}
    ;

function_specifier: INLINE
    ;

declarator: direct_declarator
    | pointer direct_declarator
    ;

direct_declarator: IDENT {$$ = new_symbol($1.string_literal);} 
    | '(' declarator ')' {$$ = $2;}
    //| direct_declarator '[' assignment_expression ']'
    //| direct_declarator '[' type_qualifier_list assignment_expression ']'
    //| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' 
    //| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' 
    //| direct_declarator '[' type_qualifier_list '*' ']'
    //| direct_declarator '(' parameter_type_list ')'
    //| direct_declarator '(' identifier_list ')'
    | direct_declarator '[' ']'
    | direct_declarator '[' NUMBER ']'
    | direct_declarator '(' ')'
    ;

pointer: '*' {$$ = new_astnode_pointer(POINTER_NODE, NULL, NULL);}
    | '*' type_qualifier_list {$$ = new_astnode_pointer(POINTER_NODE, $2, NULL);}
    | '*' pointer {$$ = new_astnode_pointer(POINTER_NODE, NULL, $2);}
    | '*' type_qualifier_list pointer {$$ = new_astnode_pointer(POINTER_NODE, $2, $3);}
    ;

type_qualifier_list: type_qualifier {$$ = new_astnode_declaration_spec(DECSPEC_NODE, UNKNOWN_TYPE, $1);}
    | type_qualifier_list type_qualifier
    ;

type_name: specifier_qualifier_list                       
         | specifier_qualifier_list abstract_declarator      
         ; 

/* 
parameter_type_list: parameter_list
    | parameter_list ',' 
    ;

parameter_list: parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration: declaration_specifiers  
    | declaration_specifiers declarator
    | declaration_specifiers abstract_declarator
    ;

identifier_list: IDENT
    | identifier_list ',' IDENT
    ; */

abstract_declarator: pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator: '(' abstract_declarator ')' {$$ = $2;}
    | '[' ']' {$$ = new_astnode_array(ARRAY_NODE, NULL, 0);}
    | direct_abstract_declarator '[' ']' {$$ = new_astnode_array(ARRAY_NODE, $1, 0);}
    | '[' NUMBER ']' {$$ = new_astnode_array(ARRAY_NODE, NULL, $2.value.int_val);}
    | direct_abstract_declarator '[' NUMBER ']' {$$ = new_astnode_array(ARRAY_NODE, $1, $3.value.int_val);}
    | '(' ')'
    | direct_abstract_declarator '(' ')'
    // | '[' assignment_expression ']' 
    // | direct_abstract_declarator '[' assignment_expression ']' 
    // | '[' '*' ']' 
    // | direct_abstract_declarator '[' '*' ']' 
    // | '(' parameter_type_list ')'
    // | direct_abstract_declarator '(' parameter_type_list ')'
    ;

typedef_name: IDENT;

initializer: assignment_expression
   // | '{' initializer_list '}' 
   // | '{' initializer_list ',' '}'
    ;

/* initializer_list: initializer
    | designation initializer
    | initializer_list ',' initializer 
    | initializer_list ',' designation initializer 
    ;

designation: designator_list '=';
designator_list: designator
    | designator_list designator
    ;

designator: '[' constant_expression ']'
    | '.' IDENT
    ;
 */


%%

void printIndents(int indent){
    for (int i = 0; i < indent; i++){
        printf("\t");
    }
}

void printBinop(int operator){
    if(operator == '=') {
        printf("ASSIGNMENT\n"); 
    } else if(operator >= 263 && operator <= 264){
        printf("LOGICAL OP ");
    } else if(operator >= 265 && operator <= 266){
        printf("BINARY OP ");
    } else if(operator >= 267 && operator <= 270){
        printf("COMPARISON OP ");
    } else if(operator >= 271 && operator <= 282){
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
            printf("<<\n");
            break;
        case SHR:
            printf(">>\n");
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
            case(UNSIGNED_INT):
            case(SIGNED_INT):
                printf("int)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(UNSIGNED_LONG):
            case(SIGNED_LONG):
                printf("long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(UNSIGNED_LONGLONG):
            case(SIGNED_LONGLONG):
                printf("long long)");
                printf("%lld\n", numInfo.value.int_val);
                break;
            case(DOUBLE_NUM):
                printf("double)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(FLOAT_NUM):
                printf("float)");
                if (numInfo.value.float_val >= 10) {
                    printf("%.2Le\n", numInfo.value.float_val);
                } else {
                    printf("%.2Lf\n", numInfo.value.float_val);
                }
                break;
            case(LONG_DOUBLE):
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
    int count = 1; 
    printIndents(indent);

    switch(node->generic.type){
        case UNOP_NODE: 
            if (node->unop.operator == SIZEOF) {
                printf("SIZEOF\n");
            } else if (node->unop.operator == '&') {
                printf("ADDRESSOF\n");
            } else if (node->unop.operator == '*') {
                printf("DEREF\n");
            } else if (node->unop.operator == PLUSPLUS) {
                printf("UNARY OP POSTINC\n");
            } else if (node->unop.operator == MINUSMINUS) {
                printf("UNARY OP POSTDEC\n");
            } else{
                printf("UNARY OP %c\n", node->unop.operator);
            }
            printAST(node->unop.operand, indent+1); 
            break;
        case BINOP_NODE:
            if ((node->binop.operator >= LOGAND && node->binop.operator <= XOREQ) || node->binop.operator == '=') {
                printBinop(node->binop.operator); 
            } else if (node->binop.operator == '.') {
                if ((node->binop.left)->unop.operator && (node->binop.left)->unop.operator == '*') {
                    printf("INDIRECT SELECT, member %s\n", (node->binop.right)->id.ident);
                    printAST((node->binop.left)->unop.operand, indent+1);  
                } else {
                    printf("SELECT, member %s\n", (node->binop.right)->id.ident);
                    printAST(node->binop.left, indent+1);  
                }
                break;
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
            printf("STRING\t%s\n", node->str.string_literal);
            break;
        case ARGLIST_NODE:
            printIndents(indent + 1);
            printf("arg #%d=\n", count);
            printAST((node->list.arg_head)->arg.argument, indent+1);
            while(node->list.arg_next != NULL) {
                printIndents(indent + 1);
                printf("arg #%d=\n", ++count);
                printAST((node->list.arg_next)->arg.argument, indent+1);
                node = node->list.arg_next;
            }
            break;
        case FUNCTION_NODE:
            printf("FNCALL, %d arguments\n", node->func.num_args);
            printAST(node->func.function_name, indent+1);
            if (node->func.arg_head) {
                printAST(node->func.arg_head, indent-1);
            }
            break;
        case ARGUMENT_NODE:
        case SCALAR_NODE:
            printf("SCALAR DECLARATION, TYPE: %d\n", node->scalar.scalarType);
            break; 
        case POINTER_NODE:
            printf("pointer to\n");
            printAST(node->ptr.parent, indent+1);
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
