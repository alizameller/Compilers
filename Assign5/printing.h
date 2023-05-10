#ifndef PRINTING_H
#define PRINTING_H

#include "ast-manual.h"
#include "parse.tab.h"

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

void printQuads();

void printType(union astnode *node);

char *printOp(int opcode);

#endif //PRINTING_H