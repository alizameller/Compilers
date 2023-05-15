#include "assembly.h"
#include "quads.h"

void generate_assembly(char *out) {
    FILE *outfile = fopen(out, "w");
    fprintf(outfile, "\t.file\t\"%s\"\n", out);
    generate_globals(outfile);
    fprintf(outfile, "\t.text\n");
    generate_funcs(outfile);
}

void generate_globals(FILE *outfile) {
    scope *global_scope = current; 
    // set global_scope to actual global scope, backtrack through the scopes
    if (!global_scope) { // current scope is NULL, have yet to push any scopes
        fprintf(stderr, "Error: cannot find global scope\n"); 
    } else {
        while (global_scope) {
            if(global_scope->name == FILE_SCOPE) break;
            global_scope = global_scope->parent;
        }
    }

    symbol_table *global_sym = global_scope->symbolTables[OTHER]; 
     // find all symbols in global symbol table
    for(int i = 0; i < global_sym->capacity; i++) {
        symbol *sym = global_sym->data[i];
        if(sym && sym->sym_type == VARIABLE_SYMBOL) {
            // get size and alignment of globals -- make astnode to get size of variable
            int size;
            int alignment;
            if (sym->type_rep && sym->type_rep->generic.type == POINTER_NODE) {
                size = 4;
                alignment = 4;
            } else {
                size = get_size(new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym));
                alignment = get_alignment(sym->dec_specs);
            }
            // Print to output file
            fprintf(outfile, "    .comm    %s,%d,%d\n", sym->key, size, alignment);
        }
    }
} 

int get_alignment(union astnode *node) {
    specifier_type st = (node->decspec.s_type)->scalar.scalarType;

    switch(st) {
        case CHAR_TYPE:
            return 1;
        case SHORT_TYPE:
            return 2;
        default:
            return 4;
    }
}

int get_offset(char *f_name) {
    // Gets symbol table entry for function
    symbol *sym_temp;
    int offset = 0;

    scope *f_scope = current; 
    while (f_scope) {
        if(f_scope->name == FUNCTION_SCOPE && strcmp(f_name, f_scope->scope_fileName)) break;
        f_scope = f_scope->parent;
    }

    if (!f_scope) { 
        fprintf(stderr, "Error: cannot find scope corresponding to function %s\n", f_name); 
    }

    symbol_table *f_table = f_scope->symbolTables[OTHER]; 
    // find all symbols in global symbol table
    for(int i = 0; i < f_table->capacity; i++) {
        symbol *sym = f_table->data[i];
        if(sym && sym->sym_type == VARIABLE_SYMBOL) {
            if (sym->type_rep && sym->type_rep->generic.type == POINTER_NODE) {
                offset += 4;
            } else {
                offset += get_size(new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym));
            }
        }
    }

    return offset;
}

void generate_funcs(FILE *outfile) {
    basic_block *temp_block = block_list->head;
    int op; 
    while (temp_block) {
        if (temp_block->f_name) {
            fprintf(outfile, "\t.globl\t%s\n", temp_block->f_name);
            fprintf(outfile, "\t.type\t%s,@function\n", temp_block->f_name);
            fprintf(outfile, "%s:\n", temp_block->f_name);
            fprintf(outfile, "\tpushl\t%%ebp\n");
            fprintf(outfile, "\tmovl\t%%esp, %%ebp\n");
            // Reserves space for local variables
            int l_size = get_offset(temp_block->f_name);
            if(l_size) {
                fprintf(outfile, "\tsubl \t$%d, %%esp\n", l_size);
            }
        }
        quad_list_item *temp_quad = temp_block->head_quad;
        while (temp_quad) {

            temp_quad = temp_quad->next_quad;
        }

        temp_block = temp_block->next_bb;
    }
} 