#include "assembly.h"

void generate_assembly(char *out) {
    int i;
    for (i = 0; i < NUM_REGISTERS; i++) {
        regs[i] = NO_REG; //initialize register array to NO_REG (available for use)
    }
    if (!block_cursor) {
        outfile = fopen(out, "w");
        // creating file with string info if there are any strings present
        stringfile = fopen("string.S", "w");
        fprintf(stringfile, "\t.section .rodata\n");

        fprintf(outfile, "\t.file\t\"%s\"\n", "test.c"); //place holder, should be name of c file
        generate_globals();
        fprintf(outfile, "\t.text\n");
    }
    generate_funcs();

    fclose(stringfile);
    stringfile = fopen("string.S", "r");
    // copy over contents from stringfile to outfile
    char c = fgetc(stringfile);
    while(c != EOF) {
        fputc(c, outfile);
        c = fgetc(stringfile);
    }
}

void generate_globals() {
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
    // fprintf(stderr, "name of func is %s\n", f_name);
    symbol *sym_temp;
    int offset = 0;

    scope *f_scope = current; 
    while (f_scope) {
        //fprintf(stderr, "scope name is %s\n", f_scope->scope_fileName);
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

void if_string(struct quad_list_item *quad) {
    if(quad->src1 && quad->src1->generic.type == STRING_NODE) {
            
            fprintf(stringfile, ".LC%d:\n", f); //matches function number
            fprintf(stringfile, "\t.string  \"%s\"\n", quad->src1->str.string_literal); //copies over newline as literal newline

            // Changes src -> string memory location
            astnode *temp_reg = reserve_registers(NULL);
            fprintf(outfile, "\tleal  .LC%d, %s\n", f, print_assemblyType(temp_reg));
            quad->src1 = temp_reg;
        }
        if(quad->src2 && quad->src2->generic.type == STRING_NODE) {
            
            fprintf(stringfile, "LC%d:\n", f); //matches function number
            fprintf(stringfile, "\t.string  \"%s\"\n", quad->src2->str.string_literal);

            // Changes src -> string memory location
            astnode *temp_reg = reserve_registers(NULL);
            fprintf(outfile, "\tleal  LC%d, %s\n", f, print_assemblyType(temp_reg));
            quad->src2 = temp_reg;
        }
}

basic_block *generate_blocks(basic_block *block) {
    while (block) {
        if(block->assembled) {
            block = block->next_bb;
        }

        fprintf(outfile, "%s:\n", block->bb_name);

        quad_list_item *temp_quad = block->head_quad;
        while (temp_quad) {
            generate_quad_assembly(temp_quad);
            prev = temp_quad;
            temp_quad = temp_quad->next_quad;
        }
        
        if (block->branch_condition >= BR && block->branch_condition <= BRGE) {
            if (block->branch_condition == BR) {
                    generate_jump(block);
                    //printf("\t\t\t%s %s\n", printOp(block->branch_condition), block->branch_bb->bb_name);
                } else {
                    generate_jump(block);
                    //printf("\t\t\t%s %s, %s\n", printOp(block->branch_condition), block->next_bb->bb_name, block->branch_bb->bb_name);
                }
            if ((block->branch_bb && block->next_bb) && (block->branch_condition != BR) ) {
                block->next_bb->next_bb = block->branch_bb;
            }
            if ((block->branch_bb && !block->next_bb) && (block->branch_condition == BR)) {
                block->next_bb = block->branch_bb;
            }
        }

        block = block->next_bb;
    }
}

void generate_quad_assembly(quad_list_item *quad) {
    char *temp = "temp";
    // if string -> create separate file and insert at beginning of file?
    if (quad->dest && quad->dest->generic.type == TEMPORARY_NODE) {
        quad->dest = reserve_registers(quad->dest);
    }
    // if src1 or src2 are strings, the respective info is added to stringfile to later be added to outfile
    if_string(quad);

    // Checks op code
    //fprintf(stderr, "opode is %d\n", quad->op_code);
    switch(quad->op_code) {
        // astnode for temporary register
        union astnode *temp_reg;

        case LOAD: //there is a problem with load
            temp_reg = reserve_registers(NULL);
            union astnode *temp_reg2 = reserve_registers(NULL);
            if (quad->src1->generic.type == SYMBOL_POINTER_NODE && quad->src1->sym_p.sym->dec_specs->decspec.s_class == EXTERN_CLASS) {
                fprintf(outfile, "\tmovl  $%s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            } else {
                fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            }
            fprintf(outfile, "\tmovl  (%s), %s\n", print_assemblyType(temp_reg), print_assemblyType(temp_reg2));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg2), print_assemblyType(quad->dest));

            free_register(temp_reg2);
            free_register(temp_reg);

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

            temp_reg = reserve_registers(NULL);
            
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            if (quad->src2->generic.type == TEMPORARY_NODE) {
                fprintf(outfile, "\tmovl  %s, (%s)\n", print_assemblyType(temp_reg), print_assemblyType(quad->src2));
            } else {
                fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->src2));
            }
            
            free_register(temp_reg);

            break;

        case LEA:
            temp_reg = reserve_registers(NULL);

            fprintf(outfile, "\tleal  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->src1));
        
            free_register(temp_reg);
            
            break;

        case MOV:
            temp_reg = reserve_registers(NULL);
    
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));

            free_register(temp_reg);
            break;

        case ADD:
            temp_reg = reserve_registers(NULL);

            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\taddl  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            free_register(temp_reg);

            break;

        case SUB:
            temp_reg = reserve_registers(NULL);

            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\tsubl  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            free_register(temp_reg);

            break;

        case MUL:
            temp_reg = reserve_registers(NULL);

            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(temp_reg));
            fprintf(outfile, "\timull  %s, %s\n", print_assemblyType(quad->src2), print_assemblyType(temp_reg));
            fprintf(outfile, "\tmovl  %s, %s\n", print_assemblyType(temp_reg), print_assemblyType(quad->dest));
            
            free_register(temp_reg);

            break;
        
        case CMP:
            if (quad->next_quad == quad) {quad->next_quad = NULL;}
            fprintf(outfile, "\tcmpl  %s, %s\n", print_assemblyType(quad->src1), print_assemblyType(quad->dest));
            break;

        case RET:
            if(quad->src1) {
                fprintf(outfile, "\tmovl  %s, %%eax\n", print_assemblyType(quad->src1));
                fprintf(outfile, "\tleave\n");
                fprintf(outfile, "\tret\n");
            }
            
            break;

        case ARG:
            // need to reverse order of args ?
            fprintf(outfile, "\tpushl  %s\n", print_assemblyType(quad->src1));
            break;

        case CALL:
            fprintf(outfile, "\tcall  %s\n", quad->src1->id.ident);
            // reset stack pointer
            //fprintf(stderr, "src2 type is %d\n", quad->src2->generic.type);
            if(quad->src2->num.numInfo.value.int_val > 0) { // at least one argument
                fprintf(outfile, "\taddl  $%lld, %%esp\n", quad->src2->num.numInfo.value.int_val * sizeof(int)); 
            }

            // Moves to target, if needed
            if(quad->dest) {
                fprintf(outfile, "\tmovl  %%eax, %s\n", print_assemblyType(quad->dest));
            } 

            break; 

    }

    // Frees registers used by sources
    free_register(quad->src1);
    free_register(quad->src2);
}

void generate_jump(basic_block *temp_block) {
    switch(temp_block->branch_condition) {
        // inversion applies so that branched block is the jumped to one
        case BREQ:
            fprintf(outfile, "\tjne  %s\n", temp_block->branch_bb->bb_name);
            break;

        case BRNEQ:
            fprintf(outfile, "\tje  %s\n", temp_block->branch_bb->bb_name);
            break;
            
        case BRLT:
            fprintf(outfile, "\tjge  %s\n", temp_block->branch_bb->bb_name);
            break;

        case BRGT:
            fprintf(outfile, "\tjle  %s\n", temp_block->branch_bb->bb_name);
            break;
            
        case BRLE:
            fprintf(outfile, "\tjg  %s\n", temp_block->branch_bb->bb_name);
            break;
            
        case BRGE:
            fprintf(outfile, "\tjl  %s\n", temp_block->branch_bb->bb_name);
            break;
            
        default:
            fprintf(outfile, "\tjmp  %s\n", temp_block->branch_bb->bb_name);
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

void free_register(union astnode *temp_reg) {
    if(temp_reg == NULL) {
        return;
    }

    if(temp_reg->generic.type == TEMPORARY_NODE && temp_reg->temp.reg != NO_REG) {
        regs[temp_reg->temp.reg] = NO_REG;
        temp_reg->temp.reg = NO_REG;
    }
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
    } else if (node->num.numInfo.value.int_val){ // weird situation -- it has type TERNOP (in while loops only)
        sprintf(assembly, "$%lld", node->num.numInfo.value.int_val);
    }
    //fprintf(stderr, "%s\n", assembly);
    return assembly;
}

void generate_funcs() {
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
    basic_block *end = generate_blocks(temp_block);
    temp_block->assembled = 1; 
    // if no explicit return, return 0
    if(block_list->tail->head_quad && block_list->tail->branch_condition != RET) {
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