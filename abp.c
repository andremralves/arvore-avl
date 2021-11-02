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


void Retacao_Esquerda(ArvoreAVL *raiz) {
    struct Node *node;
    node = (*raiz)->right;
    (*raiz)->right = node->left;
    node->left = (*raiz);
    (*raiz) = node;
    Calcula_Fat_Bal(*raiz);
}

void Retacao_Direita(ArvoreAVL *raiz) {
    struct Node *node;
    node = (*raiz)->left;
    (*raiz)->left = node->right;
    node->right = (*raiz);
    (*raiz) = node;
    Calcula_Fat_Bal(*raiz);
}

void Retacao_Dupla_Direita(ArvoreAVL *raiz) {
    Retacao_Esquerda(&(*raiz)->left);
    Retacao_Direita(raiz);      
}

void Retacao_Dupla_Esquerda(ArvoreAVL *raiz) {
    Retacao_Direita(&(*raiz)->right);
    Retacao_Esquerda(raiz);  
}

void Remove_Node(ArvoreAVL *node) {
  

    free(node);
}

int Insere_Node(ArvoreAVL *raiz, int data)
{
  int res;
  if(*raiz == NULL)
  {
    struct Node *novo_node;
    novo_node = (struct Node*)malloc(sizeof(struct Node));
    if(novo_node == NULL)
      return 0;

    novo_node->data = data;
    novo_node->fatBall = 0;
    novo_node->left = NULL;
    novo_node->right =  NULL;
    *raiz = novo_node;
    return 1;
  }
  
  struct Node *cursor = *raiz;
  
  if(data < cursor->data)
  {
    if(res = Insere_Node(&(cursor->left),data) == 1)
    {
      if(Calcula_Fat_Bal(cursor) >= 2)
      {
        if(data < (*raiz)->left->data)
          Retacao_Direita(raiz);
        else
          Retacao_Dupla_Direita(raiz);
      }
    }
  }
  else if(data > cursor->data)
  {
      if(res = Insere_Node(&(cursor->right),data) == 1)
      {
        if(Calcula_Fat_Bal(cursor) >= 2)
        {
          if((*raiz)->right->data < data)
            Retacao_Esquerda(raiz);
          else
            Retacao_Dupla_Esquerda(raiz);
        }
      }
  }
  else
  {
    printf("valor duplicado\n");
    return 0;
  }
  return res;
}

void printaEmOrdem(struct Node *rootNode) {

    if(rootNode == NULL)
        return;
    printaEmOrdem(rootNode->left);
    printf("%d fat_bal = (%d)\n",rootNode->data, rootNode->fatBall);
    printaEmOrdem(rootNode->right);
    
}

void Deleta_Arvore(struct Node *rootNode) {

    if(rootNode == NULL)
        return;
    Deleta_Arvore(rootNode->left);
    Deleta_Arvore(rootNode->right);
    free(rootNode);
    rootNode = NULL;
}
