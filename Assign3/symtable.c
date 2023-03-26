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
    // Creates the symbol.
    symbol* sym = new_symbol(ident);

    // Computes the index using the hash function.
    int index = hash(ident, CAPACITY);

    symbol* current_symbol = symTable->data[index];

    // check for attempted redeclaration
    if (current_symbol != NULL) {
        if (!strcmp(current_symbol->key, ident)) { // strcmp returns 0 if same
            printf("error cannot re-declare %s\n", ident);
            return 0;
        }

        while (strcmp(current_symbol->key, ident)) { // ident is not the same as key
            // HashTable is full
            if (symTable->filled == symTable->capacity) {
                printf("Insert Error: Hash Table is full\n");
                free_symbol(sym);
                return 0;
            }

            // Linear Probing
            index++; 
            symbol* current_symbol = symTable->data[index];

            if (current_symbol == NULL) { // check if symbol at new index is NULL
                //printf("%d\n", index);
                break;
            }
        }
    } 

    if (symTable->filled == symTable->capacity) {
        // HashTable is full.
        printf("Insert Error: Hash Table is full\n");
        free_symbol(sym);
        return 0;
        }

    // Insert
    symTable->data[index] = sym;
    symTable->filled++;

    return 1;
}

int contains_symbol(symbol_table *symTable, char *ident) {
    // Searches for the key in the HashTable.
    int index = hash(ident, CAPACITY);
    symbol* sym = symTable->data[index];

    if (sym == NULL) {
        return 0; 
    } else {
        while (strcmp(sym->key, ident)){ // key is not the same as ident
            index++;
            symbol* sym = symTable->data[index];
            if (sym == NULL) {
                return 0; // cannot find symbol in symbol table
            } else {
                break;
            }
        }
    }

    return 1;

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
    if(!(scope_ptr = (scope*) malloc(sizeof(scope *)))) { // if malloc returns NULL
        // ERROR
    }

    // Set entries
    scope_ptr->name = s_name;
    scope_ptr->parent = current;
    for(int i = TAGS; i == OTHER; i++) {
        scope_ptr->symbolTables[i] = NULL; 
    }
    return scope_ptr;
}

void free_scope() {
    for(int i = TAGS; i == OTHER; i++) {
        free_symbol_table(current->symbolTables[i]);
    }
    free(current);
}

void init() {
    current = new_scope(GLOBAL, NULL);
    printf("global scope %d\n", current->name);
    return;
}

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
    init();
    printf("current scope is %d\n", current->name);
    push_scope(PROTOTYPE_SCOPE);
    printf("current scope is %d\n", current->name);
    printf("scope parent is %d\n", (current->parent)->name);

    push_scope(FILE_SCOPE);
    printf("current scope is %d\n", current->name);
    printf("scope parent is %d\n", (current->parent)->name);

    /*
    current->symbolTables[TAGS] = new_symbol_table();
    char *ident = "hello";

    if (insert_symbol(current->symbolTables[TAGS], ident)) {
        printf("%s was inserted\n", ident);
    } else {
        printf("%s was not inserted\n", ident);
    }

    if (contains_symbol(current->symbolTables[TAGS], "hello")) {
        printf("table contains hello\n");
    } else {
        printf("table does not contain hello\n");
    }
    
    symbol_table *temp = current->symbolTables[TAGS];
    int index = hash("hello", CAPACITY);
    printf("%s is in TAGS symbol table in scope %d\n",  (temp->data[index])->key, current->name);
    */

    pop_scope();
    printf("scope parent is %d\n", (current->parent)->name);
    printf("popped scope, current scope is %d\n", current->name);
    pop_scope();
    printf("popped scope, current scope is %d\n", current->name);

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
