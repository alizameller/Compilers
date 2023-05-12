#include "quads.h"
#include "parse.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_IR() {
    // allocate memory for list of bbs
	block_list = (bb_list *) malloc(sizeof (bb_list));
    // set currents
    curr_block = NULL;
    curr_quad = NULL;
    temp_num = 0;
    f = 0; 
    n = 0; 
}

struct basic_block *new_basic_block(char *bb_name, char *function_name) {
    // allocate memory
	basic_block *block = (basic_block *) malloc(sizeof (basic_block));
    if (function_name) {
        block->f_name = function_name;
    } else {
        block->f_name = NULL;
    }
    if (!bb_name) { // if bb_name is NULL
        char *name = calloc(256, sizeof(char));
        name[0] = 'B';
        name[1] = 'B';
        sprintf(&name[2], "%d", f); 
        name[3] = '.';
        sprintf(&name[4], "%d", n); 
        block->bb_name = name;
    } else {
        block->bb_name = bb_name;
    }    

    block->head_quad = NULL;
    block->next_bb = NULL;
    block->branch_bb = NULL;
    block->branch_condition = 0;
    return block;
}

struct basic_block *update_block(struct basic_block *next_bb, struct basic_block *branch_bb, int branch_condition) {
    curr_block->next_bb = next_bb;
    curr_block->branch_bb = branch_bb;
    curr_block->branch_condition = branch_condition;
    return curr_block;
}

struct quad_list_item *new_quad(opcode op_code, union astnode *dest, union astnode *src1, union astnode *src2, struct quad_list_item *next_quad) {
    // allocate memory
	quad_list_item *quad = (quad_list_item *) malloc(sizeof (quad_list_item));

    quad->op_code = op_code; 
    quad->src1 = src1;
    quad->src2 = src2; 
    quad->dest = dest;
    quad->next_quad = next_quad;

    if (!curr_quad) { // if first quad in current block
        curr_block->head_quad = quad;
        return quad;
    } 

    // if current block has a quad list in it already (i.e. not first quad in BB)
    curr_quad->next_quad = quad;
    // update current quad
    curr_quad = quad;

    return quad;

}

void append_quad_list(struct quad_list_item *addition) {
    if (!(curr_block->head_quad) || !curr_quad) { // first quad in BB
        curr_block->head_quad = addition;
        curr_quad = addition; 
        return;
    } 

    if(curr_quad->next_quad) {
        curr_quad = curr_quad->next_quad;
    }
    curr_quad->next_quad = addition;
}

// not sure if this is necessary
struct bb_list *new_bblist(struct basic_block *head, struct basic_block *tail) {
    // allocate memory
	bb_list *list_bb = (bb_list *) malloc(sizeof (bb_list));

    list_bb->head = head;
    list_bb->tail = tail; 

    return list_bb;
}

void append_bb_list(struct basic_block *entry, struct basic_block *next, struct basic_block *branch) {
    if (!(block_list->head)) { // if first block in list
        block_list->head = entry;
        block_list->tail = entry;
    } else {
        block_list->tail->next_bb = entry;
        block_list->tail = entry;
    }
    // do i need this if im keeping track of tail?
    curr_block = entry; 
    if (curr_quad) {
        curr_quad->next_quad = NULL;
    }
    curr_quad = NULL; 
    curr_block->head_quad = curr_quad;
}

int get_size(union astnode *node) {
    int size = 1;
    if (node->generic.type == IDENT_NODE) {
        symbol *sym = contains_symbol(current->symbolTables[OTHER], node->id.ident);
        if (sym) {
            node = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
            return get_size(node);
        } else {
            // ERROR
        }
    }
    switch(node->generic.type) {
        case SYMBOL_POINTER_NODE: {
            union astnode *temp_type = node->sym_p.sym->type_rep;
            if (!temp_type) { // ex: int r; SCALAR
                size = get_size(node->sym_p.sym->dec_specs); 
            } else if ((temp_type)->generic.type == POINTER_NODE){
                // idk
            } else if ((temp_type)->generic.type == ARRAY_NODE) {
                int temp_size = get_size(temp_type);
                size *= temp_size;
            }
            break;
        }
        case ARRAY_NODE: 
            return (node->arr.size)*get_size(node->arr.element_type);
        case DECSPEC_NODE: {
            union astnode *decspec_temp = node;
            if (decspec_temp->decspec.s_type) { 
                return get_scalarSize(decspec_temp);
            }
        }
    }
    return size;
} 

int get_scalarSize(union astnode *node) {
    // assumes floats are not supported
    int num_longs = 0; 
    specifier_type st = (node->decspec.s_type)->scalar.scalarType;
    union astnode *temp = node; 
    while(temp->decspec.next) {
        if (temp->decspec.s_type->scalar.scalarType == LONG_TYPE) {
            num_longs++; 
        }
        temp = temp->decspec.next; 
    }

    switch(st) {
        case CHAR_TYPE:
            return 1;
        case SHORT_TYPE:
            return 2;
        case LONG_TYPE:
            if (num_longs == 2) {
                return 8;
            }
            return 4; 
        case INT_TYPE:
            if (num_longs == 2) {
                return 8;
            }
            return 4; 
    }
}

// gen lvalue of expression
union astnode *gen_lvalue(union astnode *node, int *addressing_mode) {
    switch(node->generic.type) {
        case IDENT_NODE:{
            //printf("%d\n", curr_quad->op_code);
            symbol *sym = contains_symbol(current->symbolTables[OTHER], node->id.ident);
            if (sym) {
                union astnode *symbol_pointer = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                return gen_lvalue(symbol_pointer, addressing_mode);
            } else {
                // ERROR
            } 
        }
        case SYMBOL_POINTER_NODE:
            if (node->sym_p.sym->sym_type == VARIABLE_SYMBOL) {
                if (node->sym_p.sym->type_rep && (node->sym_p.sym->type_rep->generic.type == POINTER_NODE)) {
                    *addressing_mode = INDIRECT;
                } else if (node->sym_p.sym->type_rep && (node->sym_p.sym->type_rep->generic.type == ARRAY_NODE)) {
                    //generate quad for LEA
                    union astnode *temp = new_temporary(TEMPORARY_NODE, ++temp_num);
                    curr_quad = new_quad(LEA, temp, node, NULL, curr_quad);
                    //printf("%d\n", temp->generic.type);
                    *addressing_mode = INDIRECT;
                    return temp;
                } else {
                    //printf("%d\n", node->sym_p.sym->dec_specs->decspec.s_type->scalar.scalarType);
                    *addressing_mode = DIRECT;
                }
            }
            return node;
        case UNOP_NODE:
            // if pointer dereference
            if(node->unop.operator == '*') {
                if (node->unop.operand->generic.type == BINOP_NODE) {
                    //printf("unop left %d\n", node->unop.operand->binop.left->generic.type);
                    //printf("unop right %d\n", node->unop.operand->binop.right->num.numInfo.value.int_val);
                    *addressing_mode = INDIRECT;
                    return gen_rvalue(node->unop.operand, NULL);
                }
                *addressing_mode = INDIRECT;
                return gen_rvalue(node->unop.operand, NULL);
            }
        break;
    }
}

// gen rvalue of expression
union astnode *gen_rvalue(union astnode *node, union astnode *target) {
    int op;
    //printf("%d\n", node->generic.type);
    switch(node->generic.type) {
        // Constants
        case SYMBOL_POINTER_NODE: {
            symbol_temp = node;
            union astnode *type = node->sym_p.sym->type_rep; //pointer, array or scalar
            if (node->sym_p.sym->type_rep) {
                if (type->generic.type == POINTER_NODE) {
                    if (type->ptr.parent && type->ptr.parent->generic.type != POINTER_NODE) {
                        // not sure what to do here?
                    }
                } else if (type->generic.type == ARRAY_NODE) {
                    if(!target) target = new_temporary(TEMPORARY_NODE, ++temp_num);
                    curr_quad = new_quad(LEA, target, node, NULL, curr_quad);
                    return target;
                }
            }
            if (node->sym_p.sym->sym_type == VARIABLE_SYMBOL) {
                return node;
            }
            //printf("%d\n", node->sym_p.sym->type_rep->generic.type);
            //printf("%d\n", node->generic.type);
            return node; 
            break;
        }
        case NUMBER_NODE:
        case STRING_NODE:
            return node;
        case IDENT_NODE: {
            symbol *sym = contains_symbol(current->symbolTables[OTHER], node->id.ident);
            if (sym) {
                union astnode *symbol_pointer = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                //return gen_rvalue(symbol_pointer, NULL);
                return symbol_pointer;
            }
        }
        case BINOP_NODE: {
            union astnode *left;
            union astnode *right;
            if (node->binop.left->generic.type == IDENT_NODE) { 
                symbol *sym = contains_symbol(current->symbolTables[OTHER], node->binop.left->id.ident);
                if (sym) {
                    node->binop.left = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                } else {
                    // ERROR
                }
                left = gen_rvalue(node->binop.left, NULL);
            } else if (node->binop.left->generic.type == UNOP_NODE) { 
                left = gen_rvalue(node->binop.left, target);
                if (left->generic.type == TEMPORARY_NODE) {
                    left_temp = left; 
                }
            } else if (node->binop.left->generic.type == NUMBER_NODE) {
                left = node->binop.left;
            }

            if (node->binop.right->generic.type == IDENT_NODE) {
                symbol *sym = contains_symbol(current->symbolTables[OTHER], node->id.ident);
                if (sym) {
                    node->binop.left = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                } else {
                    // ERROR
                }
                right = gen_rvalue(node->binop.right, NULL);
            } else if (node->binop.right->generic.type == UNOP_NODE) { 
                right = gen_rvalue(node->binop.right, NULL);
            } else if (node->binop.right->generic.type == NUMBER_NODE) {
                right = node->binop.right;
            }

            if (!target) target = new_temporary(TEMPORARY_NODE, ++temp_num);
            switch(node->binop.operator) {
                case '+':
                    op = ADD;
                    // symbol + number 
                    if (node->binop.left->generic.type == SYMBOL_POINTER_NODE && node->binop.right->generic.type == NUMBER_NODE) {
                    // curr_quad = new_quad(MUL, temp1, right, sizeof(scalar_type of node->binop.left), curr_quad);
                        if (!target) target = new_temporary(TEMPORARY_NODE, ++temp_num);
                        struct numinfo sizeInfo; 
                        // get size of array and divide by arr.size because array gets promoted to pointer
                        sizeInfo.value.int_val = get_size(node->binop.left) / node->binop.left->sym_p.sym->type_rep->arr.size; 
                        union astnode *num = new_astnode_num(NUMBER_NODE, sizeInfo);
                        append_quad_list(new_quad(MUL, target, right, num, NULL));
                        //if (target) left = target; 
                        union astnode *temp = target;
                        if (left->generic.type != TEMPORARY_NODE) {
                            left = left_temp;
                        }
                        union astnode *target = new_temporary(TEMPORARY_NODE, ++temp_num);
                        append_quad_list(new_quad(ADD, target, left, temp, NULL)); 

                        return target;
                    }
                    // deref node + number ex: (a[2][3] -> *(*(a + 2) + 3))
                    if (node->binop.left->generic.type == UNOP_NODE && node->binop.right->generic.type == NUMBER_NODE) {
                        symbol_temp->sym_p.sym->type_rep = symbol_temp->sym_p.sym->type_rep->arr.element_type; // remove one layer of array
                        node->binop.left = symbol_temp;
                        return gen_rvalue(node, target);
                    }
                    break;
                case '-':
                    op = SUB;
                    break;
                case '*':
                    op = MUL;
                    break;
                case '/':
                    op = DIV;
                    break;
                case '%':
                    op = MOD;
                    break;
            }
            curr_quad = new_quad(ADD, target, left, right, curr_quad);

            return target;
        }
        case UNOP_NODE:
            if (node->unop.operator == '*') { //pointer deref
                union astnode *addr;
                if (node->unop.operand->generic.type == BINOP_NODE) {
                    return gen_rvalue(node->unop.operand, NULL);
                } else {
                    addr = gen_rvalue(node->unop.operand, NULL);
                }

                if (!target) target = new_temporary(TEMPORARY_NODE, ++temp_num);
                curr_quad = new_quad(LOAD, target, addr, NULL, curr_quad);
                
                return target;
            }

            // Sizeof operator
            if(node->unop.operator == SIZEOF) {
                if(!target) { // if target is NULL, create temp node
                    target = new_temporary(TEMPORARY_NODE, ++temp_num);
                }
                // gen quad MOV size to temp node
                int size = get_size(node->unop.operand);
                struct numinfo sizeInfo; 
                sizeInfo.value.int_val = size;
                union astnode *num = new_astnode_num(NUMBER_NODE, sizeInfo);
                curr_quad = new_quad(MOV, target, num, NULL, curr_quad);
                return target;
            }
            break;
        case FUNCTION_NODE:
            return generate_fncall(node, target);
    }
}

void generate_assignment(union astnode *node) {
    int *addressing_mode;
    astnode *lvalue = gen_lvalue(node->binop.left, addressing_mode);
    if (*addressing_mode == DIRECT) {
        astnode *rvalue = gen_rvalue(node->binop.right, NULL);
        append_quad_list(new_quad(MOV, lvalue, rvalue, NULL, NULL));
        curr_quad->next_quad = NULL;
        // make quad with MOV lvalue, rvalue
    } else if (*addressing_mode == INDIRECT) {
        astnode *rvalue = gen_rvalue(node->binop.right, NULL);
        append_quad_list(new_quad(STORE, lvalue, rvalue, NULL, NULL));
        curr_quad->next_quad = NULL;
    }
}

void generate_functions(union astnode *node) {
    // create a first block for function add it to bb_list and set curr block
    f++;
    n = 0;
    append_bb_list(new_basic_block(NULL, node->sym_p.sym->key), NULL, NULL);
    return;
}

union astnode *generate_fncall(union astnode *node, union astnode *target) {
    // create num ast node for quad generation
    struct numinfo args; 
    args.meta = UNSIGNED_INT; // just default value
    args.value.int_val = node->func.num_args; 
    union astnode *num = new_astnode_num(NUMBER_NODE, args); 

    // create quad ARGBEGIN
    append_quad_list(new_quad(ARGBEGIN, NULL, num, NULL, NULL));

    union astnode *arg_temp = node->func.arg_head;
    union astnode *arg_id; 
    while (arg_temp) {
        if (arg_temp->generic.type == ARGLIST_NODE) {
            //printf("arg is %s\n", arg_temp->list.arg_head->arg.argument->id.ident);
            arg_id = arg_temp->list.arg_head->arg.argument; 
        } else {
            //printf("arg is %s\n", arg_temp->arg.argument->id.ident);
            arg_id = arg_temp->arg.argument; 
        }
        append_quad_list(new_quad(ARG, NULL, arg_id, NULL, NULL));
        arg_temp = arg_temp->list.arg_next;
    }

    if(!target) { // if target is NULL, create temp node
        target = new_temporary(TEMPORARY_NODE, ++temp_num);
    }
    append_quad_list(new_quad(CALL, target, node->func.function_name, NULL, NULL));
    curr_quad->next_quad = NULL; 
    return target;
} 

void generate_ret(union astnode *node) {
    append_quad_list(new_quad(RET, NULL, gen_rvalue(node->ret.exp, NULL), NULL, NULL));
    curr_quad->next_quad = NULL; 
    update_block(NULL, NULL, RET);
}

void generate_if(union astnode *node) {
    n++;
    basic_block *true = new_basic_block(NULL, NULL);
    n++;
    basic_block *false = new_basic_block(NULL, NULL);
    // if logical? 
    // checks if there is an else (need to branch to false block, otherwise fall through)
    basic_block *next;
    if (node->generic.type == TERNOP_NODE) { // there is an else
        n++; 
        next = new_basic_block(NULL, NULL);
    } else if (node->generic.type == IF_NODE) { // no else
        next = false; 
    } 
    
    // generate condition quad 
    // generate quads for true block
    // append true block to condiiton quads w CMP op 
    // if there is an else, gen quads for else blocks
    // append false block to next block w CMP op
}

void generate_quads(union astnode *node) {
    switch(node->generic.type) {
        case UNOP_NODE:
            break;
        case BINOP_NODE:
            //printf("here! - binop\n");
            generate_assignment(node);
            break;
        case IF_NODE:
            break;
        case WHILE_NODE:
            break;
        case FOR_NODE:
            break;
        case CONTINUE_NODE:
            break;
        case BREAK_NODE:
            break;
        case RETURN_NODE:
            generate_ret(node);
            break;
        case FUNCTION_NODE: // function call
            generate_fncall(node, NULL);
            break;
        case LIST_NODE:
            while(node->ast_list.node) {
                generate_quads(node->ast_list.node);
                if (!(node->ast_list.next)) { // if next is null
                    break; 
                }
                node = node->ast_list.next; 
            }
            break;
        case SYMBOL_POINTER_NODE:
            //printf("here! - symbol\n");
            if (node->sym_p.sym->sym_type == FUNCTION_SYMBOL) {
                generate_functions(node);
            } 
            // else its a declaration in which case we do not care to generate quads for it
            break;
        default:
            fprintf(stderr, "Error: Cannot generate quads\n");
    }
    return;
}