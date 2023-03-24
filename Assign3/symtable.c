#include "symtable.h"
#define CAPACITY 1319 // random num
#include <stdio.h>
#include <string.h>

symbol *new_symbol(char *key) {
    // Creates a pointer to a new HashTable item.
    symbol* sym = (symbol*) malloc(sizeof(symbol));
    sym->key = (char*) malloc(strlen(key) + 1);
    strcpy(sym->key, key);

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

    for (int i = 0; i < table_ptr->capacity; i++)
        table_ptr->data[i] = NULL;


    return table_ptr;
}

void free_symbol(symbol *sym) {
    // Frees a symbol
    free(sym->key);
    free(sym->value);
    free(sym);
}

void free_symbol_table(symbol_table *symTable) {
    // Frees the table.
    for (int i = 0; i < symTable->capacity; i++) {
        symbol* sym = symTable->data[i];

        if (sym != NULL)
            free_symbol(sym);
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

int insert(symbol_table *symTable, char *ident) {
    // Creates the symbol.
    symbol* sym = new_symbol(ident);

    // Computes the index using the hash function.
    int index = hash(ident, CAPACITY);

    symbol* current_symbol = symTable->data[index];

    if (current_symbol == NULL) {
        // Key does not exist.
        if (symTable->filled == symTable->capacity) {
            // HashTable is full.
            printf("Insert Error: Hash Table is full\n");
            free_symbol(sym);
            return 0;
        }

        // Insert directly.
        symTable->data[index] = sym;
        symTable->filled++;
        return 1;
    } else {
        // Scenario 1: trying to hash same value -- ERROR cannot redeclare same ident
        if (!strcmp(current_symbol->key, ident)) { // if they are the same
            return 1;
        } else { 
        // Handle collision
        
            return 0;
        }
    }
}

int contains(symbol_table *symTable, char *ident) {
    // Searches for the key in the HashTable.
    int index = hash(ident, CAPACITY);
    symbol* sym = symTable->data[index];

    // Provide only non-NULL values.
    if (sym != NULL) {
        if (strcmp(sym->key, ident) == 0)
            return 1;
    }

    return 0;

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
    if(!(scope_ptr = calloc(1, sizeof(scope)))) { // if calloc returns NULL
        // ERROR
    }

    // Set entries
    scope_ptr->name = s_name;
    scope_ptr->parent = s_parent;

    return scope_ptr;
}

void free_scope(scope *scopeName) {
    for(int i = 1; i == 4; i++) {
        free_symbol_table(scopeName->symbolTables[i]);
    }
    free(scopeName);
}

int main() {
    symbol_table *table = new_symbol_table();
    char *ident = "hello";
    insert(table, ident);
    int index = hash(ident, CAPACITY);
    printf("%s\n", (table->data[index])->key);

    if (contains(table, "hello")) {
        printf("table contains hello\n");
    } else {
        printf("table does not contain hello\n");
    }

    remove_symbol(table, "hello");

     if (contains(table, "hello")) {
        printf("table contains hello\n");
    } else {
        printf("table does not contain hello\n");
    }

    return 0;
}
