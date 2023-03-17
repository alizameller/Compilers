#ifndef SYMTABLE_H
#define SYMTABLE_H

/* 

    Stack
|           |
|  scope 2  |
|___________|     hashtable   hashtable  hashtable  hashtable 
|  scope 1  | -> |___NS 1___|___NS 2___|___NS 3___|___NS 4___|
|___________|         ↓           ↓          ↓         ↓
|   global  |      x, y, z     a, c, x       x      z, a, x 
_____________

- Stack consists of scopes from outermost to innermost 
- Each scope entry consists of four hashtables for each namespace that consist of 
the symbols

*/
enum scope_name {
    FILE_SCOPE,
    BLOCK_SCOPE,
    FUNCTION_SCOPE,
    PROTOTYPE_SCOPE
};

enum name_space {
    TAGS,
    LABELS,
    MEMBERS,
    OTHER
};

// Variable Symbol
struct variable_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} variable_symbol;

// Function Symbol
struct function_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} function_symbol;

//  Symbol
struct typedef_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} typedef_symbol;

// Struct/Union Tag Symbol
struct su_tag_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} su_tag_symbol;

// Struct/Union Member Symbol
struct member_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} member_symbol;

// Enum Tag Symbol
struct enum_tag_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} enum_tag_symbol;

// Enum Symbol
struct enum_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} enum_symbol;

// Label Symbol
struct label_symbol {
    int key; // hash value
    char *name; // copy of name of entry
    /* other info needed () etc. */
} label_symbol;

// Generic Symbol
typedef union symbol {
    struct variable_symbol var;
    struct function_symbol func;
    struct typedef_symbol tdef;
    struct su_tag_symbol suTag;
    struct member_symbol mem;
    struct enum_tag_symbol enumTag;
    struct enum_symbol eNum;
    struct label_symbol label;
} symbol;

// Hash Table Struct
typedef struct hashtable {
    enum name_space nameSpace;
    int size; 
    symbol* symbolTable;
} hashtable;

// Scope Struct
typedef struct scope {
    enum scope_name name;
    hashtable *hashTables[4];
    scope *parent;
} scope;

// creates new symbol table and returns the symbol table 
scope new_scope(void);

// delete a symbol table and all its contents
void deleteTable(scope scopeName);

// get the number of symbols in a symbol table –– error checking purposes?
//int getLength(symbol_table symTable);

// if a symbol with the name does not already exist, insert a new 
//      symbol and return 1 (TRUE)
// else, no changes should be made and insert should return 0 (FALSE)
// Note: make a copy of the name and store the address of that copy within the 
// new binding
int insert(scope scopeName, char *name, int type);

// if a binding with the key (pKey) exists, remove that binding from the 
//      symbol table and return 1 (TRUE)
// else, no chnages should be made and remove should return 0 (FALSE) 
int remove(scope scopeName, const char *pKey);

// returns 1 (TRUE) if inputted symTable conrains a binding whose key is pKey
// else, returns 0 (FALSE)
int contains(scope scopeName, const char *pKey);

// return the symbol with the key (pKey) if it exists
// else, return NULL
symbol *get(scope scopeName, const char *pKey);

// functions pertaining to bindings in symbol table
unsigned int hash(char * &key); //get hash value for specific key

int findPos(char * &key);

void *getPointer(char * &key, int *b); // int b = bool

int setPointer(char * &key, void *pv);

int rehash(); // returns 1 if success, 0 if fail

static unsigned int getPrime(int size);

#endif //SYMTABLE_H