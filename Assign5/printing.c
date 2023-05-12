#include "ast-manual.h"
#include "parse.tab.h"

void printIndents(int indent){
    for (int i = 0; i < indent; i++){
        printf("\t");
    }
}

void printBinop(int op){
    if(op == '=') {
        printf("ASSIGNMENT\n"); 
    } else if(op >= 263 && op <= 264){
        printf("LOGICAL OP ");
    } else if(op >= 265 && op <= 266){
        printf("BINARY OP ");
    } else if(op >= 267 && op <= 270){
        printf("COMPARISON OP ");
    } else if(op >= 271 && op <= 282){
        printf("ASSIGNMENT COMPOUND (");
    } 
    switch(op){
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

    if(op >= 267 && op <= 270){
        printf("=\n");
    } else if(op >= 271 && op <= 282){
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
    //printf("type is %d\n", node->generic.type);
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
            printIndents(indent);
            printf("THEN:\n");
            printAST(node->ternop.middle, indent+1);
            printIndents(indent);
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
            printIndents(indent-2);
            printf("arg #%d=\n", count);
            indent++; // im not sure why the indents got messed up here
            printAST((node->list.arg_head)->arg.argument, indent+1);
            while(node->list.arg_next != NULL) {
                printIndents(indent);
                printf("arg #%d=\n", ++count);
                printAST((node->list.arg_next)->arg.argument, indent+1);
                node = node->list.arg_next;
            }
            break;
        case FUNCTION_NODE:
            printf("FNCALL, %d arguments\n", node->func.num_args);
            printAST(node->func.function_name, indent+1);
            if (node->func.arg_head) {
                printAST(node->func.arg_head, --indent);
            }
            break;
        case ARGUMENT_NODE:
        case SCALAR_NODE:
            printf("SCALAR DECLARATION, TYPE: %d\n", node->scalar.scalarType);
            break; 
        case POINTER_NODE:
            printf("pointer to\n");
            if (node->ptr.parent) {
                printAST(node->ptr.parent, indent+1);
            } else {
                printIndents(indent+1);
            }
            break; 
        case SYMBOL_POINTER_NODE:
            printIndents(0); // suppressing error of "expected expression"
            symbol *temp_sym = node->sym_p.sym;
            printf("%s is defined at ", (temp_sym)->key);
            scope *scope_ptr = find_symbol((temp_sym)->nameSpace, (temp_sym)->key);
            printf("%s:%d ", (temp_sym)->filename, (temp_sym)->line); 
            printf("[in %s starting at %s:%d]\n", printScopeName(), scope_ptr->scope_fileName, scope_ptr->scope_lineNum);

            if (temp_sym->sym_type == FUNCTION_SYMBOL) {
                printFunctions(temp_sym, ++indent);
            } else if (temp_sym->sym_type == VARIABLE_SYMBOL) {
                printDeclaration(temp_sym, ++indent);
            } 
            break;
        case FUNCTION_DEF_NODE:
            printf("a function returning\n");
            if (node->fndef.ret_type && node->fndef.ret_type->generic.type == DECSPEC_NODE) { 
                printIndents(indent);
            }
            while(node->fndef.ret_type) {
                if (node->fndef.ret_type->generic.type == FUNCTION_DEF_NODE) {
                    printf("a function returning\n");
                    //printf("ret type of func is %d\n", node->fndef.ret_type->generic.type);
                    printAST(node->fndef.ret_type, indent);
                    break;
                } else if (node->fndef.ret_type->generic.type == DECSPEC_NODE) {
                    printf("%s ", printScalarType(node->fndef.ret_type));
                    (node->fndef.ret_type) = (node->fndef.ret_type)->decspec.next;
                    //printf("%d\n", node->fndef.ret_type->decspec.s_type->scalar.scalarType);
                    break;
                } else if (node->fndef.ret_type->generic.type == ARRAY_NODE) {
                    printAST(node->fndef.ret_type, indent++);
                    break;
                } else if (node->fndef.ret_type->generic.type == POINTER_NODE) {
                    //printf("pointer to\n");
                    printAST(node->fndef.ret_type, indent);
                    break;
                }
            }
            printf("\n");
            break;
        case ARRAY_NODE:
            printIndents(0);
            printf("array\n");
            union astnode *temp = node;
            while (temp->arr.element_type) { // if element type of array is array
                if (temp->arr.size == -1) {
                    printIndents(indent+1);
                    printf("of unknown size of\n");
                } else {
                    printIndents(indent+1);
                    printf("of size %d of\n", node->arr.size);
                }
                printIndents(indent+1);

                if (temp->arr.element_type->generic.type == DECSPEC_NODE) {
                    printf("%s ", printScalarType(temp->decspec.s_type));
                    temp->arr.element_type = (temp->arr.element_type)->decspec.next;
                } else if (temp->arr.element_type->generic.type == ARRAY_NODE) {
                    // printf("array\n");
                    temp = temp->arr.element_type;
                    printAST(temp, ++indent);
                }
            }
            printf("\n");
            break;
        case DECSPEC_NODE: 
            printIndents(0);
            union astnode *decspec_temp = node;
            if (decspec_temp->decspec.s_type) {
                while(decspec_temp) {
                    printf("%s ", printScalarType(decspec_temp->decspec.s_type));
                    decspec_temp = (decspec_temp)->decspec.next;
                }
            }
            printf("\n");
            break;
        case LABEL_NODE:
            if (node->label.labelType == GOTO_LABEL) {
                printf("LABEL(");
                if (node->label.label_name) {
                    printf("%s):\n", node->label.label_name->sym_p.sym->key);
                } else {
                    printf("Error: Label does not have a label name\n");
                }
            } else if (node->label.labelType ==CASE_LABEL) {
                printf("CASE\n");
                printIndents(indent+1);
                printf("EXPR:\n");
                printAST(node->label.label_name, indent+2);
                printIndents(indent+1);
                printf("STMT:\n");
            } else { //default label
                printf("DEFAULT:\n");
            }
            printAST(node->label.statement, ++indent);
            break;
        case IF_NODE:
            printf("IF\n");
            printAST(node->if_statement.exp, indent+1);
            printIndents(indent);
            printf("THEN\n");
            printAST(node->if_statement.statement, indent+1);
            break;
        case SWITCH_NODE:
            printf("SWITCH\n");
            printAST(node->switch_statement.exp, indent+1);
            printIndents(indent);
            printf("BODY\n");
            printAST(node->switch_statement.statement, indent+1);
            break;
        case WHILE_NODE:
            printf("WHILE\n");
            printAST(node->while_statement.exp, indent+1);
            printIndents(indent);
            printf("BODY\n");
            printAST(node->while_statement.statement, indent+1);
            break;
        case DO_WHILE_NODE:
            printf("DO\n");
            printAST(node->while_statement.statement, indent+1);
            printf("WHILE\n");
            printAST(node->while_statement.exp, indent+1);
            printIndents(indent);
            break;
        case FOR_NODE:
            printf("FOR_NODE\n");
            indent = indent+2;
            printIndents(indent);
            printf("INTIIALIZATION\n");
            printAST(node->for_statement.initialization, indent+1);
            printIndents(indent);
            printf("CONDITION\n");
            printAST(node->for_statement.condition, indent+1);
            printIndents(indent);
            printf("UPDATE\n");
            printAST(node->for_statement.update, indent+1);
            printIndents(indent);
            printf("BODY\n");
            printAST(node->for_statement.statement, indent+1);
            break;
        case GOTO_NODE:
            printf("GOTO ");
            printf("%s (DEF)\n", node->goto_statement.label_ptr->label.label_name->sym_p.sym->key);
            break;
        case CONTINUE_NODE:
            printf("CONTINUE\n");
            break;
        case BREAK_NODE:
            printf("BREAK\n");
            break;
        case RETURN_NODE:
            printf("RETURN\n");
            printAST(node->ret.exp, indent+1);
            break;
        case LIST_NODE:
            if (!(node->ast_list.prev)) {
                printf("LIST {\n");
            }
            while(node->ast_list.node) {
                printAST(node->ast_list.node, indent+1);
                if (!(node->ast_list.next)) { // if next is null
                    break; 
                }
                node = node->ast_list.next; 
            }
            printIndents(indent);
            printf("}\n");
    }
    free(node); 
}

void printFunctions(struct symbol *sym, int indent) {
    printIndents(indent);
    printf("%s is in storage class %s and is\n", sym->key, printStorageClass(sym));        
    if ((sym->dec_specs)->decspec.q_type) {
        printIndents(++indent);
        printf("%s\n", printTypeQualifier(sym));
    }

    union astnode *temp = sym->type_rep;
    
    //printf("ret type is %d\n", (((temp->fndef.ret_type)->ret.returning)->generic.type));
    if (temp) {
        if (temp->generic.type == POINTER_NODE) {
            printf("a function returning\n");
            //printIndents(indent);
            //printf("pointer to\n");
            printAST(temp, indent);
        } else if (temp->generic.type == FUNCTION_DEF_NODE) {
            printAST(temp, indent+1);
        } else {
            printf("a function returning\n");
            union astnode *decspec_temp = sym->dec_specs;
            if (decspec_temp->decspec.s_type) {
                printIndents(indent+1);
                while(decspec_temp) {
                    printf("%s ", printScalarType(decspec_temp));
                    decspec_temp = (decspec_temp)->decspec.next;
                }
            }
            printf("\n"); 
        } 
    }
}

void printDeclaration(struct symbol *sym, int indent) {
    if (sym->sym_type == FUNCTION_SYMBOL) {
        printFunctions(sym, indent);
        return;
    }
    printIndents(indent);
    printf("%s is a %s ", sym->key, printSymType(sym));
    printf("with storage class %s of type:\n", printStorageClass(sym)); 

    if ((sym->dec_specs)->decspec.q_type) {
        printIndents(++indent);
        printf("%s\n", printTypeQualifier(sym));
    }

    union astnode *temp = sym->type_rep;
    if (temp) {
        if ((temp)->generic.type == POINTER_NODE) {
            //printIndents(indent+1);
            //printf("pointer to\n");
            printAST(temp, indent);
        }
        if ((temp)->generic.type == ARRAY_NODE) { //add this to printAST instead?
            //printIndents(++indent);
            //printf("array\n");
            printAST(temp, indent);
        }
    } else {
        union astnode *decspec_temp = sym->dec_specs;
        if (decspec_temp->decspec.s_type) {
            if (!decspec_temp->decspec.q_type) {
                printIndents(indent);
            } else {
                printIndents(++indent);
            }
            while(decspec_temp) {
                printf("%s ", printScalarType(decspec_temp->decspec.s_type));
                decspec_temp = (decspec_temp)->decspec.next;
            }
        }
        printf("\n");
    }
}

char *printScopeName(void){
    switch(current->name) {
        case FILE_SCOPE:
            return "file scope";
        case BLOCK_SCOPE:
            return "block scope";
        case FUNCTION_SCOPE:
            return "function scope";
        case PROTOTYPE_SCOPE:
            return "prototype scope";
    }
}

char *printSymType(struct symbol *sym) {
    switch(sym->sym_type) {
        case VARIABLE_SYMBOL:
            return "variable";
        case FUNCTION_SYMBOL:
            return "function";
        case LABEL_SYMBOL:
            return "label";
    }
    return NULL;
}

char *printStorageClass(struct symbol *sym) {
    switch((sym->dec_specs)->decspec.s_class) {
        case UNKNOWN_CLASS:
            return "unknown";
        case TYPEDEF_CLASS:
            return "typedef";
        case EXTERN_CLASS:
            return "extern";
        case STATIC_CLASS:
            return "static";
        case AUTO_CLASS:
            return "auto";
        case REGISTER_CLASS:
            return "register";
    }
}

char *printScalarType(union astnode *node) {
    specifier_type st; 
    if (node->generic.type == SCALAR_NODE) {
        st = node->scalar.scalarType;
    } else {
        st = (node->decspec.s_type)->scalar.scalarType;
    }

    switch(st) {
        case UNKNOWN_TYPE:
            return "unknown";
        case VOID_TYPE:
            return "void";
        case CHAR_TYPE:
            return "char";
        case SHORT_TYPE:
            return "short";
        case INT_TYPE:
            return "int";
        case LONG_TYPE:
            return "long";
        case FLOAT_TYPE:
            return "float";
        case DOUBLE_TYPE:
            return "double";
        case SIGNED_TYPE:
            return "signed";
        case UNSIGNED_TYPE:
            return "unsigned";
        case BOOL_TYPE:
            return "bool";
    }
}

char *printTypeQualifier(struct symbol *sym) {
    switch((sym->dec_specs)->decspec.q_type) {
        case NONE_TYPE:
            return "none";
        case CONST_TYPE:
            return "const";
        case RESTRICT_TYPE:
            return "restrict";
        case VOLATILE_TYPE:
            return "volatile";
    }
}

void printQuads() {
    basic_block *temp_block = block_list->head; 
    if (temp_block) {
        printf("%s:\n", block_list->head->bb_name);
        quad_list_item *temp_quad = block_list->head->head_quad;
        while (temp_quad) {
            printf("\t");
            if (temp_quad->op_code >= 4 && temp_quad->op_code <= 9) {
                printType(temp_quad->dest);
                printf(" =\t");
            } else {
                printf("\t");
                if (temp_quad->dest) {
                    temp_quad->src2 = temp_quad->dest;
                }
            }
            printf("%s ", printOp(temp_quad->op_code));
            printType(temp_quad->src1);
            if (temp_quad->src2) {
                printType(temp_quad->src2);
            }
            printf("\n");
            temp_quad = temp_quad->next_quad;
        }
        temp_block = temp_block->next_bb;
    }
}

void printType(union astnode *node) {
    if (node->generic.type == TEMPORARY_NODE) {
        printf("T%d ", node->temp.num);
    } else if (node->generic.type == SYMBOL_POINTER_NODE){
        printf("%s ", node->sym_p.sym->key);
    } else if (node->generic.type == NUMBER_NODE){
        printf("%lld{constant} ", node->num.numInfo.value.int_val);
    }
    return;
}

char *printOp(int opcode) {
    char *op_code_arr[NUM_OPS] = {"LOAD", "STORE", "LEA", "MOV", "ADD", "SUB", "MUL", "DIV", "MOD", "CMP", "BR",
                                  "BREQ", "BRNEQ", "BRLT", "BRLE", "BRGT", "BRGE", "ARGBEGIN", "ARG", "CALL", "RET"};
    return op_code_arr[opcode];
}