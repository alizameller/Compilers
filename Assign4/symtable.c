#include "symtable.h"
#define CAPACITY 1319 // random num

symbol *new_symbol(char *ident, enum name_space ns, union astnode *decspec_ptr, union astnode *type_ptr, symbolType symType) {
    // Creates a pointer to a new HashTable item.
    symbol* sym = (symbol*) malloc(sizeof(symbol));

    if (!sym) {
        printf("Error mallocing symbol for %s failed\n", ident);
    }

    sym->key = strdup(ident);
    sym->nameSpace = ns;
    sym->sym_type = symType;
    sym->dec_specs = decspec_ptr; // contains info on storage class, type spec, type qualifier  
    sym->type_rep = type_ptr;
    sym->next = NULL;
    sym->line = report.lineNum;
    sym->filename = report.fileName;

    return sym;
}

symbol_table *new_symbol_table() {
    // Creates symbol table struct
    symbol_table *table_ptr;
    if(!(table_ptr = (symbol_table *) malloc(sizeof(symbol_table)))) { // if malloc returns NULL
        // ERROR
    }
    
    // Set entries
    //table_ptr->nameSpace = namespace;
    table_ptr->filled = 0;
    table_ptr->capacity = CAPACITY;
    table_ptr->data = (symbol**) calloc(table_ptr->capacity, sizeof(symbol*));

    for (int i = 0; i < table_ptr->capacity; i++) {
        table_ptr->data[i] = NULL;
    }

    return table_ptr;
}

void free_symbol(symbol *sym) {
    // Frees a symbol
    free(sym->key);
    free(sym);
}

void free_symbol_table(symbol_table *symTable) {
    // Frees the table.
    for (int i = 0; i < CAPACITY; i++) {
        symbol* sym = symTable->data[i];

        if (sym) {
            free_symbol(sym);
        }
    }

    free(symTable->data);
    free(symTable);
}

int hash(char *ident, int capacity) {
    int hashVal = 0;

    for (int i = 0 ;i < strlen(ident) ; ++i)
        hashVal = 37*hashVal + ident[i];

    hashVal %= capacity;

    if (hashVal < 0)
        hashVal += capacity;

    return hashVal;
}

int compare_symbols(symbol *sym, symbol *current) {    
    if (current->dec_specs && sym->dec_specs) {
        if ((current->dec_specs)->decspec.q_type != (sym->dec_specs)->decspec.q_type &&
            (current->dec_specs)->decspec.s_class != (sym->dec_specs)->decspec.s_class) {
                return 0;
            }
        if (current->dec_specs->decspec.s_type && sym->dec_specs->decspec.s_type) {
            if ((current->dec_specs)->decspec.s_type->scalar.scalarType != 
            (sym->dec_specs)->decspec.s_type->scalar.scalarType) {
                return 0;
            }
        }
    }
    if (current->type_rep) {
        if ((current->type_rep)->generic.type != (sym->type_rep)->generic.type) {
            return  0;
        }
    }

    return 1;
}

int insert_symbol(symbol_table *symTable, symbol *sym) {
    // HashTable is full

    if (symTable->filled == symTable->capacity) {
        fprintf(stderr, "Insert Error: Hash Table is full\n");
        return 0;
    }

    // Computes the index using the hash function.
    int index = hash(sym->key, CAPACITY);  
    symbol* current_symbol = symTable->data[index];

    // check for attempted redeclaration
    if (current_symbol) {
        if (!strcmp(current_symbol->key, sym->key)) { // strcmp returns 0 if same
            if (!(current_symbol->sym_type == sym->sym_type &&
                current_symbol->nameSpace == sym->nameSpace &&
                compare_symbols(sym, current_symbol))) {
                    fprintf(stderr, "Error: Cannot Re-declare %s\n", sym->key);
                    return 0;
            }
            printf("***Declaration of %s is compatible with previous declaration***\n", current_symbol->key);
            return 1;
        }

        while (strcmp(current_symbol->key, sym->key)) { // ident is not the same as key
            // Linear Probing
            index++; 
            symbol* current_symbol = symTable->data[index];

            if (current_symbol == NULL) { // check if symbol at new index is NULL
                //printf("%d\n", index);
                break;
            }
        }
    } 

    // Insert
    symTable->data[index] = sym;
    symTable->filled++;

    return 1;
}

symbol *contains_symbol(symbol_table *symTable, char *ident) {
    // Searches for the key in the HashTable.
    int index = hash(ident, CAPACITY);
    symbol* sym = symTable->data[index];

    if (sym == NULL) {
        return NULL; 
    } 
    
    while (strcmp(sym->key, ident)){ // key is not the same as ident
        index++;
        symbol* sym = symTable->data[index];
        if (sym == NULL) {
            return NULL; // cannot find symbol in symbol table
        } else {
            break;
        }
    }

    return sym;

}

int remove_symbol(symbol_table *symTable, char *ident) {
    int index = hash(ident, CAPACITY);
    symbol *sym = symTable->data[index];

    if (!sym) { // symbol does not exist
        return 0;
    } else { // symbol does exist
        symTable->data[index] = NULL;
        free_symbol(sym);
        symTable->filled--;
        return 1;
    }
}

scope *new_scope(enum scope_name s_name, scope *s_parent) {
    // Creates scope struct
    scope *scope_ptr;
    if(!(scope_ptr = (scope*) malloc(sizeof(scope)))) { // if malloc returns NULL
        fprintf(stderr, "Error: cannot malloc scope\n");
        exit(1);
    }

    // Set entries
    scope_ptr->name = s_name;
    scope_ptr->parent = s_parent;
    for(int i = 0; i <= 3; i++) {
        scope_ptr->symbolTables[i] = new_symbol_table(); 
    }

    return scope_ptr;
}

void free_scope() {
    for(int i = 0; i <= 3; i++) { // TAGS to OTHER
        free_symbol_table(current->symbolTables[i]);
    }
    free(current);
}

int push_scope(enum scope_name scopeType) {
    scope *scope_ptr = new_scope(scopeType, current);
    if (!scope_ptr) { // new_scope returned NULL
        return 0; // did not push scope to stack
    }
    current = scope_ptr; 
    current->scope_fileName = report.fileName;
    current->scope_lineNum = report.lineNum - 1; //off by one for some reason
    
    return 1; 
}

void pop_scope() {
    scope *temp = current->parent;
    free_scope();
    current = temp; 
}

scope *find_symbol(enum name_space nameSpace, char *ident) {
    if (!current) { // current is NULL, have yet to push any scopes
        fprintf(stderr, "Error: Cannot find symbol because there is no scope to search\n");
        return NULL; 
    }

    scope *ptr = current; 
    symbol *sym;

    while (ptr) {
        sym = contains_symbol(ptr->symbolTables[nameSpace], ident);
        if (sym) {
            //printf("Symbol %s found in scope %d\n", sym->key, ptr->name);
            break;
        }
        ptr = ptr->parent;
    }

    return ptr; // returns null if symbol is not found in any scope
}

symbol *add_astnode_to_symbol(symbol *sym, union astnode* node) {
    if (node->generic.type == DECSPEC_NODE) {
        sym->dec_specs = node;
    } else {
        switch(node->generic.type) {
            case POINTER_NODE:
                sym->type_rep = node;
                break;
            case ARRAY_NODE:
                sym->type_rep = node;
                break;
            case FUNCTION_DEF_NODE:
                /*if (sym->type_rep && sym->type_rep->generic.type == POINTER_NODE) { //short circuiting
                    union astnode *temp_sym = sym->type_rep;
                    while(temp_sym->ptr.parent) {
                        temp_sym = temp_sym->ptr.parent;
                    } 
                    temp_sym->ptr.parent = node;
                    break;
                } */
                sym->type_rep = node;
                
                break; 
        }
    }

    return sym; 
}


symbol *modify_symbol_type(symbol *sym, symbolType type) {
    sym->sym_type = type; 

    return sym;
}

symbol *append_symbol_list(symbol *sym, symbol *addition) {
    sym->next = addition; 

    return addition;
}

void checkArrayType(union astnode *temp, symbol *sym) {
    while (temp->arr.element_type) { // if element type of array is array
        temp = sym->type_rep->arr.element_type;
    }
    temp->arr.element_type = sym->dec_specs; // set element type of innermost array to dec specs
}

union astnode *merging(symbol *sym) {
    union astnode *ptr = new_astnode_symbol_pointer(SYMBOL_POINTER_NODE, sym);
    if (ptr->sym_p.sym->sym_type == FUNCTION_SYMBOL) {
        // create function def node
        union astnode *fn_type = new_astnode_fndef(FUNCTION_DEF_NODE, NULL, NULL);
        
        if (sym->type_rep && sym->type_rep->generic.type == FUNCTION_DEF_NODE) {
            union astnode *temp = sym->type_rep;
            while (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == FUNCTION_DEF_NODE) { // if ret type of function is function
                temp = temp->fndef.ret_type;
            }
            if (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == POINTER_NODE) { // if ret type of function is pointer
                // assume only one pointer to function is allowed
                if (temp->fndef.ret_type->ptr.parent && temp->fndef.ret_type->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if pointer points to function
                    temp->fndef.ret_type->ptr.parent->fndef.ret_type = sym->dec_specs;
                } else { // if pointer does not point to function, assume it points to scalar
                    temp->fndef.ret_type->ptr.parent = sym->dec_specs;
                }
            } else if (temp->fndef.ret_type && temp->fndef.ret_type->generic.type == ARRAY_NODE) { // if ret type of function is array
                    temp->fndef.ret_type->arr.element_type = sym->dec_specs; // set element type to dec specs
            } else {
                temp->fndef.ret_type = sym->dec_specs; // set return type of innermost function to dec specs
            }
            // set the ret_type = fnc def node
            (fn_type->fndef).ret_type = sym->type_rep;
// -------------------------------------------------------------------------------------------- for visual ease            
        } else if (sym->type_rep && sym->type_rep->generic.type == ARRAY_NODE) { 
            union astnode *temp = sym->type_rep;
            while (temp->arr.element_type) { // if element type of array is array
                temp = sym->type_rep->arr.element_type;
            }
            temp->arr.element_type = sym->dec_specs; // set element type of innermost array to dec specs
            //change the fndef.ret_type = array node
            (fn_type->fndef).ret_type = sym->type_rep; 
            // change astnode type to function def
            add_astnode_to_symbol(sym, fn_type);
    // -------------------------------------------------------------------------------------------- for visual ease       
        } else if (sym->type_rep && sym->type_rep->generic.type == POINTER_NODE) {
            union astnode *temp = sym->type_rep;
            while (temp->ptr.parent && (temp->ptr.parent->generic.type == POINTER_NODE)) { // if parent of pointer is a pointer
                temp = sym->type_rep->ptr.parent;
            }
            if (temp->ptr.parent && temp->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if type is pointer to ... function, set ret type
                temp->ptr.parent->fndef.ret_type = sym->dec_specs;
            } else {
                temp->ptr.parent = sym->dec_specs; // set parent type of innermost pointer to dec specs
            }
            //change the fndef.ret_type = pointer node
            (fn_type->fndef).ret_type = sym->type_rep; 
            // change astnode type to function def
            add_astnode_to_symbol(sym, fn_type);
        // -------------------------------------------------------------------------------------------- for visual ease    
        } else {
            // set ret type of fn_type to dec specs if astnode type is not already set
            (fn_type->fndef).ret_type = sym->dec_specs;
            // change astnode type to function def
            add_astnode_to_symbol(sym, fn_type);
        }
    /* JUST A DECLARATION NOT FUNCTION DECLARATION */ 
    } else {
        // if array, make element type the decspec 
        if (sym->type_rep && sym->type_rep->generic.type == ARRAY_NODE) {
            union astnode *temp = sym->type_rep;
            while (temp->arr.element_type) { // if element type of array is array
                temp = sym->type_rep->arr.element_type;
            }
            temp->arr.element_type = sym->dec_specs; // set element type of innermost array to dec specs
        } else if (sym->type_rep && sym->type_rep->generic.type == POINTER_NODE) {
            union astnode *temp = sym->type_rep;
            while (temp->ptr.parent && (temp->ptr.parent->generic.type == POINTER_NODE)) { // if parent of pointer is a pointer
                temp = sym->type_rep->ptr.parent;
            }
            if (temp->ptr.parent && temp->ptr.parent->generic.type == FUNCTION_DEF_NODE) { // if type is pointer to ... function, set ret type
                temp->ptr.parent->fndef.ret_type = sym->dec_specs;
            } else if (temp->ptr.parent && (temp->ptr.parent->generic.type == ARRAY_NODE)){ // if type is pointer to array
                checkArrayType(temp, sym);
            } else {
                temp->ptr.parent = sym->dec_specs; // set parent type of innermost pointer to dec specs
            }
        } else if (sym->type_rep && sym->type_rep->generic.type == FUNCTION_DEF_NODE) {
            union astnode *temp = sym->type_rep;
            while (temp->fndef.ret_type) { // if ret type of function is function
                temp = sym->type_rep->fndef.ret_type;
            }
            temp->fndef.ret_type = sym->dec_specs; // set return type of innermost function to dec specs
        }
    }

    return ptr;
}


/*int main() {
    current = NULL;
    push_scope(FILE_SCOPE);
    printf("current scope is %d\n", current->name);
    char *ident = "hello";
    symbol *sym = new_symbol(ident, OTHER, NULL, VARIABLE_SYMBOL);
    printf("symbol created, key is %s\n", sym->key);
    insert_symbol(current->symbolTables[OTHER], sym);
    union astnode *scalarNode = new_astnode_scalar(SCALAR_NODE, VOID_TYPE);
    union astnode *decNode = new_astnode_declaration_spec(DECSPEC_NODE, scalarNode, 0, 0);
    add_astnode_to_symbol(sym, decNode);
    symbol *cur = contains_symbol(current->symbolTables[OTHER], sym->key);
    if (cur) {
        printf("type is %d\n", ((cur->dec_specs)->decspec.s_type)->scalar.scalarType);
    }

    return 0;
} */
