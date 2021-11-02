#ifndef tp2_abp_h
#define tp2_abp_h

struct Node {
    int data;
    struct Node *left, *right;
    int fatBall;
};
typedef struct Node* ArvoreAVL;

int Altura_Node(struct Node *node);
int Calcula_Fat_Bal(struct Node *node);
void Retacao_Esquerda(ArvoreAVL *raiz);
void Retacao_Direita(ArvoreAVL *raiz);
int Insere_Node(ArvoreAVL *raiz, int data);
void Deleta_Arvore(struct Node *rootNode);
void printaEmOrdem(struct Node *rootNode);

#endif //tp2_abp_h