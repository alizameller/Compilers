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
    CHARLIT_NODE,
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

// Generic
struct astnode_generic {
    enum nodetype type;
};

struct astnode_unop {
    enum nodetype type;
    int operator;
    union astnode *operand;
};

union astnode* new_astnode_unop(int operator, union astnode *operand);

struct astnode_binop {
    enum nodetype type;
    int operator;
    union astnode *left,*right;
};

union astnode* new_astnode_binop(int operator, union astnode *left, union astnode *right);

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

// Char
struct astnode_char {
    enum nodetype type;
    char char_literal;;
};

union astnode* new_astnode_char(nodetype type, char charlit); 

void printAST(union astnode* node, int indent); 

typedef union astnode {
    struct astnode_generic generic;
    struct astnode_unop unop;
    struct astnode_binop binop;
    struct astnode_ternop ternop;
    struct astnode_num num;
    struct astnode_ident id;
    struct astnode_string str;
    struct astnode_char charlit; 
    /* etc.*/
} astnode; 

#endif //AST_H