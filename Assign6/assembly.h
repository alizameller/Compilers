#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "ast-manual.h"
#include <stdio.h>

FILE *outfile;
FILE *stringfile;
struct quad_list_item *prev; 

void generate_assembly(char *out);

void generate_globals();

int get_alignment(union astnode *node); 

void generate_funcs();

int get_offset(char *f_name);

struct basic_block *generate_blocks(struct basic_block *block);

void generate_quad_assembly(struct quad_list_item *quad);

char *print_assemblyType(union astnode *node);

char *printRegisters(int registers);

union astnode *reserve_registers(union astnode *node);

int regs[6]; //indexed by enum registers to keep track of which ones are in use

void free_register(union astnode *temp_reg);

void if_string(struct quad_list_item *quad);

void generate_jump(struct basic_block *block);

int add_dest_contains_addr; 

#endif // ASSEMBLY_H