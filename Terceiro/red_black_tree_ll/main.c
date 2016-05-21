#include<stdio.h>
#include<stdlib.h>

struct rbllNode{
    int key;
    char color;
    struct rbllNode *esquerda;
    struct rbllNode *direita;
    struct rbllNode *parent;
};
typedef struct rbllNode rbllNode;

rbllNode* root = NULL;

void esquerdaRotaciona(struct rbllNode *root,struct rbllNode *x);
void direitaRotaciona(struct rbllNode *root,struct rbllNode *y);
void rbInsertFix(struct rbllNode *root,struct rbllNode *z);
void rbInsert(int val);
void inorderTree(struct rbllNode* root);

int main(int argc, char const *argv[]) {    
    int loop = 1;
    while(loop){
        printf("\nRed Black Tree Management - Enter your choice : ");
        printf("\n1\tInsert into arvorern\n2\tDisplay arvorern inorder\n");
        int choice;
        int val;
        scanf("%d",&choice);
        while(1){
            scanf("%d",&val);
            rbInsert(val);
        }
        printf("\nPress '0' to terminate and '1' to continue : ");
        scanf("%d",&loop);
    }
    return 0;
}


void esquerdaRotaciona(struct rbllNode *root,struct rbllNode *x){
    struct rbllNode *y;
    y = x->direita;  
    x->direita = y->esquerda; 
    if( y->esquerda != NULL){
        y->esquerda->parent = x; 
    }
    y->parent = x->parent;
    if( x->parent == NULL){
        root = y;
    }
    else if( x->key == x->parent->esquerda->key){
        x->parent->esquerda = y; 
    }
    else x->parent->direita = y;
    y->esquerda = x; 
    x->parent = y; 

    return;
}

void direitaRotaciona(struct rbllNode *root,struct rbllNode *y){
    struct rbllNode *x;
    x = y->esquerda; 
    y->esquerda = x->direita; 
    if ( x->direita != NULL){
        x->direita->parent = y;
    }
    x->parent = y->parent; 
    if( y->parent == NULL){
        root = x;
    } 
    else if( y->key == y->parent->esquerda->key){
        y->parent->esquerda = x; 
    }
    else y->parent->direita = x;
    x->direita = y; 
    y->parent = x; 

    return;

}

void rbInsertFix(struct rbllNode *root,struct rbllNode *z){
    struct rbllNode *y;
    while (z->parent->color == 'r'){
        if (z->parent->key == z->parent->parent->esquerda->key){
            y = z->parent->parent->direita;
            if (y->color == 'r'){
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            }
            else if (z->key == z->parent->direita->key){
                z = z->parent;
                esquerdaRotaciona(root,z);
            }
            z->parent->color = 'b';
            z->parent->parent->color = 'r';
            direitaRotaciona(root,z->parent->parent);
        }
        else {
            y = z->parent->parent->esquerda;
            if (y->color == 'r'){
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            }
            else if (z->key == z->parent->esquerda->key){
                z = z->parent;
                direitaRotaciona(root,z);
            }
            z->parent->color = 'b';
            z->parent->parent->color = 'r';
            esquerdaRotaciona(root,z->parent->parent);
        }
    }
    root->color = 'b';
}

void rbInsert(int val){
    struct rbllNode *z = (struct rbllNode*)malloc(sizeof(struct rbllNode));
    z->key = val;
    z->esquerda = NULL;
    z->direita = NULL;
    z->color = 'r';
    struct rbllNode *x = root;
    struct rbllNode *y;
    if ( root == NULL ){
        root = z;
        root->color = 'b';
        return;
    }
    while ( x != NULL){
        y = x;
        if ( z->key < x->key){
            x = x->esquerda;
        }
        else x = x->direita;
    }
    z->parent = y;
    if ( y == NULL){
        root = z;
    }
    else if( z->key < y->key ){
        y->esquerda = z;
    }
    else y->direita = z;
    rbInsertFix(root,z);

    return;
}

void inorderTree(struct rbllNode* root){
    struct rbllNode* temp = root;
    if (temp != NULL){
        inorderTree(temp->esquerda);
        printf(" %d-%c ",temp->key,temp->color);
        inorderTree(temp->direita);
    }
}