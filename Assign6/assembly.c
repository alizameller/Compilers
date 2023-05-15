#include "assembly.h"

void generate_assembly(char *out) {
    int i;
    for (i = 0; i < NUM_REGISTERS; i++) {
        regs[i] = NO_REG; //initialize register array to NO_REG (available for use)
    }
    if (!block_cursor) {
        outfile = fopen(out, "w");
        fprintf(outfile, "\t.file\t\"%s\"\n", out);
        generate_globals(outfile);
        fprintf(outfile, "\t.text\n");
    }
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
            fprintf(outfile, "\t.comm    %s,%d,%d\n", sym->key, size, alignment);
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
    // fprintf(stderr, "name of func is %s\n", f_name);
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
            sym->stack_offset = offset;
        }
    }

    return offset;
}

basic_block *generate_blocks(FILE *outfile, basic_block *block) {
    if(block == NULL || block->assembled) {
        return NULL;
    }

    fprintf(outfile, "%s:\n", block->bb_name);

    quad_list_item *temp_quad = block->head_quad;
    while (temp_quad) {
        generate_quad_assembly(outfile, temp_quad);
        temp_quad = temp_quad->next_quad;
    }
}

void generate_quad_assembly(FILE *outfile, quad_list_item *quad) {
    char *temp = "temp";
    // if string -> create separate file and insert at beginning of file?
    if (quad->dest && quad->dest->generic.type == TEMPORARY_NODE) {
        quad->dest = reserve_registers(quad->dest);
    }

    // Checks op code
    switch(quad->op_code) {
        // astnode for temporary register
        astnode *temp_reg;

        // Addressing & Assigning
        case LOAD: //there is a problem with load
            // Gets temp register
            temp_reg = reserve_registers(NULL);
            astnode *temp_reg2 = reserve_registers(NULL);

            // Prints assembly
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(quad->src2));
            fprintf(outfile, "\tmovl  (%s), %s\n", print_assemblyType(temp_reg), print_assemblyType(temp_reg2));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(quad->dest));

            //free_register(temp_reg2);

            break;

        case STORE:
            if (quad->dest && !(quad->src1)) {
                quad->src1 = quad->dest;
                quad->dest = NULL;
            }
            if (quad->dest && !(quad->src2)) {
                quad->src2 = quad->dest;
                quad->dest = NULL;
            }
            // Gets temp register
            temp_reg = reserve_registers(NULL);
            // Prints assembly
            
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, (%s)\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            
            break;

        case LEA:
            // Gets temp register
            temp_reg = reserve_registers(NULL);

            // Prints assembly
            fprintf(outfile, "\tleal  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->src1));
        
            // Frees temp register
            //free_register(temp_reg);
            
            break;

        case MOV:
            // Gets temp register
            temp_reg = reserve_registers(NULL);
            // Prints assembly
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            // Frees temp register
            //free_register(temp_reg);
            break;

        // Arithmetic Operations
        case ADD:
            // Gets temp register
            temp_reg = reserve_registers(NULL);

            // Prints assembly
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\taddl  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            // Frees temp register
            //free_register(temp_reg);

            break;

        case SUB:
            // Gets temp register
            temp_reg = reserve_registers(NULL);

            // Prints assembly
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tsubl  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            // Frees temp register
            //free_register(temp_reg);

            break;

        case MUL:
            // Gets temp register
            temp_reg = reserve_registers(NULL);

            // Prints assembly
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\timull  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            // Frees temp register
            //free_register(temp_reg);

            break;
    }
}

union astnode *reserve_registers(union astnode *node) {
    if(node) {
        if ((node->generic.type == TEMPORARY_NODE && node->temp.reg != NO_REG) ||  // node is a temp node and already has a reg associated w it
            (node->generic.type == SYMBOL_POINTER_NODE && node->sym_p.sym->sym_type == VARIABLE_SYMBOL)) { // or node is a sym pointer of type var (accessible within memory)
        
            return node;
        }
    }
    if(!node) { // node is NULL
        node = new_temporary(TEMPORARY_NODE, n);   
    }
    int reg_num;
    for(reg_num = 0; reg_num < NUM_REGISTERS; reg_num++) {
        if (regs[reg_num] < 0) { // regs[reg_num] is available
            node->temp.reg = reg_num; // set reg num in temp node
            regs[reg_num] = reg_num;
            return node;
        }
    }
    return NULL;
}


char *print_assemblyType(union astnode *node) {
    static char *assembly;
    assembly = calloc(256, sizeof(char));
    if (node->generic.type == TEMPORARY_NODE) {
        switch(node->temp.reg) {
            case NO_REG:
                sprintf(assembly, "No register allocated");
                break;
            case EAX:
                sprintf(assembly, "%%eax");
                break;
            case EBX:
                sprintf(assembly, "%%ebx");
                break;
            case ECX:
                sprintf(assembly, "%%ecx");
                break;
            case EDX:
                sprintf(assembly, "%%edx");
                break;
            case EDI:
                sprintf(assembly, "%%edi");
                break;
            case ESI:
                sprintf(assembly, "%%esi");
                break;
        }
    } else if (node->generic.type == SYMBOL_POINTER_NODE){
        if(node->sym_p.sym->sym_type == VARIABLE_SYMBOL && node->sym_p.sym->dec_specs->decspec.s_class == EXTERN_CLASS) {
            sprintf(assembly, "%s", node->sym_p.sym->key);
        } else {
            sprintf(assembly, "-%d(%%ebp)", node->sym_p.sym->stack_offset);
        }
    } else if (node->generic.type == NUMBER_NODE){
        switch(node->num.numInfo.meta) {
                case INT_TYPE:
                    sprintf(assembly, "$%d", (int) node->num.numInfo.value.int_val);
                    break;

                case FLOAT_TYPE:
                    sprintf(assembly, "$%f", (float) node->num.numInfo.value.float_val);
                    break;

                case DOUBLE_TYPE:
                    sprintf(assembly, "$%f", (double) node->num.numInfo.value.float_val);
                    break;

                case LONG_TYPE:
                    sprintf(assembly, "$%ld", (long) node->num.numInfo.value.int_val);
                    break;

                default:
                    sprintf(assembly, "$%lld ", node->num.numInfo.value.int_val);
            }
    } else if (node->generic.type == IDENT_NODE){
        strcpy(assembly, node->id.ident);
    } else {
        sprintf(assembly, "variable");
    }
    //fprintf(stderr, "%s\n", assembly);
    return assembly;
}

void generate_funcs(FILE *outfile) {
    char *func_name;
    int i = 0;
    basic_block *temp_block = (*(block_list->list + i));
    i++;
    while (temp_block->assembled) {
        temp_block = temp_block->next_bb;
    }
    int op; 
    int l_size;
    if (temp_block->f_name) {
        fprintf(outfile, "\t.globl\t%s\n", temp_block->f_name);
        fprintf(outfile, "\t.type\t%s,@function\n", temp_block->f_name);
        fprintf(outfile, "%s:\n", temp_block->f_name);
        fprintf(outfile, "\tpushl\t%%ebp\n");
        fprintf(outfile, "\tmovl\t%%esp, %%ebp\n");
        // Reserves space for local variables
        l_size = get_offset(temp_block->f_name);
        //fprintf(stderr, "lsize is %d\n", l_size);
        if(l_size) {
            fprintf(outfile, "\tsubl \t$%d, %%esp\n\n", l_size);
        }
        func_name = temp_block->f_name;
    }
    quad_list_item *temp_quad = temp_block->head_quad;
    basic_block *end = generate_blocks(outfile, temp_block);
    temp_block->assembled = 1; 
    // Generates assembly for return
    // Checks if explicit return, if not then 0
    if(block_list->tail->branch_condition != RET) {
        // Sets return value
            fprintf(outfile, "\tmovl  $0, %%eax\n");
            // Resets stack frame
            fprintf(outfile, "\tleave\n");
            // Returns
            fprintf(outfile, "\tret\n\n");
    }

    // Prints size of function
    fprintf(outfile, "\t.size  %s, .-%s\n\n", func_name, temp_block->bb_name);

} 