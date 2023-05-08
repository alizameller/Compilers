#include "quads.h"

bb_list *block_list;
basic_block *curr_block;
quad_list_item *curr_quad;

void init_IR() {
    // allocate memory
	bb_list *block_list = (bb_list *) malloc(sizeof (bb_list));
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

    return quad;

}

void append_quad_list(struct quad_list_item *addition) {
    if (!curr_block->head_quad) { // first quad in BB
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
    // not sure how this will work
    // big list pointing to bbs in order
    // basic blocks contain possible scenarios?
}

void generate_quads(union astnode *node) {
    switch(node->generic.type) {
        case UNOP_NODE:
            break;
        case BINOP_NODE:
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
            break;
    }

    fprintf(stderr, "Error: Cannot generate quads\n");
}