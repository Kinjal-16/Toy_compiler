default:
	clear
	bison -d -t parse.y
	flex lex.l
	gcc -o a lex.yy.c parse.tab.c
	./a input.txt