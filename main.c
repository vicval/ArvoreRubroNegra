/*Algumas informações:

 * PRINTF RULLEZ: [Sistemas Unix]
 * printf("\033[XA"); // Move up X lines;
 * printf("\033[XB"); // Move down X lines;
 * printf("\033[XC"); // Move right X column;
 * printf("\033[XD"); // Move left X column;
 * printf("\033[2J"); // Clear screen

*/

#include <stdio.h>
#include <stdlib.h>
#include "input_output.h"
#include "arvores.h"
#include "rubroNegra.h"
#include "234.h"

void Console (char opcao); // Manutenção do Console

int main(int argc, char** argv) {
    /*MENU*/    char menu_arvB, menu_arvB_conversao;
    /*ÁRVORE*/  int elemento;
                tno *arv = cria234();

	arv = Leitura_Arquivo();

    // MENU:
    while (menu_arvB != '5'){
        printf("\t[Arvores Balanceadas : Menu]\n\n1. Inserir novo elemento na arvore 2-3-4\n2. Remover elemento da rvore 2-3-4\n3. Imprimir arvore 2-3-4\n4. Converter em uma arvore rubro-negra\n5. Sair do programa\n\n\tEntre com a opcao desejada: ");
        scanf(" %c", &menu_arvB);
        Console('0');
        switch (menu_arvB){
            case '1': // Inserção na árvore 2-3-4
                printf("Entre com o elemento a ser inserido: ");
                scanf("%d", &elemento);
                insere234(&arv, elemento);
                printf("Elemento inserido com sucesso!\n");
                break;
            case '2': // Remoção na árvore 2-3-4
                printf("Entre com o elemento a ser removido: ");
                scanf("%d", &elemento);
                break;
            case '3': // Impressão da árvore 2-3-4
                printf("\t\t\t2-3-4 Tree\n\n");
                imprime234(arv, 0);
                printf("\n\n");
                break;
            case '4': // Conversão para árvore rubro-negra
                converteArvore(arv, arv);
                consultRB(arv);
                while (menu_arvB_conversao != '4' && menu_arvB_conversao != 'v' && menu_arvB_conversao != 'V'){
                    printf("\t[Árvores Balanceadas : Menu : Converter em uma árvore rubro-negra]\n\n1. Inserir novo elemento na arvore rubro-negra\n2. Remover elemento da arvore rubro-negra\n3. Imprimir arvore rubro-negra\n4. Sair do programa\n\tEntre com a opcao desejada: ");
                    scanf(" %c", &menu_arvB_conversao);
                    Console('0');
                    switch (menu_arvB_conversao){
                        case '1': // Inserção na árvore rubro-negra
                            printf("Entre com o elemento a ser inserido: ");
                            scanf("%d", &elemento);
                            insertNodeRB(arv, elemento);
                            printf("Elemento inserido com sucesso!\n");
                            break;
                        case '2': // Remoção na árvore rubro-negra
                            break;
                        case '3': // Impressão da árvore rubro-negra
                            consultRB(arv);
                            break;
                        case '4': // Sair do programa
                            Console(0);
                            return (EXIT_SUCCESS);
                            break;
                        case 'v': case 'V': // Voltar ao menu principal
                            break;
                        default:
                            break;
                    }
                }
                // Reciclando variável de menu
                menu_arvB_conversao = '6';
                break;
            case '5': // Sair do programa
                Console(0);
                return (EXIT_SUCCESS);
                break;
            default:
                break;
        }
        //Console('0');
    }

    return (EXIT_SUCCESS);
}

void Console (char opcao){
    #ifdef LINUX
        // Limpar console
        if (opcao == '0'){
            // Limpa o console com printf
            printf("\033[2J");
            // Volta pro começo do console
            printf("\033[20A");
        }
        // vazio
        else if (opcao == '1'){}
    #elif defined WIN32
        system("cls");
    #else
        printf("\n\n");
    #endif

    return;
}
