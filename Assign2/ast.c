#include "ast-manual.h"

/*union astnode* new_astnode_char(nodetype type, char charlit){
	// allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->charlit.type = type;
    node_ptr->charlit.char_literal = charlit;

    return node_ptr;
} */

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

union astnode *new_astnode_ternop(int operator1, int operator2, union astnode *left, union astnode *middle, union astnode *right){
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

union astnode *astnode_one(){
    // allocate memory
    union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

    node_ptr->generic.type = NUMBER_NODE;
    node_ptr->num.numInfo.meta = UNSIGNED_INT;
    node_ptr->num.numInfo.value.int_val = 1; 

    return node_ptr; 
} 

union astnode *new_astnode_arg(union astnode *argument) {
    // allocate memory
    union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

    node_ptr->generic.type = ARGUMENT_NODE;
    node_ptr->arg.argument = argument; 

    return node_ptr; 
}

union astnode *init_list(union astnode *arg_head) {
    // allocate memory
    union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));

    node_ptr->generic.type = ARGLIST_NODE;
    node_ptr->list.arg_head= arg_head;
    node_ptr->list.arg_next = NULL; 

    return node_ptr;
}

union astnode * append_arg(union astnode *arg_head, union astnode *arg_entry) {
    // make arg_entry an astnode_arg
    union astnode *entry = new_astnode_arg(arg_entry); 
    // create a temp astnode called current
    union astnode *current = arg_head;
    // iterate through list setting current to the next argument until the next arg is NULL
    
    while(current->list.arg_next) {
        current = current->list.arg_next;
    }
    // set the current node's next argument = NULL
    current->list.arg_next = entry; 
    entry->list.arg_next = NULL; 

    return arg_head; //return the head
}

union astnode* new_astnode_func(union astnode *function_name, union astnode *arg_list) {
   // allocate memory
    union astnode *node_ptr = (union astnode*) malloc (sizeof (union astnode));
    
    node_ptr->generic.type = FUNCTION_NODE;
    node_ptr->func.function_name = function_name;
    // default is no arguments
    node_ptr->func.arg_head = NULL; 
    node_ptr->func.num_args = 0;

    // if there are arguments..
    union astnode *current = arg_list;
    if (arg_list) {
        node_ptr->func.arg_head = arg_list;
        (node_ptr->func.num_args)++; //count head as arg 1
        // iterate through list setting current to the next argument until the next arg is NULL
        while(current->list.arg_next) {
            (node_ptr->func.num_args)++; //count every subsequent arg
            current = current->list.arg_next;
        }
    }
    
    return node_ptr;
}


