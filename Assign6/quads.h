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
    RET,
    NUM_OPS
} opcode;

// Enum of Addressing Mode
typedef enum mode{
    IMMEDIATE,
    INDIRECT,
    DIRECT
} mode;

// Basic Block
typedef struct basic_block {
    char *bb_name; 
    char *f_name;                          // eg: BB1, BBr, f ?
    struct quad_list_item *head_quad;             // Linked list of quads within one block
    struct basic_block *next_bb, *branch_bb;    // exit branch, continue linearly (next) or branch (on conditional)
    int branch_condition;                    // Type of comparator (from op_codes enum below)
    int assembled;
} basic_block;

struct basic_block *new_basic_block(char *bb_name, char *function_name);
struct basic_block *update_block(struct basic_block *next_bb, struct basic_block *branch_bb, int branch_condition);

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
    basic_block **list;
} bb_list;

struct bb_list *new_bblist(struct basic_block *head, struct basic_block *tail);
void append_bb_list(struct basic_block *entry, struct basic_block *next, struct basic_block *branch);

// create temporary node
union astnode *new_temp();

// initialize current block, current quad and block list 
void init_IR();

// generate quads for AST nodes -- main generation function
void generate_quads(union astnode *node);

// gen lvalue of expression
union astnode *gen_lvalue(union astnode *node);

// gen rvalue of expression
union astnode *gen_rvalue(union astnode *node, union astnode *target);

// generate quads for functions
void generate_functions(union astnode *node);

// generate quads for assignment expressions
void generate_assignment(union astnode *node);

union astnode *generate_fncall(union astnode *node, union astnode *target);

void generate_if(union astnode *node);

void generate_conditions(union astnode *expr, basic_block *true, basic_block *false);

void generate_while(union astnode *node);

void generate_inc_dec(union astnode *node);

int get_size(union astnode *node);

int get_scalarSize(union astnode *node);

bb_list *block_list;
basic_block *curr_block;
quad_list_item *curr_quad;
int temp_num;
int f; 
int n; 
union astnode *symbol_temp;
union astnode *left_temp;
union astnode *backup;
int addressing_mode; 

#endif // QUADS_H