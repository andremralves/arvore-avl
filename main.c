#include <stdio.h>
#include <string.h>
#include "abp.h"
#include "files.h"

int main() {

    FILE *file = NULL;
    struct Node *raiz = NULL;  
    char filename[30];
    char number[30] = "";
    char c;
    int menuNum;

    do {
        menu();
        printf("Digite um numero do Menu: ");
        scanf("%d", menuNum);

        switch (menuNum)
        {
        case 1:
            system("cls");
            printf("Digite o nome do arquivo para gerar a ABP: ");
            scanf("%s", filename);

            //Abrir o arquivo para leitura
            file = readFile(filename);
            if(file == NULL) {
                printf("O arquivo não foi encontrado!\n");
                return 0;
            }
            break;

        case 2:
            system("cls");
            printf("Gerando AVL...\n");

            break;

        case 3:
            system("cls");
            printf("Imprimindo AVL...\n");
            
            break;

        case 4:
            system("cls");
            printf("Saindo do programa...\n");
            break;    
        
        default:
            printf("Digite um número válido!\n");
            system("pause");
            break;
        }

    } while (menuNum);

    return 0; 
}