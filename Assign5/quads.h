#ifndef QUADS_H
#define QUADS_H

#include "ast-manual.h"

// Enum of Opcodes
typedef enum opcode {
    NONE,
    LOAD,
    STORE,
    LEA,
    MOV,
    // Arithmetic Ops
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    // Logical Ops
    CMP,
    BR,
    BREQ,
    BRNEQ,
    BRLT,
    BRLE,
    BRGT,
    BRGE,
    // Function Ops
    ARGBEGIN,
    ARG,
    CALL,
    RET
} opcode;

// Enum of Addressing Mode
typedef enum mode{
    IMMEDIATE,
    INDIRECT,
    DIRECT
} mode;

// Basic Block
typedef struct basic_block {
    char *bb_name;                           // eg: BB1, BBr, f
    struct quad_list_item *head_quad;             // Linked list of quads within one block
    struct basic_block *next_bb, *branch_bb;    // exit branch, continue linearly (next) or branch (on conditional)
    int branch_condition;                    // Type of comparator (from op_codes enum below)
    int printed;                             // Used when printing blocks, so no endless loops
    int assembled;                           // Used when writing assembly, so no endless loops
} basic_block;

struct basic_block *new_basic_block(char *bb_name);
struct basic_block *update_block(char *bb_name, struct quad_list_item quad, struct basic_block next_bb, struct basic_block branch_bb, 
                                    int branch_condition, int printed, int assembled);

// Quads
typedef struct quad_list_item {
    opcode op_code;
    union astnode *dest, *src1, *src2;
    struct quad_list_item  *next_quad;
} quad_list_item;

struct quad_list_item *new_quad(opcode op_code, union astnode *dest, union astnode *src1, union astnode *src2, struct quad_list_item *next_quad);
void append_quad_list(struct quad_list_item *addition);

// Basic Block List
typedef struct bb_list {
    basic_block *head;
    basic_block *tail;
} bb_list;

struct bb_list *new_bblist(struct basic_block *head, struct basic_block *tail);
void append_bb_list(struct basic_block *entry, struct basic_block *next, struct basic_block *branch);

// initialize current block, current quad and block list 
void init_IR();

// generate quads for AST nodes
void generate_quads(union astnode *node);

#endif // QUADS_H