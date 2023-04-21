#ifndef PRINTING_H
#define PRINTING_H

#include "ast-manual.h"
#include "parse.tab.h"

// Printing Functions
void printIndents(int indent);

void printBinop(int op);

void printNum(struct numinfo numInfo);

void printAST(union astnode* node, int indent);

void printFunctions(struct symbol *sym);

void printDeclarations(struct symbol *sym);

#endif //PRINTING_H