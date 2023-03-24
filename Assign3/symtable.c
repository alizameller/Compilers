#include "symtable.h"
#define CAPACITY 1319 // random num


symbol *new_symbol(char *key, astnode* node) {
    // Creates a pointer to a new HashTable item.
    symbol* sym = (symbol*) malloc(sizeof(symbol));
    sym->key = (char*) malloc(strlen(key) + 1);
    sym->value = node;
    strcpy(sym->key, key);

    return sym;
}

symbol_table *new_symbol_table(enum name_space namespace) {
    // Creates symbol table struct
    symbol_table *table_ptr;
    if(!(table_ptr = (symbol_table *) malloc(sizeof(symbol_table)))) { // if malloc returns NULL
        // ERROR
    }
    
    // Set entries
    table_ptr->nameSpace = namespace;
    table_ptr->filled = 0;
    table_ptr->capacity = CAPACITY;
    table_ptr->data = (symbol**) calloc(table_ptr->capacity, sizeof(symbol*));

    for (int i = 0; i < table_ptr->capacity; i++)
        table_ptr->data[i] = NULL;


    return table_ptr;
}

scope *new_scope(enum scope_name s_name, scope *s_parent) {
    // Creates scope struct
    scope *scope_ptr;
    if(!(scope_ptr = calloc(1, sizeof(scope)))) { // if calloc returns NULL
        // ERROR
    }

    // Set entries
    scope_ptr->name = s_name;
    scope_ptr->parent = s_parent;
}

void free_symbol(symbol *sym) {
    // Frees an item.
    free(sym->key);
    free(sym->value);
    free(sym);
}

void free_symbol_table(symbol_table *symTable) {
    // Frees the table.
    for (int i = 0; i < symTable->capacity; i++) {
        symbol* sym = symTable->data[i];

        if (sym != NULL)
            free_item(sym);
    }

    free(symTable->data);
    free(symTable);
}

void free_scope(scope *scopeName) {
    for(int i = 1; i = 4; i++) {
        deleteTable(scopeName, i);
    }
    free(scopeName);
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

