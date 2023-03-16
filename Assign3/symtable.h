#ifndef SYMTABLE_H
#define SYMTABLE_H

typedef struct symbol_table {
    int size;
    char **data;
} symbol_table;
struct symbol_table symbolTable;

typedef struct symbol {
    char *key;
    int isOccupied; // 1 if yes, 0 if not
    int isDeleted; // 1 if yes, 0 if not
    void *pv; // pointer to...? 
} symbol;

// creates new symbol table and returns the symbol table 
symbol_table new_symbol_table(void);

// delete a symbol table and all its contents
void free(symbol_table symTable);

// get the number of bindings in a symbol table –– error checking purposes?
int getLength(symbol_table symTable);

// if a binding with the key (pKey) does not already exist, insert a new 
//      binding containing pKey and pValue and return 1 (TRUE)
// else, no changes should be made and insert should return 0 (FALSE)
// Note: make a copy of the char *pKey and store the address of that copy within the new binding
int insert(symbol_table symTable, const char *pKey, const void *pValue);

// if a binding with the key (pKey) exists, remove that binding from the 
//      symbol table and return 1 (TRUE)
// else, no chnages should be made and remove should return 0 (FALSE) 
int remove(symbol_table symTable, const char *pKey);

// returns 1 (TRUE) if inputted symTable conrains a binding whose key is pKey
// else, returns 0 (FALSE)
int contains(symbol_table symTable, const char *pKey);

// return the value of the binding, if a binding with the key (pKey) exists
// else, return NULL
void *get(symbol_table symTable, const char *pKey);

void map(symbol_table symTable, 
   void (*pfApply)(const char *pKey, void *pValue, void *pExtra),
const void *pExtra);


// functions pertaining to bindings in symbol table
unsigned int hash(char * &key); //get hash value for specific key

int findPos(char * &key);

void *getPointer(char * &key, int *b); // int b = bool

int setPointer(char * &key, void *pv);

int rehash(); // returns 1 if success, 0 if fail

static unsigned int getPrime(int size);

#endif //SYMTABLE_H