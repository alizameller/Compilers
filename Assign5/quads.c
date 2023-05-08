#include "quads.h"

void init_IR() {
    // allocate memory for list of bbs
	block_list = (bb_list *) malloc(sizeof (bb_list));
    // set currents
    curr_block = NULL;
    curr_quad = NULL;
}

struct basic_block *new_basic_block(char *bb_name) {
    // allocate memory
	basic_block *block = (basic_block *) malloc(sizeof (basic_block));
    if (!bb_name) { // if bb_name is NULL
        char *name = calloc(256, sizeof(char));
        block->bb_name = name;
    } else {
        block->bb_name = bb_name;
    }    

    block->head_quad = NULL;
    block->next_bb = NULL;
    block->branch_bb = NULL;
    block->branch_condition = NONE;
    block->printed = 0;
    return block;
}

struct basic_block *update_block(char *bb_name, struct quad_list_item quad, struct basic_block next_bb, struct basic_block branch_bb, 
                                 int branch_condition, int printed, int assembled) {
    // nothing
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
    if (!(curr_block->head_quad)) { // first quad in BB
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
    // curr quad?
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
        case SWITCH_NODE:
            break;
        case WHILE_NODE:
            break;
        case DO_WHILE_NODE:
            break;
        case FOR_NODE:
            break;
        case CONTINUE_NODE:
            break;
        case BREAK_NODE:
            break;
        case RETURN_NODE:
            break;
        case FUNCTION_NODE: 
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
            // else its a declaration in which case we do not care
            break;
        default:
            fprintf(stderr, "Error: Cannot generate quads\n");
    }
    return;
}

// find lvalue of expression
union astnode *find_lvalue(union astnode *node, int *addressing_mode) {
    switch(node->generic.type) {
        case IDENT_NODE:{
            symbol *sym = contains_symbol(current->symbolTables[OTHER], node->id.ident);
            if (sym) {
                union astnode *symbol_pointer = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
                return find_lvalue(symbol_pointer, addressing_mode);
            } else {
                // ERROR
            }
        }
        case SYMBOL_POINTER_NODE:
            if (node->sym_p.sym->sym_type == VARIABLE_SYMBOL) {
                if (node->sym_p.sym->type_rep && (node->sym_p.sym->type_rep->generic.type == POINTER_NODE)) { // or array node?
                    *addressing_mode = INDIRECT;
                } else {
                    //printf("%d\n", node->sym_p.sym->dec_specs->decspec.s_type->scalar.scalarType);
                    *addressing_mode = DIRECT;
                }
            }
            return node;
    }
}

/* 
struct astnode *get_lvalue(struct astnode *node, int *mode) {
    switch(node->node_type) {
        // Scalar Variable
        case SYM_ENTRY_TYPE:
            // Scalar type
            if(node->ast_sym_entry.sym_type == VAR_TYPE
                && node->ast_sym_entry.sym_node->node_type == SCALAR_TYPE) {
                *mode = DIRECT_MODE;
                return node;
            }
            // Pointer type
            if(node->ast_sym_entry.sym_type == VAR_TYPE && 
                node->ast_sym_entry.sym_node->node_type == POINTER_TYPE) {
                *mode = INDIRECT_MODE;
                return node;
                }
            break;

        // Constants
        case NUMBER_TYPE:
        case CHARLIT_TYPE:
        case STRING_TYPE:
            return NULL;

        case UNARY_TYPE:
            // Pointer Deref
            if(node->ast_unary_op.op == '*') {
                *mode = INDIRECT_MODE;
                return get_rvalue(node->ast_unary_op.expr,NULL);
            }
            break;
    }

    return NULL;
}
*/

// find rvalue of expression
union astnode *find_rvalue(union astnode *node, int *addressing_mode) {
    int op;
    //printf("%d\n", node->generic.type);
    switch(node->generic.type) {
        // Constants
        case NUMBER_NODE:
        case STRING_NODE:
        case IDENT_NODE:
            return node;
        case BINOP_NODE:
            switch(node->binop.operator) {
                case '+':
                    op = ADD;
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
            break;
        case NONE:
            break;
    }
}


// Generates IR for assignments
void generate_assignment(union astnode *node) {
    int *addressing_mode;
    astnode *lvalue = find_lvalue(node->binop.left, addressing_mode);
    if (*addressing_mode == DIRECT) {
        astnode *rvalue = find_rvalue(node->binop.right, NULL);
        new_quad(MOV, lvalue, rvalue, NULL, NULL);
        // make quad with MOV lvalue, rvalue
    } else if (*addressing_mode == INDIRECT) {
        astnode *rvalue = find_rvalue(node->binop.right, NULL);
        new_quad(STORE, lvalue, rvalue, NULL, NULL);
    }
}


void generate_functions(union astnode *node) {
    /*
    // Makes sure that node is a function
    if(node->node_type != SYM_ENTRY_TYPE || node->ast_sym_entry.sym_type != FNC_NAME_TYPE) {
        fprintf(stderr, "ERROR: Can only print quads of function.\n");
        return; // Should this kill the program?
    }
    */
    // create a first block for function add it to bb_list and set curr block
    append_bb_list(new_basic_block(node->sym_p.sym->key), NULL, NULL);
    return;
}
