#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

struct Node {
    int key;
    int color;
    struct Node *esq;
    struct Node *dir;
};

typedef struct Node* Tree;
typedef struct Node Node;

Tree* create(Tree* root);
void destroyNode(Node* node);
void destroyTree(Tree* root);
void showInPreOrder(Tree* root);
void insert(Tree* root, int value);

int color(Node* node){
    if (node == NULL)    
        return BLACK;
    else
        return node->color;
}

void changeColor(Node* node){
    node->color = !node->color;
    if(node->esq != NULL)
        node->esq->color = !node->esq->color; //inverte as cores

    if(node->dir != NULL)
        node->dir->color = !node->dir->color; //inverte as cores
}

Node* rotateLeft(Node *node){
    Node* tmp = node->dir;
    node->dir = tmp->esq;
    tmp->esq = node;
    tmp->color = node->color;
    node->color = RED;
    return tmp;
}

Node* rotateRight(Node *node){
    Node* tmp = node->esq;
    node->esq = tmp->dir;
    tmp->dir = node;
    tmp->color = node->color;
    node->color = RED;
    return tmp;
}

Node* moveToLeftRed(Node* node) {
    changeColor(node);
    if (color(node->dir->esq) == RED)
    {
        node->dir = rotateRight(node->dir);
        node = rotateLeft(node);
        changeColor(node);
    }
    return node;
}

Node* moveToRightRed(Node* node) {
    changeColor(node);
    if (color(node->esq->esq) == RED)
    {
        node = rotateRight(node);        
        changeColor(node);
    }
    return node;
}

Node* assert(Node* node){
    if ( color(node->dir) == RED ) 
        node = rotateLeft(node);

    if ( node->esq != NULL && color(node->dir) == RED && color(node->esq->esq) == RED )
        node = rotateRight(node);
    
    if ( color(node->esq) == RED && color(node->dir) == RED )
        changeColor(node);
    
    return node;
}

int insertInLLRBTree(Tree* root, int value){
    int resp;
    *root = insertNodeInLLRB(*root, value, &resp);
    if ((*root) != NULL){
        (*root)->color = BLACK;
    }
    return resp;
}

Node* insertNodeInLLRB(Node* node, int value, int *resp){
    if (Node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL){
            *resp = 0;
            return NULL;
        }

        newNode->key = value;
        newNode->color = RED;
        newNode->esq = NULL;
        newNode->dir = NULL;
        *resp = 1;
        return newNode;
    }

    if (value == node->key)
        *resp = 0;
    else {
        if (value < node->key)
            node->esq = insertNodeInLLRB(node->esq, value, resp);
        else
            node->dir = insertNodeInLLRB(node->dir, value, resp);
    }

    if( color(node->dir) == RED && color(node->esq) == BLACK  )
        node = rotateLeft(node);
    if( color(node->esq) == RED && color(node->esq->esq) == RED )
        node = rotateRight(node);
    if( color(node->esq) == RED && color(node->dir) == RED )
        changeColor(node);

    return node;
}

int main(int argc, char const *argv[])
{
    Tree* root;    
    create(root);   
    
    insertInLLRBTree(root, 7);
    insertInLLRBTree(root, 4);
    insertInLLRBTree(root, 9);
    insertInLLRBTree(root, 12);
    showInPreOrder(root);

    destroyTree(root);
    return 0;
}

Tree* create(Tree* root){
    root = (Tree*) malloc(sizeof(Tree));
    if (root != NULL) {
        *root = NULL;
    }    
    return root;
}

void destroyNode(Node* node){
    if (node == NULL) {
        return;
    }
    destroyNode(node->esq);
    destroyNode(node->dir);
    free(node);
    node = NULL;
}

void destroyTree(Tree* root){
    if (root == NULL) {
        return;
    }
    destroyNode(*root);
    free(root);    
}

void showInPreOrder(Tree* root){
    if (root == NULL) {    
        return;
    }
    if (root != NULL) {
        printf("%d ", (*root)->key);
        showInPreOrder(&((*root)->esq));
        showInPreOrder(&((*root)->dir));
    }
}

void insert(Tree* root, int value){
    /*verify if tree is valid*/
    if (root == NULL) {
        return;
    }
    
    /*create a new node with new value */
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        return;
    }
    newNode->key = value;
    newNode->dir = NULL;
    newNode->esq = NULL;

    /*let's play*/

    if (*root == NULL) {
        *root = newNode;
    }
    else{
        Node* currentNode = *root;
        Node* previousNode = NULL;

        while(currentNode != NULL){
            previousNode = currentNode;
            if (value == currentNode->key) {
                free(newNode);
                return;
            }
            if (value > newNode->key)
                currentNode = currentNode->dir;            
            else
                currentNode = currentNode->esq;            
        }
        if (value > currentNode->key) 
            previousNode->dir = newNode;        
        else
            previousNode->esq = newNode;
    }
    return;
}