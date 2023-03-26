#include "symtable.h"
#define CAPACITY 1319 // random num
#include <stdio.h>
#include <string.h>

symbol *new_symbol(char *ident) {
    // Creates a pointer to a new HashTable item.
    symbol* sym = (symbol*) malloc(sizeof(symbol));

    if (!sym) {
        printf("Error mallocing symbol for %s failed\n", ident);
    }
    sym->key = strdup(ident);
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

    hashVal = 1302;

    return hashVal;
}

int insert_symbol(symbol_table *symTable, char *ident) {
    // HashTable is full
    if (symTable->filled == symTable->capacity) {
        printf("Insert Error: Hash Table is full\n");
        return 0;
    }

    // Creates the symbol.
    symbol* sym = new_symbol(ident);

    // Computes the index using the hash function.
    int index = hash(ident, CAPACITY);

    symbol* current_symbol = symTable->data[index];

    // check for attempted redeclaration
    if (current_symbol != NULL) {
        if (!strcmp(current_symbol->key, ident)) { // strcmp returns 0 if same
            printf("Error: Cannot Re-declare %s\n", ident);
            return 0;
        }

        while (strcmp(current_symbol->key, ident)) { // ident is not the same as key
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
    } else {
        while (strcmp(sym->key, ident)){ // key is not the same as ident
            index++;
            symbol* sym = symTable->data[index];
            if (sym == NULL) {
                return NULL; // cannot find symbol in symbol table
            } else {
                break;
            }
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
    for(int i = 0; i <= 3; i++) {
        free_symbol_table(current->symbolTables[i]);
    }
    free(current);
}

/* void init() {
    current = new_scope(GLOBAL, current);
    return;
} */

int push_scope(enum scope_name scopeType) {
    scope *scope_ptr = new_scope(scopeType, current);
    if (!scope_ptr) { // new_scope returned NULL
        return 0; // did not push scope to stack
    }
    current = scope_ptr; 

    return 1; 
}

void pop_scope() {
    scope *temp = current->parent;
    free_scope();
    current = temp; 
}

int main() {
    push_scope(GLOBAL);
    printf("current scope is %d\n", current->name);
    push_scope(PROTOTYPE_SCOPE);
    printf("current scope is %d\n", current->name);
    push_scope(FILE_SCOPE);
    printf("current scope is %d\n", current->name);

    char *ident = "hello";
    
    if (insert_symbol(current->symbolTables[TAGS], ident)) {
        printf("%s was inserted\n", ident);
    } else {
        printf("%s was not inserted\n", ident);
    }
    
    symbol *temp;
    if ((temp = contains_symbol(current->symbolTables[TAGS], "hello"))) {
        printf("table contains %s\n", temp->key);
    } else {
        printf("table does not contain %s\n", temp->key);
    }

    printf("Popping current scope, scope %d\n", current->name);
    pop_scope();
    printf("Scope popped\n");
    printf("Popping current scope, scope %d\n", current->name);
    pop_scope();
    printf("Scope popped\n");
    printf("Current scope is %d\n", current->name);

    /*
    symbol_table *table = new_symbol_table();
    char *ident = "hello";

    if (insert(table, ident)) {
        printf("%s was inserted\n", ident);
    } else {
        printf("%s was not inserted\n", ident);
    }

    ident = "new";
    
    if (insert(table, ident)) {
        printf("%s was inserted\n", ident);
    } else {
        printf("%s was not inserted\n", ident);
    }

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
    } */

    return 0;
}
