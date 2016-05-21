#include<stdio.h>
#include<stdlib.h>

struct Node {
    int elemento;
    struct Node *esquerda;
    struct Node *direita;
};

typedef struct Node Node;

Node* insert(Node *node,int elemento);
Node* Find(Node *node, int elemento);
void printInOrder(Node *node);
void printInPreOrder(Node *node);

int main(int argc, char const *argv[]) {
    Node *ptRaiz = NULL;
    ptRaiz = insert(ptRaiz, 5);
    ptRaiz = insert(ptRaiz, -1);
    ptRaiz = insert(ptRaiz, 3);
    ptRaiz = insert(ptRaiz, -14);
    ptRaiz = insert(ptRaiz, 8);
    ptRaiz = insert(ptRaiz, 10);
    ptRaiz = insert(ptRaiz, 9);
    ptRaiz = insert(ptRaiz, 6);
    printInOrder(ptRaiz);
    printf("\n");
    printInPreOrder(ptRaiz);
    return 0;
}

void printInOrder(Node *node)
{
    if(node==NULL)
    {
        return;
    }
    printInOrder(node->esquerda);
    printf("%d ",node->elemento);
    printInOrder(node->direita);
}

void printInPreOrder(Node *node)
{
    if(node==NULL)
    {
        return;
    }
    printf("%d ",node->elemento);
    printInPreOrder(node->esquerda);
    printInPreOrder(node->direita);
}

void PrintPostorder(Node *node) {
    if(node==NULL)
    {
        return;
    }
    PrintPostorder(node->esquerda);
    PrintPostorder(node->direita);
    printf("%d ",node->elemento);
}

Node * insert(Node *node,int elemento) {
    if(node==NULL) {
        Node *temp;
        temp = (Node *)malloc(sizeof(Node));
        temp -> elemento = elemento;
        temp -> esquerda = temp -> direita = NULL;
        return temp;
    }

    if(elemento >(node->elemento)) {
        node->direita = insert(node->direita,elemento);
    }
    else if(elemento < (node->elemento))
    {
        node->esquerda = insert(node->esquerda,elemento);
    }
    return node;
}