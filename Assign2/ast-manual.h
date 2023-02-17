#ifndef AST_H
#define AST_H

typedef enum nodetype {
    BINOP_NODE,
    UNOP_NODE,
    NUMBER_NODE,
    IDENT_NODE, 
    STRING_NODE,
    CHARLIT_NODE,
}nodetype;

struct astnode_binop {
    enum nodetype type;
    int operator;
    union astnode *left,*right;
};

// Generic
struct astnode_generic {
    enum nodetype type;
};

// Number
struct astnode_num {
    enum nodetype type;
    int number;
};

// Ident
struct astnode_ident {
    enum nodetype type;
    char* ident;
};

// String
struct astnode_string {
    enum nodetype type;
    char *string;
};

// Char
struct astnode_char {
    enum nodetype type;
    char *charlit;
};

union astnode {
    struct astnode_generic generic;
    struct astnode_binop binop;
    struct astnode_num num;
    struct astnode_ident id;
    struct astnode_string str;
    struct astnode_char char_lit; 
    /* etc.*/
};

#endif AST_H