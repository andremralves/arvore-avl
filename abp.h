#ifndef tp2_abp_h
#define tp2_abp_h

struct Node {
    int data;
    struct Node *left, *right;
    int fatBall;
};


int Altura_Node(struct Node *node);
int Calcula_Fat_Bal(struct Node *node);
void Retacao_Esquerda(struct Node *node_rot);
void Retacao_Direita(struct Node *node_rot);
int Insere_Node(struct Node *raiz, int data);
void Remove_Node(struct Node *node);
void Deleta_Arvore(struct Node *raiz);

#endif //tp2_abp_h