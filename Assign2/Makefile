parse: parse.tab.c ast.c lex.yy.c 
		gcc -std=c99 -o parse lex.yy.c parse.tab.c ast.c

parse.tab.c: parse.y
		bison -d parse.y

lex.yy.c: lex.l parse.tab.h
		flex lex.l

clean:
		rm -f lex.yy.c parse.tab.* parse 