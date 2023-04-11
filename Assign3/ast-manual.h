#ifndef AST_H
#define AST_H

#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum nodetype {
    UNOP_NODE,
    BINOP_NODE,
    TERNOP_NODE,
    NUMBER_NODE,
    IDENT_NODE, 
    STRING_NODE,
    FUNCTION_NODE,
    ARGUMENT_NODE,
    ARGLIST_NODE,
    DECSPEC_NODE,
    SCALAR_NODE,
    POINTER_NODE,
    ARRAY_NODE,
    FUNCTION_DEF_NODE,
    SYMBOL_POINTER_NODE, 
    RETURN_TYPE_NODE
} nodetype;

struct info {
    char *fileName; 
    int lineNum;
};
struct info report;

enum nums {
		UNSIGNED_INT,
		SIGNED_INT,
		UNSIGNED_LONG,
		SIGNED_LONG,
		UNSIGNED_LONGLONG,
		SIGNED_LONGLONG,
		DOUBLE_NUM, 
		FLOAT_NUM,
		LONG_DOUBLE
}; 

struct numinfo {
    enum nums meta; 
	union {
    	long long int int_val;
		long double float_val;  
	} value; 
};
struct numinfo numInfo; 

struct stringinfo {
	char *string_literal; 
	int length; 
};
struct stringinfo stringInfo; 

/* Expressions Nodes */

// Generic
struct astnode_generic {
    enum nodetype type;
};

// Unary Operators
struct astnode_unop {
    enum nodetype type;
    int operator;
    union astnode *operand;
};

union astnode* new_astnode_unop(int operator, union astnode *operand);

// Binary Operators
struct astnode_binop {
    enum nodetype type;
    int operator;
    union astnode *left,*right;
};

union astnode* new_astnode_binop(int operator, union astnode *left, union astnode *right);

// Ternary Operators
struct astnode_ternop {
    enum nodetype type;
    int operator1;
    int operator2;
    union astnode *left,*right, *middle;
};

union astnode* new_astnode_ternop(int operator1, int operator2, union astnode *left, union astnode *middle, union astnode *right);

// Number
struct astnode_num {
    enum nodetype type;
    struct numinfo numInfo;
};
union astnode* new_astnode_num(nodetype type, struct numinfo numInfo);

// Ident
struct astnode_ident {
    enum nodetype type;
    char* ident;
};
union astnode* new_astnode_ident(nodetype type, char* ident);

// String
struct astnode_string {
    enum nodetype type;
    char *string_literal;
};
union astnode* new_astnode_string(nodetype type, char* string);

// Argument Node
struct astnode_argument {
    enum nodetype type;
    union astnode *argument;
};

// List of Arguments
struct astnode_arglist {
    enum nodetype type;
    union astnode *arg_head;
    union astnode *arg_next;
};

union astnode* new_astnode_arg(union astnode *arg_entry);
union astnode *init_list(union astnode *arg_head);
union astnode  *append_arg(union astnode *arg_head, union astnode *arg_entry);

// Function Call node
struct astnode_function {
    enum nodetype type;
    union astnode *function_name;
    union astnode *arg_head; 
    int num_args;
    //char *return_type;
};

union astnode* new_astnode_func(union astnode *function_name, union astnode *arg_list);
union astnode* astnode_one(); 

/* Declarations Nodes */

typedef enum specifier_type {
    UNKNOWN_TYPE,
    VOID_TYPE,
    CHAR_TYPE,
    SHORT_TYPE,
    INT_TYPE,
    LONG_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    SIGNED_TYPE,
    UNSIGNED_TYPE,
    BOOL_TYPE,
} specifier_type;

typedef enum qualifier_type {
    NONE_TYPE,
    CONST_TYPE,
    RESTRICT_TYPE,
    VOLATILE_TYPE,
} qualifier_type;

typedef enum storage_class {
    UNKNOWN_CLASS,
    TYPEDEF_CLASS, 
    EXTERN_CLASS, 
    STATIC_CLASS, 
    AUTO_CLASS, 
    REGISTER_CLASS,
} storage_class;

// Declaration Specifier Node
struct astnode_declaration_spec {
    enum nodetype type;
    //specifier_type s_type;
    union astnode* s_type;
    qualifier_type q_type; 
    storage_class s_class; 

    union astnode *next; // pointer to next astnode in list (for multiple type specifiers/qualifiers) 
    union astnode *prev; // pointer to previous astnode in list

    // 1 = inline, 0 = not inline 
    int function_specifier; // *** Optional -- Not Implemented ***
};

union astnode* new_astnode_declaration_spec(nodetype type, union astnode* s_type, qualifier_type q_type, storage_class s_class);
union astnode* modify_astnode_declaration_spec(union astnode *node_ptr, union astnode* s_type, qualifier_type q_type, storage_class s_class);
union astnode* append_astnode_list(union astnode *prev, union astnode *addition);

// Scalar Node
struct astnode_scalar {
    enum nodetype type;
    enum specifier_type scalarType;
};

union astnode* new_astnode_scalar(nodetype type, specifier_type s_type);

// Pointer Node
struct astnode_pointer {
    enum nodetype type;
    union astnode* parent;
    enum qualifier_type q_type;
};
union astnode* new_astnode_pointer(nodetype type, union astnode *type_qual, union astnode *pointer);

// Array Node
struct astnode_array {
    enum nodetype type;
    int size;
    union astnode* element_type;
};
union astnode* new_astnode_array(nodetype type, union astnode *element_type, int size);

// Function Definition Node
struct astnode_fndef {
    enum nodetype type;
    union astnode *arg_type;
    union astnode *ret_type;
};
union astnode* new_astnode_fndef(nodetype type, union astnode *arg, union astnode *ret);

// Symbol Pointer Node
struct astnode_symbol_p {
    enum nodetype type;
    struct symbol *sym;
    union astnode *next; // for lists
};
union astnode* new_astnode_symbol_pointer(nodetype type, struct symbol *sym);

// Return Type Node
struct astnode_return_type {
    enum nodetype type;
    union astnode *s_type;
    union astnode *next;  
};

union astnode* new_astnode_return_type(nodetype type, union astnode* s_type, union astnode *next);

typedef union astnode {
    struct astnode_generic generic;
    struct astnode_unop unop;
    struct astnode_binop binop;
    struct astnode_ternop ternop;
    struct astnode_num num;
    struct astnode_ident id;
    struct astnode_string str;
    struct astnode_function func;
    struct astnode_argument arg;
    struct astnode_arglist list; 
    struct astnode_declaration_spec decspec;  
    struct astnode_scalar scalar; 
    struct astnode_pointer ptr; 
    struct astnode_array arr; 
    struct astnode_fndef fndef; 
    struct astnode_symbol_p sym_p;
    struct astnode_return_type ret; 
    /* etc.*/
} astnode; 

// Printing Functions
void printIndents(int indent);

void printBinop(int op);

void printNum(struct numinfo numInfo);

void printAST(union astnode* node, int indent);

void printFunctions(struct symbol *sym, int indent);

void printDeclaration(struct symbol *sym, int indent);

char *printScopeName(void);

char *printSymType(struct symbol *sym);

char *printStorageClass(struct symbol *sym);

char *printScalarType(union astnode *node);

char *printTypeQualifier(struct symbol *sym);


#endif //AST_H