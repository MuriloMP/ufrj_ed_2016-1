#include<stdio.h>
#include<stdlib.h>

struct Node {
    int key;
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

int main(int argc, char const *argv[])
{
    Tree* root;    
    rootcreate(root);   
    
    insert(root, 7);
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