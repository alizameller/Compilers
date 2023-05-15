parse: parse.tab.o symtable.o quads.o assembly.o ast.o lex.yy.o printing.o
		gcc -g -o parse parse.tab.o printing.o symtable.o quads.o assembly.o ast.o lex.yy.o

assembly.o: quads.o assembly.h assembly.c
		gcc -g -c -o assembly.o assembly.c

printing.o: ast.o parse.tab.h printing.c
		gcc -g -c -o printing.o printing.c

quads.o: ast.o quads.h quads.c
		gcc -g -c -o quads.o quads.c

symtable.o: ast.o symtable.h symtable.c 
		gcc -g -c -o symtable.o symtable.c

ast.o: ast-manual.h ast.c
		gcc -g -c -o ast.o ast.c

lex.yy.o: lex.yy.c
		gcc -g -c -o lex.yy.o lex.yy.c

lex.yy.c: lex.l parse.tab.h
		flex -o lex.yy.c lex.l

parse.tab.h: parse.tab.o

parse.tab.o: parse.y
		bison -vd parse.y
		gcc -g -c -o parse.tab.o parse.tab.c

clean:
		rm -f lex.yy.* parse.tab.c parse *.o

outs:
		rm -f *.out *.output *.err