#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "234.h"

tno* Leitura_Arquivo(){
    int dado;
    FILE *p;
    char nome[30];
    tno *arv;

    arv = cria234();

    printf("Arquivo de entrada [sem '.txt']: ");
    scanf("%s", nome);

    strcat(nome, ".txt");

    p = fopen(nome, "r");

    // Verificação do arquivo
    if (!p){
        printf("\nERRO! ARQUIVO DE DADOS NÃO ENCONTRADO!\n");
        exit(EXIT_FAILURE);
    }

    Console(0);

    while(!feof(p)){
        fscanf(p, "%d", &dado);
        if (ferror(p)){
            printf("Erro ao ler arquivo de dados!");
            exit(EXIT_FAILURE);
        }
        insere234(&arv, dado);
    } imprime234(arv, 0);

    fclose(p);

    return arv;
}
