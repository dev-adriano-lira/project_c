#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define comprimentoDaLista 256
#define comprimentoDasPalavras 21
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

char **pegaPalavras(FILE *fp, int *n);
void liberaArray(char **palavras, int linhas);
int Existe(char *palavra, char **palavras, int nPalavras);           //Retorna 1 se existir tal palavra na lista de palavras
char *corrigePalavra(char *palavra, char **palavras, int nPalavras); //corrige a palavra ou não se ela não existir no dicionário
int levenshtein(const char *s, const char *t);                       //Função que retorna a distância de proximidade entre duas palavras                                                   //quanto menor, mais próximo da palavra comparada
int dist(int i, int j);  
