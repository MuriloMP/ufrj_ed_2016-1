#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct _Node{
    int value;
    int color;
    struct _Node* left;
    struct _Node* right;
} Node;

int color(Node* node);
Node* recolor(Node* node);
Node* rotationLeft(Node* node);
Node* rotationRight(Node* node);
Node* insert(Node* node, int value);
void printTree(Node* root);

int main(int argc, char const *argv[])
{
    Node* node = NULL;
    node = insert(node, 3);
    node = insert(node, 1);
    node = insert(node, 10);
    printTree(node);    
    return 0;
}

Node* recolor(Node* node){
    node->color = RED;
    Node* son = node->left;
    son->color = BLACK;
    son = node->right;
    son->color = BLACK;
    free(son);
    return node;
}

int color(Node* node) {
    return (node->color == RED) ? RED:BLACK;
}

Node* rotationLeft(Node* node){
    Node* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    tmp->color = node->color;
    node->color = RED;
    return tmp;
}

Node* rotationRight(Node* node){
    Node* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    tmp->color = node->color;
    node->color = RED;
    return node;
}

void printTree(Node* root){    
    if (root == NULL) {
        return;
    }
    if (root != NULL){
        if(root->color == RED){
            printf("%d, R\n",root->value);
        } else{
            printf("%d, N\n", root->value);
        }
        printTree(root->left);
        printTree(root->right);
    }    
}

Node* insert(Node* node, int value){
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->value = value;
        node->color = RED;
        node->left = NULL;
        node->right = NULL;
    } else {
        if ( color(node) == BLACK && color(node->left) == RED && color(node->right) == RED) {
            node = recolor(node);
            if (value < node->value) {
                insert(node->left, value);
            } else {
                insert(node->right, value);
            }            
        }
        
        if ( color(node) == BLACK && color(node->left) == BLACK && color(node->right) == RED ){
            node = rotationLeft(node);
        }

        Node* leftNode = node->left;

        if ( color(node) == BLACK && color(node->left) == RED && color(leftNode->left) == RED ) {
            node = rotationRight(node);                
        }

        free(leftNode);
    }
    return node;
}