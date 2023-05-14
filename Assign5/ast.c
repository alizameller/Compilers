#include "ast-manual.h"

/* Expression Functions */
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

union astnode *append_arg(union astnode *arg_head, union astnode *arg_entry) {
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

union astnode*new_astnode_func(union astnode *function_name, union astnode *arg_list) {
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

/* Declaration Functions */ 
union astnode* new_astnode_declaration_spec(nodetype type, union astnode* s_type, qualifier_type q_type, storage_class s_class){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

    // set entries
    node_ptr->decspec.type = type; 
    node_ptr->decspec.s_type = s_type;
    node_ptr->decspec.q_type = q_type; 
    node_ptr->decspec.s_class = s_class; 

    // initialize astnode scalar as a singular type spec
    node_ptr->decspec.next = NULL;
    node_ptr->decspec.prev = NULL;
    
    return node_ptr;
}

union astnode* modify_astnode_declaration_spec(union astnode *node_ptr, union astnode* s_type, qualifier_type q_type, storage_class s_class){
   // if decspec field has no value and parameter has value, set decspec field
    if (!node_ptr->decspec.s_type && s_type) { 
        node_ptr->decspec.s_type = s_type; // specifier type modification
    } else if (node_ptr->decspec.s_type && s_type) { // both have values
        fprintf(stderr, "ERROR: Cannot have two declaration specifiers\n");
    }
    if (!node_ptr->decspec.q_type && q_type) {
        node_ptr->decspec.q_type = q_type; // qualifier type modification
    } else if (node_ptr->decspec.q_type && q_type) { // both have values
        fprintf(stderr, "ERROR: Cannot have two declaration specifiers\n");
    }
    if (!node_ptr->decspec.s_class && s_class) {
        node_ptr->decspec.s_class = s_class; // storage class modification
    } else if (node_ptr->decspec.q_type && s_class) { // both have values
        fprintf(stderr, "ERROR: Cannot have two declaration specifiers\n");
    }

    return node_ptr;
}


union astnode* new_astnode_scalar(nodetype type, enum specifier_type s_type){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->scalar.type = type; 
    node_ptr->scalar.scalarType = s_type;

    return node_ptr;
}


union astnode* new_astnode_list(nodetype type, union astnode *list_item, union astnode *prev) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->ast_list.type = type; 
    node_ptr->ast_list.node = list_item;
    node_ptr->ast_list.prev = prev;
    node_ptr->ast_list.next = NULL;

    return node_ptr;
}

union astnode *append_astnode_list(union astnode *previous, union astnode *addition){
    if (previous->generic.type != DECSPEC_NODE) {
        if (previous->generic.type != LIST_NODE) { //head of list
            previous = new_astnode_list(LIST_NODE, previous, NULL);
        }

        addition = new_astnode_list(LIST_NODE, addition, previous);
        previous->ast_list.next = addition;

        return addition; 
    } // ELSE
    previous->decspec.next = addition; 
    addition->decspec.prev = previous; 

    return previous;
}

union astnode* new_astnode_pointer(nodetype type, union astnode *type_qual, union astnode *pointer){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

    // set entries
    node_ptr->ptr.type = type; 
    node_ptr->ptr.parent = NULL;
    node_ptr->ptr.q_type = NONE_TYPE; 
    
    // if pointer is not NULL
    if (pointer) {
        node_ptr->ptr.parent = pointer;
    }
    if (type_qual) {
        node_ptr->ptr.q_type = type_qual->decspec.q_type; 
    }
    return node_ptr;
}  

union astnode* new_astnode_array(nodetype type, union astnode *element_type, int size){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->arr.type = type; 
    node_ptr->arr.size = size;
    node_ptr->arr.element_type = element_type;

    return node_ptr;
}

union astnode* modify_astnode_array(union astnode *node_ptr, union astnode *element_type) {
   if (!(node_ptr->arr.element_type)) {
        node_ptr->arr.element_type = element_type;
   }
   
    return node_ptr;
}

union astnode* new_astnode_fndef(nodetype type, union astnode *arg, union astnode *ret){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

    node_ptr->fndef.type = type;
    node_ptr->fndef.arg_type = arg;
    node_ptr->fndef.ret_type = ret;
    
    return node_ptr;
}

union astnode* modify_astnode_fndef(union astnode *node_ptr, union astnode *arg, union astnode *ret) {
    if (!(node_ptr->fndef.arg_type)) {
        node_ptr->fndef.arg_type = arg;
    }
    if (!(node_ptr->fndef.ret_type)) {
        node_ptr->fndef.ret_type = ret;
    }
   
    return node_ptr;
}

union astnode* new_astnode_symbol_pointer(nodetype type, symbol *sym){
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->sym_p.type = type; 
    node_ptr->sym_p.sym = sym;

    return node_ptr;
}

/* Statement Functions */
union astnode* new_astnode_label(nodetype type, label_type labelType, union astnode *label_name, union astnode *statement) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->label.type = type; 
    node_ptr->label.labelType = labelType;
    node_ptr->label.statement = statement;
    node_ptr->label.label_name = label_name;

    return node_ptr;
}

union astnode* new_astnode_if(nodetype type, union astnode *exp, union astnode *statement) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->if_statement.type = type; 
    node_ptr->if_statement.exp = exp;
    node_ptr->if_statement.statement = statement;

    return node_ptr;
}

union astnode* new_astnode_switch(nodetype type, union astnode *exp, union astnode *statement) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->switch_statement.type = type; 
    node_ptr->switch_statement.exp = exp;
    node_ptr->switch_statement.statement = statement;

    return node_ptr;
}

union astnode* new_astnode_while(nodetype type, union astnode *exp, union astnode *statement) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->while_statement.type = type; 
    node_ptr->while_statement.exp = exp;
    node_ptr->while_statement.statement = statement;

    return node_ptr;
}

union astnode* new_astnode_for(nodetype type, union astnode *initialization, union astnode *condition, union astnode *update, union astnode *statement) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->for_statement.type = type; 
    node_ptr->for_statement.initialization = initialization;
    node_ptr->for_statement.condition = condition;
    node_ptr->for_statement.update = update;
    node_ptr->for_statement.statement = statement;

    return node_ptr;
}

union astnode* new_astnode_goto(nodetype type, union astnode *label_ptr) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->goto_statement.type = type; 
    node_ptr->goto_statement.label_ptr = label_ptr;

    return node_ptr;
}

union astnode* new_astnode_cont_break(nodetype type) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->cont_break_statement.type = type; 

    return node_ptr;
}

union astnode* new_astnode_return(nodetype type, union astnode *exp) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->ret.type = type;
    node_ptr->ret.exp = exp;
    
    return node_ptr;
}

union astnode *new_temporary(nodetype type, int num) {
    // allocate memory
	union astnode *node_ptr = (union astnode*) malloc(sizeof (union astnode));

	// set entries
    node_ptr->temp.type = type;
    node_ptr->temp.num = num;

    return node_ptr;
}