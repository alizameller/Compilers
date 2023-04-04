parse: parse.tab.o symtable.o ast.o lex.yy.o printing.o
		gcc -o parse parse.tab.o printing.o symtable.o ast.o lex.yy.o

printing.o: ast.o parse.tab.h printing.c
		gcc -c -o printing.o printing.c

symtable.o: ast.o symtable.h symtable.c 
		gcc -c -o symtable.o symtable.c

ast.o: ast-manual.h ast.c
		gcc -c -o ast.o ast.c

lex.yy.o: lex.yy.c
		gcc -c -o lex.yy.o lex.yy.c

lex.yy.c: lex.l parse.tab.h
		flex -o lex.yy.c lex.l

parse.tab.h: parse.tab.o

parse.tab.o: parse.y
		bison -vd parse.y
		gcc -c -o parse.tab.o parse.tab.c

clean:
		rm -f lex.yy.* parse.tab.* parse *.o

outs:
		rm -f *.out *.output *.err