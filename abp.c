#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"abp.h"

int Altura_Node(struct Node *node)
{
    if(node == NULL) 
        return 0;
    int altura_no;
    int altura_esquerda = Altura_Node(node->left);
    int altura_direita = Altura_Node(node->right);

    if(altura_esquerda > altura_direita)
        altura_no = altura_esquerda +1;
    else
        altura_no = altura_direita +1;

    node->fatBall = altura_esquerda - altura_direita;
    return altura_no;
}

int Calcula_Fat_Bal(struct Node *node)
{
    int tmp;
    tmp = Altura_Node(node);
    return labs(node->fatBall);
}


void Retacao_Esquerda(struct Node *node_rot) {
    struct Node *node;
    node = node_rot->right;
    node_rot->right = node->left;
    node->left = node_rot;
    node_rot = node;
}

void Retacao_Direita(struct Node *node_rot) {
    struct Node *node;
    node = node_rot->left;
    node_rot->left = node->right;
    node->right = node_rot;
    node_rot = node;
}

void Retacao_Dupla_Direita(struct Node *node_rot) {
    Retacao_Esquerda(node_rot->left);
    Retacao_Direita(node_rot);      
}

void Retacao_Dupla_Esquerda(struct Node *node_rot) {
    Retacao_Direita(node_rot->right);
    Retacao_Esquerda(node_rot);  
}

void Remove_Node(struct Node *node) {
    free(node);
}

void Remove_Arvore(struct Node* raiz)
{
    


}