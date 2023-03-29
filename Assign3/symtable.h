#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "ast.c"
/* Data Structure of Symbol Table:

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

typedef enum symbolType {
    VARIABLE_SYMBOL,
    FUNCTION_SYMBOL,
    TYPEDEF_SYMBOL,
    SUTAG_SYMBOL,
    MEMBER_SYMBOL, 
    ENUMTAG_SYMBOL,
    ENUM_SYMBOL,
    LABEL_SYMBOL
} symbolType;

// Variable Symbol
struct variable_symbol {
    astnode *type;
    int offset;
} variable_symbol;

// Function Symbol
struct function_symbol {
    astnode *type; // return type
    int argType;
} function_symbol;

// Struct/Union Member Symbol
struct member_symbol {
    int isStruct; // 0 = is Union, 1 = is Struct
    int type;
    int offset; // in struct only
    int bit_field_width;
    int bit_offset;
} member_symbol;

// Struct/Union Tag Symbol
struct su_tag_symbol {
    struct symbol **su_symbol_table; // array of symbols (of type member_symbol)
} su_tag_symbol;

// Enum Tag Symbol
struct enum_tag_symbol {
    struct symbol *constant; // pointer to enum constant?
} enum_tag_symbol;

// Enum Symbol
struct enum_symbol {
    int value;
    struct symbol *tag; // pointer to enum tag?
} enum_symbol;

// Label Symbol
struct label_symbol {
    char *assembly_label;
} label_symbol;

//  Typedef Symbol
struct type_def_symbol {
    // type of symbol
} type_def_symbol;

// Generic Symbol
typedef struct symbol {
    char *key;    // hash value/ident
    int line;     // line number
    symbolType sym_type; // enum for type of symbol
    
    enum name_space nameSpace;
    astnode *dec_specs; // declaration specifiers
    
    // possible types of IDENT symbols
    union {
        struct variable_symbol var;
        struct function_symbol func;
        struct type_def_symbol tdef;
        struct su_tag_symbol suTag;
        struct member_symbol mem;
        struct enum_tag_symbol enumTag;
        struct enum_symbol eNum;
        struct label_symbol label;
    }; 
} symbol;

// Symbol Table Struct -- Implemented as a hashtable 
typedef struct symbol_table {
    //enum name_space nameSpace;
    int filled; 
    int capacity;
    symbol **data; 
} symbol_table;

// Scope Struct -- Implemented as a stack (linked list)
typedef struct scope {
    enum scope_name name;
    symbol_table *symbolTables[4];
    struct scope *parent;
} scope;

// initialize global variables for scope list (or scope stack struct?)
scope *current = NULL;

// create symbol
symbol *new_symbol(char *ident, enum name_space ns, astnode *type_ptr, symbolType symType);
// free symbol 
void free_symbol(symbol *sym);

// create symbol table 
symbol_table *new_symbol_table();

// free symbol table 
void free_symbol_table(symbol_table *symTable);

// hash the ident and return hash value (position in array of pointers to symbols)
int hash(char *ident, int capacity);

// if a symbol with the name does not already exist, insert a new 
//      symbol and return 1 (TRUE)
// else, no changes should be made and insert should return 0 (FALSE)
// - calls hash
int insert_symbol(symbol_table *symTable, symbol *sym);
// if a binding with the key (pKey) exists, remove that binding from the 
//      symbol table and return 1 (TRUE)
// else, no changes should be made and remove should return 0 (FALSE) 
int remove_symbol(symbol_table *symTable, char *ident);

// returns 1 (TRUE) if inputted symTable conrains a binding whose key is pKey
// else, returns 0 (FALSE)
// FIX RETURN TYPE TO BE A POINTER TO A SYMBOL
symbol *contains_symbol(symbol_table *symTable, char *ident);

// get symbol attribute
//void *get_symbol_attribute(symbol_table *symTable, char *ident, void *attribute);

// set symbol attribute
//void *set_symbol_attribute(symbol_table *symTable, char *ident, void *attribute);

// creates new scope and returns a pointer to the new scope
scope *new_scope(enum scope_name s_name, scope *s_parent);

// delete a scope and all its contents
void free_scope();

// initialize scope list (make global)
void init();

// push scope to stack
// calls new scope and updates current 
int push_scope(enum scope_name scopeType);

// pop current scope from stack by calling free_scope
// updates current to parent
void pop_scope();

// starts in current scope calling contains_symbol() in the specific namespace symbol table
// linearlly moves upwards until global is searched
symbol *find_symbol(enum name_space nameSpace, char *ident);

/* Hash Table functions */
// return the symbol with the key (pKey) if it exists
// else, return NULL
// symbol *get(symbol_table symTable, char *ident);

// get the number of symbols in a symbol table –– error checking purposes?
// int getLength(symbol_table *symTable);

// functions pertaining to bindings in symbol table
//unsigned int hash(char * &key); //get hash value for specific key

//int findPos(char * &key);

//void *getPointer(char * &key, int *b); // int b = bool

//int setPointer(char * &key, void *pv);

//int rehash(); // returns 1 if success, 0 if fail

//static unsigned int getPrime(int size);

#endif //SYMTABLE_H