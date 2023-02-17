parse: parse.tab.o ast.o lex.yy.o 
		gcc --std=gnu99 -o parse parse.tab.o ast.o ../Assign1/lex.yy.o 

parse.tab.o: parse.y
		# For debugging:
		# bison --debug -vd parse.y
		bison -vd parse.y
		gcc --std=gnu99 -c -o parse.tab.o parse.tab.c

parse.tab.h: parse.tab.o

ast.o: ast-manual.h ast.c
		gcc -std=gnu99 -c -o ast.o ast.c

lex.yy.o: lex.yy.c
		gcc --std=gnu99 -c -o ../Assign1/lex.yy.o ../Assign1/lex.yy.c

lex.yy.c: ../Assign1/lex.l parse.tab.h
		flex -o ../Assign1/lex.yy.c ../Assign1/lex.l
		# For debugging:
		# flex --debug -o ../Lexer/lexer.yy.c ../Lexer/lexer.l

clean:
		rm -f ../Assign1/lex.yy.c ../Assign1/lex.yy.o 