#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    int color; // 1 for red, 0 for black
    struct _node* left;
    struct _node* right;
    struct _node* father;
}NODE;

NODE* recolor(NODE* node){
    node->color = 1;
    NODE* son = node->left;
    son->color = 0;
    son = node->right;
    son->color = 0;
    free(son);
    return node;
}

int color(NODE* node){
    return (node->color == 1) ? 1:0;
}

NODE* rotation_left(NODE* node);
NODE* rotation_right(NODE* node);

NODE* insert(NODE* node,int value){
    if (node == NULL){
        node = (NODE*) malloc(sizeof(NODE));
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->color = 1;
    } else {
        if(color(node) == 0 && color(node->left) == 1 && color(node->right) == 1){
            node = recolor(node);
            if(value < node->value){
                insert(node->left,value);
            } else {
                insert(node->right,value);
            }
        } if (color(node) == 0 && color(node->left) == 0 && color(node->right) == 1){
            node = rotation_left(node);    
        } 
        NODE* left_node = node->left;
        if (color(node) == 0 && color(node->left) == 1 && color(left_node->left) == 1){
            node = rotation_right(node);
        }
        free(left_node);
    }
    return node;
}

NODE* rotation_left(NODE* node){
    NODE* x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = 1;
    return x;
}

NODE* rotation_right(NODE* node){
    NODE* x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    node->color = 1;
    return node;
}

void printTree(NODE* root){
    if (root != NULL){
        if(root->color == 1){
            printf("%d, R\n",root->value);
        } else{
            printf("%d, N\n", root->value);
        }
        printTree(root->left);
        printTree(root->right);
    }
}


int main(void){
    char z,z2;
    int x;

    NODE* i = NULL;
    scanf("%c%d%c",&z,&x,&z2);
    while(z != EOF || x != EOF || z2 != EOF){
        if (z == 'p'){
            printTree(i);
            break;
        }
        i = insert(i,x);
        scanf("%c%d",&z,&x);
    }
    return 0;
}