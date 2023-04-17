/*-----------------------------------------------------------------------------------------------------------------\
|      TO DO:                                                                                                      |       
|      - Fix bug where info gets lost if declared within function scope                                            |
|      - Clean up printing situation                                                                               |
|      - Clean up dec spec merging                                                                                 |
|                                                                                                                  |
\-----------------------------------------------------------------------------------------------------------------*/

/* Prologue */
%{
int yylex();
void yyerror(char *s);
%}

%code requires {
    #include "symtable.h"
}

/* YYSTYPE union */
%union { 
    struct numinfo numInfo;
    struct stringinfo stringInfo; 
    char char_literal; 
    union astnode *astnode_p; 
    int operator; 
    symbol *symbol_p;
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
%type<symbol_p> declaration_or_fndef 
%type<symbol_p> function_definition
%type<astnode_p>compound_statement
%type<astnode_p> decl_or_stmt_list
%type<astnode_p> decl_or_stmt
%type<symbol_p> declaration 
%type<astnode_p>statement
%type<astnode_p>declaration_specifiers 
%type<symbol_p> init_declarator_list 
%type<symbol_p> init_declarator
%type<astnode_p>storage_class_specifier 
%type<astnode_p>type_specifier 
%type<astnode_p> struct_or_union_specifier
%type<astnode_p>struct_or_union 
%type<astnode_p>struct_declaration_list 
                struct_declaration 
                specifier_qualifier_list 
                struct_declarator_list 
%type<symbol_p> struct_declarator  
%type<astnode_p>type_qualifier
%type<astnode_p>function_specifier 
                parameter-type-list
                parameter-list
                parameter-declaration
%type<symbol_p>declarator 
%type<symbol_p>direct_declarator 
%type<astnode_p>pointer 
%type<astnode_p>type_qualifier_list
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

primary_expression: IDENT {$$ = new_astnode_ident(IDENT_NODE, $1.string_literal);}
    | NUMBER {$$ = new_astnode_num(NUMBER_NODE, $1);}
    | CHARLIT { 
                struct numinfo *temp = (struct numinfo*) malloc(sizeof (struct numinfo));
                temp->meta = UNSIGNED_INT;
                temp->value.int_val = $1;
                $$ = new_astnode_num(NUMBER_NODE, *temp); 
              }
    | STRING {$$ = new_astnode_string(STRING_NODE, $1.string_literal);}
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
declaration_or_fndef: declaration { 
                                    union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, $1);
                                    if (ptr->sym_p.sym->sym_type == FUNCTION_SYMBOL) {
                                        // create function def node
                                        union astnode *fn_type = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                        
                                        if ($1->type_rep && $1->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                            union astnode *temp = $1->type_rep;
                                            while (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == FUNCTION_DEF_NODE) { // if ret type of function is function
                                                temp = temp->fndef.ret_type;
                                            }
                                            if (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == POINTER_NODE) { // if ret type of function is pointer
                                               // assume only one pointer to function is allowed
                                               if (temp->fndef.ret_type->ptr.parent && temp->fndef.ret_type->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if pointer points to function
                                                    temp->fndef.ret_type->ptr.parent->fndef.ret_type = $1->dec_specs;
                                               } else { // if pointer does not point to function, assume it points to scalar
                                                    temp->fndef.ret_type->ptr.parent = $1->dec_specs;
                                               }
                                            } else if (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == ARRAY_NODE) { // if ret type of function is array
                                                    temp->fndef.ret_type->arr.element_type = $1->dec_specs; // set element type to dec specs
                                            } else {
                                                temp->fndef.ret_type = $1->dec_specs; // set return type of innermost function to dec specs
                                            }
                                            // set the ret_type = fnc def node
                                            (fn_type->fndef).ret_type = $1->type_rep;
                                // -------------------------------------------------------------------------------------------- for visual ease            
                                        } else if ($1->type_rep && $1->type_rep->generic.type == ARRAY_NODE) { 
                                            union astnode *temp = $1->type_rep;
                                            while (temp->arr.element_type) { // if element type of array is array
                                                temp = $1->type_rep->arr.element_type;
                                            }
                                            temp->arr.element_type = $1->dec_specs; // set element type of innermost array to dec specs
                                            //change the fndef.ret_type = array node
                                            (fn_type->fndef).ret_type = $1->type_rep; 
                                            // change astnode type to function def
                                            add_astnode_to_symbol($1, fn_type);
                                 // -------------------------------------------------------------------------------------------- for visual ease       
                                        } else if ($1->type_rep && $1->type_rep->generic.type == POINTER_NODE) {
                                            union astnode *temp = $1->type_rep;
                                            while (temp->ptr.parent && (temp->ptr.parent->generic.type == POINTER_NODE)) { // if parent of pointer is a pointer
                                                temp = $1->type_rep->ptr.parent;
                                            }
                                            if (temp->ptr.parent && temp->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if type is pointer to ... function, set ret type
                                                temp->ptr.parent->fndef.ret_type = $1->dec_specs;
                                            } else {
                                                temp->ptr.parent = $1->dec_specs; // set parent type of innermost pointer to dec specs
                                            }
                                            //change the fndef.ret_type = pointer node
                                            (fn_type->fndef).ret_type = $1->type_rep; 
                                            // change astnode type to function def
                                            add_astnode_to_symbol($1, fn_type);
                                     // -------------------------------------------------------------------------------------------- for visual ease    
                                        } else {
                                            // set ret type of fn_type to dec specs if astnode type is not already set
                                            (fn_type->fndef).ret_type = $1->dec_specs;
                                            // change astnode type to function def
                                            add_astnode_to_symbol($1, fn_type);
                                        }
                                    /* JUST A DECLARATION NOT FUNCTION DECLARATION */ 
                                    } else {
                                        // if array, make element type the decspec 
                                        if ($1->type_rep && $1->type_rep->generic.type == ARRAY_NODE) {
                                            union astnode *temp = $1->type_rep;
                                            while (temp->arr.element_type) { // if element type of array is array
                                                temp = $1->type_rep->arr.element_type;
                                            }
                                            temp->arr.element_type = $1->dec_specs; // set element type of innermost array to dec specs
                                        } else if ($1->type_rep && $1->type_rep->generic.type == POINTER_NODE) {
                                            union astnode *temp = $1->type_rep;
                                            while (temp->ptr.parent && (temp->ptr.parent->generic.type == POINTER_NODE)) { // if parent of pointer is a pointer
                                                temp = $1->type_rep->ptr.parent;
                                            }
                                            if (temp->ptr.parent && temp->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if type is pointer to ... function, set ret type
                                                temp->ptr.parent->fndef.ret_type = $1->dec_specs;
                                            } else {
                                                temp->ptr.parent = $1->dec_specs; // set parent type of innermost pointer to dec specs
                                            }
                                        } else if ($1->type_rep && $1->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                            union astnode *temp = $1->type_rep;
                                            while (temp->fndef.ret_type) { // if ret type of function is function
                                                temp = $1->type_rep->fndef.ret_type;
                                            }
                                            temp->fndef.ret_type = $1->dec_specs; // set return type of innermost function to dec specs
                                        }
                                    }
                                    /*printf("ret type is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                    printf("pointer parent is %d\n", $1->type_rep->fndef.ret_type->ptr.parent->generic.type);
                                    printf("ret type of pointed is %d\n", $1->type_rep->fndef.ret_type->ptr.parent->fndef.ret_type->generic.type);
                                    */
                                    printAST(ptr, 0);
                                  }
    | function_definition {} // 
    ;

function_definition: declaration_specifiers declarator  { 
                                                            if (!current->scope_fileName) {
                                                                current->scope_fileName = report.fileName;
                                                            }
                                                            modify_symbol_type($2, FUNCTION_SYMBOL);

                                                            // add decspecs to declaration symbol
                                                            symbol *temp = add_astnode_to_symbol($2, $1);
                                                            
                                                            if ($1->decspec.s_class == UNKNOWN_CLASS) {
                                                                $1->decspec.s_class = EXTERN_CLASS;
                                                            }

                                                            // create function def node
                                                            union astnode *fn_type = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);

                                                            if ($2->type_rep && $2->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                                                union astnode *temp = $2->type_rep;
                                                                while (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == FUNCTION_DEF_NODE) { // if ret type of function is function
                                                                    temp = temp->fndef.ret_type;
                                                                }
                                                                if (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == POINTER_NODE) { // if ret type is pointer
                                                                // assume only one pointer to function is allowed
                                                                if (temp->fndef.ret_type->ptr.parent && temp->fndef.ret_type->ptr.parent->generic.type == FUNCTION_DEF_NODE) {
                                                                        temp->fndef.ret_type->ptr.parent->fndef.ret_type = $2->dec_specs;
                                                                } else {
                                                                        temp->fndef.ret_type->ptr.parent = $2->dec_specs;
                                                                }
                                                                } else {
                                                                    temp->fndef.ret_type = $2->dec_specs; // set return type of innermost function to dec specs
                                                                }
                                                                // set the ret_type = fnc def node
                                                                (fn_type->fndef).ret_type = $2->type_rep;
                                                // -------------------------------------------------------------------------------------------- for visual ease
                                                            } else if ($2->type_rep && $2->type_rep->generic.type == ARRAY_NODE) { 
                                                                union astnode *temp = $2->type_rep;
                                                                while (temp->arr.element_type) { // if element type of array is array
                                                                    temp = $2->type_rep->arr.element_type;
                                                                }
                                                                temp->arr.element_type = $2->dec_specs; // set element type of innermost array to dec specs
                                                                //change the fndef.ret_type = array node
                                                                (fn_type->fndef).ret_type = $2->type_rep; 
                                                                // change astnode type to function def
                                                                add_astnode_to_symbol($2, fn_type);
                                                // -------------------------------------------------------------------------------------------- for visual ease            
                                                            } else if ($2->type_rep && $2->type_rep->generic.type == POINTER_NODE) {
                                                                union astnode *temp = $2->type_rep;
                                                                while (temp->ptr.parent && (temp->ptr.parent->generic.type == POINTER_NODE)) { // if parent of pointer is a pointer
                                                                    temp = $2->type_rep->ptr.parent;
                                                                }
                                                                if (temp->ptr.parent && temp->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if type is pointer to ... function, set ret type
                                                                    temp->ptr.parent->fndef.ret_type = $2->dec_specs;
                                                                } else {
                                                                    temp->ptr.parent = $2->dec_specs; // set parent type of innermost pointer to dec specs
                                                                }
                                                                //change the fndef.ret_type = pointer node
                                                                (fn_type->fndef).ret_type = $2->type_rep; 
                                                                // change astnode type to function def
                                                                add_astnode_to_symbol($2, fn_type);
                                                 // -------------------------------------------------------------------------------------------- for visual ease
                                                            } else {
                                                                // set ret type of fn_type to dec specs if astnode type is not already set
                                                                (fn_type->fndef).ret_type = $2->dec_specs;
                                                                // change astnode type to function def
                                                                add_astnode_to_symbol($2, fn_type);
                                                            }

                                                            // if inserting symbol was successful
                                                            if (!insert_symbol(current->symbolTables[OTHER], temp)) {
                                                                // ERROR
                                                               fprintf(stderr, "Error: Symbol for ident %s declared in %s:%d, was not inserted into symbol table\n", temp->key, report.fileName, report.lineNum); 
                                                            }
                                                            // create astnode ptr that contains a pointer to the symbol (for printing purposes)
                                                            union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, temp);
                                                            printAST(ptr, 0);
                                                            
                                                        }
     compound_statement {$$ = $4;}
    ;

compound_statement: '{' {                 
                            if (current->name == FUNCTION_SCOPE) {
                                if (!push_scope(BLOCK_SCOPE)) { // if push_scope returns 0 -> ERROR
                                fprintf(stderr, "Error: Cannot create block scope. Current scope is %d\n", current->name);
                                }
                            } else {
                                if (!push_scope(FUNCTION_SCOPE)) { // if push_scope returns 0 -> ERROR
                                    fprintf(stderr, "Error: Cannot create function scope. Current scope is %d\n", current->name);
                                }
                            }
                        }
    '}' { pop_scope(); }
| '{' {                 
        if (current->name == FUNCTION_SCOPE) {
            if (!push_scope(BLOCK_SCOPE)) { // if push_scope returns 0 -> ERROR
            fprintf(stderr, "Error: Cannot create block scope. Current scope is %d\n", current->name);
            }
        } else {
            if (!push_scope(FUNCTION_SCOPE)) { // if push_scope returns 0 -> ERROR
                fprintf(stderr, "Error: Cannot create function scope. Current scope is %d\n", current->name);
            }
        }
      }
    decl_or_stmt_list '}' {
                            $$ = $3;
                            pop_scope();
                          }
    ;


decl_or_stmt_list: decl_or_stmt  {$$ = $1;}
    | decl_or_stmt_list decl_or_stmt {append_astnode_list($1, $2);}
    ;

decl_or_stmt: declaration  {$$ = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, $1);}
    | statement {$$ = $1;}
    ;

declaration: declaration_specifiers ';' 
    | declaration_specifiers init_declarator_list ';' {  
                                                        if (!current->scope_fileName) { // if fileName is not set, set it to report.fileName
                                                            current->scope_fileName = report.fileName;
                                                        }
                                                        
                                                        // add decspecs to declaration symbol
                                                        symbol *temp = add_astnode_to_symbol($2, $1);

                                                        if ($1->decspec.s_class == UNKNOWN_CLASS) {
                                                            if (current->name == FUNCTION_SCOPE) {
                                                                $1->decspec.s_class = AUTO_CLASS;
                                                            } else {
                                                                $1->decspec.s_class = EXTERN_CLASS;
                                                            }
                                                        }
                                                        
                                                        if ($1->decspec.s_type) {
                                                            if ($1->decspec.s_type->scalar.scalarType == SIGNED_TYPE || $1->decspec.s_type->scalar.scalarType == UNSIGNED_TYPE) {
                                                                if ((!($1->decspec.prev) && !($1->decspec.next))) { // if the dec spec is ONLY signed or unsigned
                                                                    union astnode *int_type = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                                                                    int_type = new_astnode_declaration_spec(DECSPEC_NODE, int_type, NONE_TYPE, UNKNOWN_CLASS);
                                                                    append_astnode_list($1, int_type);
                                                                }
                                                            }
                                                        } else {
                                                            if ($1->decspec.q_type) {
                                                                union astnode *int_type = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                                                                modify_astnode_declaration_spec($1, int_type, NONE_TYPE, UNKNOWN_CLASS);
                                                            }
                                                        }
                                                        
                                                        //printf("ret type of func is %d\n", $2->type_rep->fndef.ret_type->generic.type);

                                                        if (!insert_symbol(current->symbolTables[OTHER], temp)) {
                                                            // ERROR
                                                            fprintf(stderr, "Error: Symbol for ident %s declared in %s:%d, was not inserted into symbol table\n", temp->key, report.fileName, report.lineNum); 
                                                            temp = contains_symbol(current->symbolTables[OTHER], temp->key);
                                                        }

                                                       if (current->name == FUNCTION_SCOPE || current->name == BLOCK_SCOPE) {
                                                            union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, temp);
                                                            printAST(ptr, 0);
                                                        }

                                                        $$ = temp;
                                                      }
    ;

statement: compound_statement {$$ = $1;}
    | expression ';' {printAST($1, 0);}
    ;

declaration_specifiers: storage_class_specifier {$$ = $1;}
    | storage_class_specifier declaration_specifiers { 
                                                        if ($2->decspec.s_class) { // if there is another storage class declared
                                                            fprintf(stderr, "Error: cannot have declaration with more than one storage class\n");
                                                        } else {
                                                            // Note: if there are already s_class and s_type, fields do not get overwritten
                                                            $$ = modify_astnode_declaration_spec($2, NULL, NONE_TYPE, $1->decspec.s_class); // the second decspec node is returned because we want to continue parsing dec specs
                                                        }
                                                    }
    | type_specifier {$$ = $1;}
    | type_specifier declaration_specifiers {
                                                append_astnode_list($1, $2); 
                                                if ($1->decspec.prev) { // if first in list
                                                    $$ = $1;
                                                }
                                            }
    | type_qualifier {$$ = $1;} 
    | type_qualifier declaration_specifiers {
                                                if ($2->decspec.s_type) {
                                                    $$ = modify_astnode_declaration_spec($2, NULL, $1->decspec.q_type, UNKNOWN_CLASS); // see note above
                                                } else if ($2->decspec.s_class) { 
                                                    fprintf(stderr, "Error:  must declare storage class before type qualifier\n");
                                                } else if ($2->decspec.q_type) {
                                                    fprintf(stderr, "Error:  more than one type qualifier not implemented\n");
                                                }
                                            }
    | function_specifier                        // *** Optional -- Not Implemented ***
    | function_specifier declaration_specifiers // *** Optional -- Not Implemented ***
    ;

init_declarator_list: init_declarator {$$ = $1;}
    | init_declarator_list ',' init_declarator {$$ = append_symbol_list($1, $3);}
    ;

init_declarator: declarator {$$ = $1;}
    | declarator '=' initializer // *** Optional -- Not Implemented ***
    ;

storage_class_specifier: TYPEDEF {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, TYPEDEF_CLASS);}
    | EXTERN {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, EXTERN_CLASS);}
    | STATIC {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, STATIC_CLASS);}
    | AUTO {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, AUTO_CLASS);}
    | REGISTER {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, NONE_TYPE, REGISTER_CLASS);}
    ;

type_specifier: VOID {
                        union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, VOID_TYPE);
                        $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
                     }
    | CHAR {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, CHAR_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
            } 
    | SHORT {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, SHORT_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
            }
    | INT { 
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, INT_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
           }
    | LONG {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, LONG_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS); 
           }
    | FLOAT {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, FLOAT_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
            }
    | DOUBLE {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, DOUBLE_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
             }
    | SIGNED {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, SIGNED_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
             }
    | UNSIGNED {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, UNSIGNED_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
               }
    | _BOOL {
                union astnode *type_spec = new_astnode_scalar(SCALAR_NODE, BOOL_TYPE);
                $$ = new_astnode_declaration_spec(DECSPEC_NODE, type_spec, NONE_TYPE, UNKNOWN_CLASS);
            } 
    //| _COMPLEX 
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

specifier_qualifier_list: type_specifier {$$ = $1;}
    | type_specifier specifier_qualifier_list {
                                                append_astnode_list($1, $2);
                                                if ($1->decspec.prev) { // if first in list
                                                    $$ = $1;
                                                }
                                              }
    | type_qualifier {$$ = $1;}
    | type_qualifier specifier_qualifier_list {
                                                append_astnode_list($1, $2);
                                                if ($1->decspec.prev) { // if first in list
                                                    $$ = $1;
                                                }
                                              }
    ;

struct_declarator_list: struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

struct_declarator: declarator {$$ = $1;}
    ;

type_qualifier: CONST {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, CONST_TYPE, UNKNOWN_CLASS);}
    | RESTRICT {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, RESTRICT_TYPE, UNKNOWN_CLASS);}
    | VOLATILE {$$ = new_astnode_declaration_spec(DECSPEC_NODE, NULL, VOLATILE_TYPE, UNKNOWN_CLASS);}
    ;

function_specifier: INLINE // *** Optional -- Not Implemented ***
    ;

declarator: direct_declarator {$$ = $1;}
    | pointer direct_declarator {$$ = add_astnode_to_symbol($2, $1);}
    ;

direct_declarator: IDENT { //symbol type defaults to VARIABLE
                            if (!report.lineNum) { 
                                report.lineNum++; // bc lineNum starts off as 0
                            }
                            $$ = new_symbol($1.string_literal, OTHER, NULL, NULL, VARIABLE_SYMBOL);
                          } 
    | '(' declarator ')' {
                            if ($2->type_rep && $2->type_rep->generic.type == POINTER_NODE) {
                                union astnode *parent = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL); // this is not always the case -- BAD
                                union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, $2->type_rep); // set ret type of function to be pointer
                                $2->type_rep->ptr.parent = parent; // change ptr to point to fndef of unknown ret type
                                $2->type_rep = ptr; // change symbol type_rep to be fndef returning ptr to fndef
                            } else if ($2->type_rep && $2->type_rep->generic.type == ARRAY_NODE) {
                                union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, $2->type_rep); // set ret type of function to be pointer
                                ptr->fndef.ret_type = $2->type_rep; // set return type = array
                                $2->type_rep = ptr; // change symbol type_rep to be fndef returning an array
                            }
                            $$ = $2;
                        
                        }
    //| direct_declarator '[' assignment_expression ']'                                             // *** Optional -- Not Implemented ***
    //| direct_declarator '[' type_qualifier_list assignment_expression ']'                         // *** Optional -- Not Implemented ***
    //| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'                  // *** Optional -- Not Implemented ***
    //| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'                  // *** Optional -- Not Implemented ***
    //| direct_declarator '[' type_qualifier_list '*' ']'                                           // *** Optional -- Not Implemented ***
    | direct_declarator '(' parameter-type-list')' {                                                // *** Optional -- Not Implemented ***
                                                        union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                                        if ($1->type_rep && $1->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                                            modify_astnode_fndef($1->type_rep, NULL, ptr);
                                                            //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                                        } else if ($1->type_rep && $1->type_rep->generic.type == POINTER_NODE) {
                                                            ptr->fndef.ret_type = $1->type_rep; //set return type of function to pointer
                                                            add_astnode_to_symbol($1, ptr); // set function as symbol type_rep
                                                        } else {
                                                            add_astnode_to_symbol($1, ptr);
                                                        }

                                                        symbol *sym; 
                                                        if ($1->sym_type == VARIABLE_SYMBOL) {
                                                            sym = modify_symbol_type($1, FUNCTION_SYMBOL);
                                                        } 
                                                        $$ = sym;
                                                    }  
    | direct_declarator '(' identifier-list ')' { // *** Optional -- Not Implemented ***
                                                    union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                                    if ($1->type_rep && $1->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                                        modify_astnode_fndef($1->type_rep, NULL, ptr);
                                                        //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                                    } else if ($1->type_rep && $1->type_rep->generic.type == POINTER_NODE) {
                                                        ptr->fndef.ret_type = $1->type_rep; //set return type of function to pointer
                                                        add_astnode_to_symbol($1, ptr); // set function as symbol type_rep
                                                    } else {
                                                        add_astnode_to_symbol($1, ptr);
                                                    }

                                                    symbol *sym; 
                                                    if ($1->sym_type == VARIABLE_SYMBOL) {
                                                        sym = modify_symbol_type($1, FUNCTION_SYMBOL);
                                                    } 
                                                    $$ = sym;
                                                }     
    | direct_declarator '[' ']' {
                                    union astnode *arr = new_astnode_array(ARRAY_NODE, $1->dec_specs, -1); // -1 = no size specified
                                    if ($1->type_rep && $1->type_rep->generic.type == ARRAY_NODE) { 
                                        $1->type_rep->arr.element_type = arr;
                                        $$ = $1;
                                    } else {
                                        $$ = add_astnode_to_symbol($1, arr);
                                    }
                                }
    | direct_declarator '[' NUMBER ']' {
                                            union astnode *arr = new_astnode_array(ARRAY_NODE, $1->dec_specs, $3.value.int_val);
                                            if ($1->type_rep && $1->type_rep->generic.type == ARRAY_NODE) { 
                                                $1->type_rep->arr.element_type = arr;
                                                $$ = $1;
                                            } else {
                                                $$ = add_astnode_to_symbol($1, arr);
                                            }
                                       }
    | direct_declarator '(' ')' {   
                                    union astnode *ptr = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
                                    if ($1->type_rep && $1->type_rep->generic.type == FUNCTION_DEF_NODE) {
                                        modify_astnode_fndef($1->type_rep, NULL, ptr);
                                        //printf("ret type of func is %d\n", $1->type_rep->fndef.ret_type->generic.type);
                                    } else if ($1->type_rep && $1->type_rep->generic.type == POINTER_NODE) {
                                        ptr->fndef.ret_type = $1->type_rep; //set return type of function to pointer
                                        add_astnode_to_symbol($1, ptr); // set function as symbol type_rep
                                    } else {
                                        add_astnode_to_symbol($1, ptr);
                                    }

                                    symbol *sym; 
                                    if ($1->sym_type == VARIABLE_SYMBOL) {
                                        sym = modify_symbol_type($1, FUNCTION_SYMBOL);
                                    } 
                                    $$ = sym;
                                }
    ;

pointer: '*' {$$ = new_astnode_pointer(POINTER_NODE, NULL, NULL);}
    | '*' type_qualifier_list {$$ = new_astnode_pointer(POINTER_NODE, $2, NULL);}
    | '*' pointer {$$ = new_astnode_pointer(POINTER_NODE, NULL, $2);}
    | '*' type_qualifier_list pointer {$$ = new_astnode_pointer(POINTER_NODE, $2, $3);}
    ;

type_qualifier_list: type_qualifier {$$ = $1;}
    | type_qualifier_list type_qualifier  // *** Optional -- Not Implemented ***
    ;

parameter-type-list: parameter-list {$$ = $1;}
    | parameter-list ',' ELLIPSIS
    ;

parameter-list: parameter-declaration {$$ = $1;}
    | parameter-list ',' parameter-declaration
    ;

parameter-declaration: declaration_specifiers declarator {  // add decspecs to declarator symbol
                                                            symbol *temp = add_astnode_to_symbol($2, $1);
                                                            union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, temp);
                                                            $$ = ptr;
                                                         }
    | declaration_specifiers abstract_declarator {
                                                       if ($2->generic.type == FUNCTION_DEF_NODE) {
                                                          // function
                                                       } else if ($2->generic.type == ARRAY_NODE) {
                                                          union astnode *node_ptr = modify_astnode_array($2, $1);
                                                          $$ = node_ptr;
                                                       }
                                                    }      
    | declaration_specifiers
    ;

identifier-list: IDENT
    | identifier-list ',' IDENT
    ;

type_name: specifier_qualifier_list {$$ = $1;}                    
    | specifier_qualifier_list abstract_declarator {
                                                       if ($2->generic.type == FUNCTION_DEF_NODE) {
                                                          // function
                                                       } else if ($2->generic.type == ARRAY_NODE) {
                                                          union astnode *node_ptr = modify_astnode_array($2, $1);
                                                          $$ = node_ptr;
                                                       }
                                                    }      
    ; 

abstract_declarator: pointer {$$ = $1;}
    | direct_abstract_declarator {$$ = $1;}
    | pointer direct_abstract_declarator 
    ;

direct_abstract_declarator: '(' abstract_declarator ')' {$$ = $2;}
    | '[' ']'                                           {$$ = new_astnode_array(ARRAY_NODE, NULL, 0);}
    | direct_abstract_declarator '[' ']'                {$$ = new_astnode_array(ARRAY_NODE, $1, 0);}
    | '[' NUMBER ']'                                    {$$ = new_astnode_array(ARRAY_NODE, NULL, $2.value.int_val);}
    | direct_abstract_declarator '[' NUMBER ']'         {$$ = new_astnode_array(ARRAY_NODE, $1, $3.value.int_val);}
    | '(' ')'                                           {$$ = new_astnode_fndef(FUNCTION_NODE, NULL, NULL);}
    | direct_abstract_declarator '(' ')'                {$$ = new_astnode_fndef(FUNCTION_NODE, NULL, $1);}
    // | '[' assignment_expression ']'                              // *** Optional -- Not Implemented ***
    // | direct_abstract_declarator '[' assignment_expression ']'   // *** Optional -- Not Implemented ***
    // | '[' '*' ']'                                                // *** Optional -- Not Implemented ***
    // | direct_abstract_declarator '[' '*' ']'                     // *** Optional -- Not Implemented ***
    // | '(' parameter_type_list ')'                                // *** Optional -- Not Implemented ***
    // | direct_abstract_declarator '(' parameter_type_list ')'     // *** Optional -- Not Implemented ***
    ;

typedef_name: IDENT {$$ = $1;}; 

initializer: assignment_expression  // *** Optional -- Not Implemented ***
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

int main(){
    //yydebug = 1;
    current = NULL;
    push_scope(FILE_SCOPE);
    current->scope_fileName = NULL;
    current->scope_lineNum = 1;
    int t;
    while(!(t = yyparse())){
    };
}

void yyerror(char *str) {
    fprintf(stderr,"error: %s\n",str);
}
