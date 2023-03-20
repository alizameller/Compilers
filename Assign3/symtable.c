#include "symtable.h"
#define CAPACITY 1319 // random num

symbol_table *new_symbol_table(enum name_space namespace) {
    // Creates symbol table struct
    symbol_table *table_ptr;
    if(!(table_ptr = calloc(1, sizeof(symbol_table)))) { // if calloc returns NULL
        // ERROR
    }
    
    // Set entries
    table_ptr->nameSpace = namespace;
    table_ptr->size = 0;
    table_ptr->capacity = CAPACITY;

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

void deleteTable(scope *scopeName, enum name_space nameSpace) {
    symbol_table *symTable = scopeName->symbolTables[nameSpace];
    for(int i = 0; i < symTable->capacity; i++) {
        free(symTable);
    }
}

void deleteScope(scope *scopeName) {
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
