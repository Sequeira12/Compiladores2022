
all:
	flex jucompiler.l
	yacc -d -Wcounterexamples jucompiler.y
	cc *.c -o jucompiler
