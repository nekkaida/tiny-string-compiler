string_compiler: y.tab.c lex.yy.c
	gcc -o string_compiler y.tab.c lex.yy.c -lfl

y.tab.c y.tab.h: string-compiler.y
	bison -y -d string-compiler.y

lex.yy.c: string-compiler.l y.tab.h
	flex string-compiler.l

clean:
	rm -f string_compiler y.tab.c y.tab.h lex.yy.c
