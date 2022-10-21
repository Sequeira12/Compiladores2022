
all: jucompiler.l
	flex jucompiler.l
	yacc -d jucompiler.y
	cc lex.yy.c functions.c -o jucompiler
