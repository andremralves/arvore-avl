#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"
#include "files.h"

void menu() {
    printf("1 - Ler um arquivo csv\n");
    printf("2 - Gerar AVL\n");
    printf("3 - Printar AVL\n");
    printf("4 - Sair\n");
}

int main() {

    FILE *file = NULL;
    ArvoreAVL *raiz = (ArvoreAVL*)malloc(sizeof(ArvoreAVL));
    *raiz = NULL;
    char filename[30];
    char number[30] = "";
    char c;
    int menuNum;

    do {
        menu();
        printf("Digite um numero do Menu: ");
        scanf("%d", &menuNum);

        switch (menuNum)
        {
        case 1:
            printf("Digite o nome do arquivo para gerar a ABP: ");
            scanf("%s", filename);

            //Abrir o arquivo para leitura
            if(file != NULL)
                fclose(file);
            file = readFile(filename);
            if(file == NULL) {
                printf("O arquivo não foi encontrado!\n");
            }
            break;

        case 2:
            Deleta_Arvore(*raiz);
            fseek(file, SEEK_SET, 0);
            
            printf("Gerando AVL...\n");

            int i = 0;
            do {
                c = fgetc(file);
                
                if(c == ',' || c == '\n' || c == EOF) {
                    //printf("%s ", number);
                    Insere_Node(raiz, atoi(number));
                    memset(number, 0, 30);
                    i = 0;
                    continue;
                }
                if(c >= 48 && c <= 57) {
                    number[i] = c; 
                    i++;
                }

            } while (c != EOF);
            break;

        case 3:
            printf("Imprimindo AVL...\n");
            printaEmOrdem(*raiz);
            break;

        case 4:
            Deleta_Arvore(*raiz);
            printf("Saindo do programa...\n");
            break;    
        
        default:
            printf("Digite um número válido!\n");
            break;
        }

    } while (menuNum != 4);

    fclose(file);


    return 0; 
}