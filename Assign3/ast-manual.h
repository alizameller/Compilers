#ifndef AST_H
#define AST_H

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
    SCALAR_NODE,
    POINTER_NODE,
    ARRAY_NODE,
    FUNCTION_DEF_NODE
} nodetype;

struct info {
    char *fileName; 
    int lineNum;
};
struct info report;

struct numinfo {
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
typedef enum scalar_type {
    VOID_TYPE,
    CHAR_TYPE,
    SHORT_TYPE,
    INT_TYPE,
    LONG_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    SIGNED_TYPE,
    UNSIGNED_TYPE,
    BOOL_TYPE
} scalar_type;

// Scalar Node
struct astnode_scalar {
    enum nodetype type;
    enum scalar_type scalarType;
};

union astnode* new_astnode_scalar(nodetype type, scalar_type s_type);

// Pointer Node
struct astnode_pointer {
    enum nodetype type;
};
union astnode* new_astnode_pointer(nodetype type, union astnode *name);

// Array Node
struct astnode_array {
    enum nodetype type;
};
union astnode* new_astnode_array(nodetype type, union astnode *name);

// Function Definition Node
struct astnode_fndef {
    enum nodetype type;
};
union astnode* new_astnode_fndef(nodetype type, union astnode *name);

void printAST(union astnode* node, int indent); 

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
    struct astnode_scalar scalar; 
    struct astnode_pointer ptr; 
    struct astnode_array arr; 
    struct astnode_fndef fndef; 
    /* etc.*/
} astnode; 

#endif //AST_H