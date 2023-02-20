#include "ast-manual.h"

union astnode* new_astnode_char(nodetype type, char charlit){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->char_lit.type = type;
    node_ptr->char_lit.charlit = charlit;

    return node_ptr;
}

union astnode* new_astnode_string(nodetype type, char* string){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->str.type = type; 
    node_ptr->str.string = string;

    return node_ptr;
}

union astnode* new_astnode_ident(nodetype type, char* ident){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->id.type = type; 
    node_ptr->id.ident = ident;

    return node_ptr;
}

union astnode* new_astnode_num(nodetype type, long long int number){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->num.type = type; 
    node_ptr->num.number = number;

    return node_ptr;
}

union astnode* new_astnode_binop(nodetype type, int operator, union astnode *left, union astnode *right){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->binop.type = type; 
    node_ptr->binop.operator = operator; 
	node_ptr->binop.left = left;
	node_ptr->binop.right = right;

    return node_ptr;
}

