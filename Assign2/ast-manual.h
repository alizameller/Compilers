#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>

typedef enum nodetype {
    BINOP_NODE,
    UNOP_NODE,
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

struct astnode_binop {
    enum nodetype type;
    int operator;
    union astnode *left,*right;
};

union astnode* new_astnode_binop(nodetype type, int operator, union astnode *left, union astnode *right);

// Generic
struct astnode_generic {
    enum nodetype type;
};

// Number
struct astnode_num {
    enum nodetype type;
    int number;
};
union astnode* new_astnode_num(nodetype type, long long int number);

// Ident
struct astnode_ident {
    enum nodetype type;
    char* ident;
};

union astnode* new_astnode_ident(nodetype type, char* ident);

// String
struct astnode_string {
    enum nodetype type;
    char *string;
};

union astnode* new_astnode_string(nodetype type, char* string);

// Char
struct astnode_char {
    enum nodetype type;
    char charlit;
};

union astnode* new_astnode_char(nodetype type, char charlit); 

typedef union astnode {
    struct astnode_generic generic;
    struct astnode_binop binop;
    struct astnode_num num;
    struct astnode_ident id;
    struct astnode_string str;
    struct astnode_char char_lit; 
    /* etc.*/
} astnode; 

#endif //AST_H