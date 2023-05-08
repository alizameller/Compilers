#ifndef QUADS_H
#define QUADS_H

#include "ast-manual.h"

// Basic Block
typedef struct basic_block {
    char *bb_name;                           // eg: BB1, BBr, f
    struct quad_list_item *quad;             // Linked list of quads within one block
    struct basic_block *next_bb, *branch;       // exit branch, continue linearly (next) or branch 
    int branch_condition;                    // Type of comparator (from op_codes enum below)
    int printed;                             // Used when printing blocks, so no endless loops
    int assembled;                           // Used when writing assembly, so no endless loops
} basic_block;

typedef struct quad_list_item {
    int op_code;
    union astnode *dest, *src1, *src2;
    struct quad_list_item  *next_quad;
} quad_list_item;


#endif // QUADS_H