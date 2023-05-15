#include "assembly.h"
#include "quads.h"

void generate_globals(char *out) {
    FILE *outfile = fopen(out, "w");
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
