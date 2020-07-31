
main : main.o minhas_funcoes.o
	gcc main.o minhas_funcoes.o -o main

minhas_funcoes.o : minhas_funcoes.h minhas_funcoes.c
	gcc -c minhas_funcoes.c -o minhas_funcoes.o
