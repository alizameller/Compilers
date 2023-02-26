#include "ast-manual.h"

union astnode* new_astnode_char(nodetype type, char charlit){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->charlit.type = type;
    node_ptr->charlit.char_literal = charlit;

    return node_ptr;
}

union astnode* new_astnode_string(nodetype type, char *string){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->str.type = type; 
    node_ptr->str.string_literal = string;

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

union astnode* new_astnode_num(nodetype type, struct numinfo numInfo){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->generic.type = NUMBER_NODE; 
    node_ptr->num.numInfo = numInfo;

    return node_ptr;
}

union astnode* new_astnode_unop(int operator, astnode* operand){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->generic.type = UNOP_NODE; 
    node_ptr->unop.operator = operator; 
	node_ptr->unop.operand = operand;

    return node_ptr;
}

union astnode* new_astnode_binop(int operator, union astnode *left, union astnode *right){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->generic.type = BINOP_NODE; 
    node_ptr->binop.operator = operator; 
	node_ptr->binop.left = left;
	node_ptr->binop.right = right;

    return node_ptr;
}

union astnode* new_astnode_ternop(int operator1, int operator2, union astnode *left, union astnode *middle, union astnode *right){
// allocate memory
	union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

	// set entries
    node_ptr->generic.type = TERNOP_NODE; 
    node_ptr->ternop.operator1 = operator1; 
    node_ptr->ternop.operator2 = operator2; 
	node_ptr->ternop.left = left;
    node_ptr->ternop.middle = middle;
	node_ptr->ternop.right = right;

    return node_ptr;
}