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
            if (node->ptr.parent) {
                printAST(node->ptr.parent, indent+1);
            } else {
                printIndents(indent+1);
            }
            break; 
        case SYMBOL_POINTER_NODE:
            if ((node->sym_p).sym->sym_type == FUNCTION_SYMBOL) {
                printFunctions((node->sym_p).sym, indent);
            } else if ((node->sym_p).sym->sym_type == VARIABLE_SYMBOL) {
                printDeclaration((node->sym_p).sym, indent);
            }
    }
    free(node); 
}

void printFunctions(struct symbol *sym, int indent) {
    printf("%s is a %s function returning\n", sym->key, printStorageClass(sym));

    union astnode *temp = sym->type_rep;
    if (temp) {
        if ((temp)->generic.type == POINTER_NODE) {
            printAST(temp, indent);
        }
        if ((temp)->generic.type == ARRAY_NODE) { //add this to printAST instead
            printIndents(indent++);
            printf("array ");
        }
    }
    if ((sym->dec_specs)->decspec.q_type) {
        printIndents(indent++);
        printf("%s ", printTypeQualifier(sym));
    }

    if ((sym->dec_specs)->decspec.s_type) {
        printIndents(indent);
        while(sym->dec_specs) {
            printf("%s ", printScalarType(sym->dec_specs));
            sym->dec_specs = (sym->dec_specs)->decspec.next;
        }
    }
    printf("\n");
}

/* i1 is defined at base.c:1 [in global scope starting at base.c:1] as a 
variable with stgclass extern  of type:
  int
 */

void printDeclaration(struct symbol *sym, int indent) {
    printf("%s is defined at ", sym->key);
    printf("%s:%d ", report.fileName, report.lineNum);
    if (!current->scope_fileName) {
        current->scope_fileName = report.fileName;
    }
    if (!current->scope_lineNum) {
        current->scope_lineNum = report.lineNum;
    }
    printf("[in %s starting at %s:%d]\n", printScopeName(), current->scope_fileName, current->scope_lineNum);
    if (sym->sym_type == VARIABLE_SYMBOL) {
        printf("\t%s is a %s ", sym->key, printSymType(sym));
        printf("with storage class %s of type:\n\t", printStorageClass(sym)); 

        if (sym->type_rep) {
            if ((sym->type_rep)->generic.type == POINTER_NODE) {
                union astnode *temp = sym->type_rep;
                printAST(temp, indent+1);
            }
            if ((sym->type_rep)->generic.type == ARRAY_NODE) { //add this to printAST instead
                printIndents(indent+1);
                printf("array ");
            }
        }

        if ((sym->dec_specs)->decspec.q_type) {
            printf("%s ", printTypeQualifier(sym));
        }

        if ((sym->dec_specs)->decspec.s_type) {
            while(sym->dec_specs) {
                printf("%s ", printScalarType(sym->dec_specs));
                sym->dec_specs = (sym->dec_specs)->decspec.next;
            }
        }
        printf("\n");
    } else if (sym->sym_type == FUNCTION_SYMBOL) {
        printIndents(++indent);
        printFunctions(sym, indent);
        return;
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
    }
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
    switch((node->decspec.s_type)->scalar.scalarType) {
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