#include "minhas_funcoes.h"

int main(int argc, char **argv)
{ //Recebe as palavras como argumento da função.
    int i, nPalavras = 0;
    char **palavras = NULL; //arquivo dado em argv[1] (o padrão é dicionario.txt)
    char *fname = argc > 1 ? argv[1] : "dicionario.txt";
    FILE *dicionario = fopen(fname, "r");
    if (!dicionario)
    { //valida a abertura do arquivo
        fprintf(stderr, "erro: abertura do arquivo falhou.\n");
        return 1;
    }
    if (!(palavras = pegaPalavras(dicionario, &nPalavras)))
    {
        fprintf(stderr, "erro: pegaPalavras retornou NULL.\n");
        return 1;
    }
    fclose(dicionario);
    //Até aqui, é para guardar as palavras em um array para podermos comparar, tá funcionando!
    printf("\n '%d' palavras lidas de '%s'\n\n", nPalavras, fname);

    for (int k = 2; k < argc; k++)
    {

        if (Existe(argv[k], palavras, nPalavras) != 1)
        {
            //A palavra não existe, vamos sugerir a correção que vai ocupar aquela posição em argv[k]

            argv[k] = corrigePalavra(argv[k], palavras, nPalavras);
        }
    }
    //aqui eu printo depois das escolhas do usuário.
    printf("\n \n Texto Final: \n");
    for (int i = 2; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    liberaArray(palavras, nPalavras);
    return 0;
}
