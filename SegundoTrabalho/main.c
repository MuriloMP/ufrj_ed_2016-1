#include <stdio.h>
#include <stdlib.h>

struct _node {
    int key;
    int value;
    struct _node *next;
    struct _node *prev;
};

typedef struct _node Node;

Node *head = NULL;
Node *last = NULL;
Node *node = NULL;

void insertFirst(int key, int value);
void insertInLast(int key, int value);
void printList();

int main(int argc, char const *argv[]) {
    
    int key, value;

    while(scanf( "%d %d", &key, &value ) != EOF){
    	if( key == 0 && value == 0 ) break;

    	if( head == NULL ) {
    	    insertFirst(key, value);
    	} else {
            insertInLast(key, value);
        }
    }

    // for (i = 0; i < 10; i++) {
    //     insertInLast(i);
    // }

    printList();
    
    return 0;
}

void insertFirst(int key, int value){
    Node *link = (Node*) malloc(sizeof(Node));
    link->key = key;
    link->value = value;

    if (head == NULL) {
        last = link;
    } else {
      //update first prev link
      head->prev = link;
   }

   //point it to old first link
   link->next = head;
    
   //point first to new first link
   head = link;
}

void insertInLast(int key, int value) {
    Node *link = (Node*)malloc(sizeof(Node));
    link->key = key;
    link->value = value;

    if (head == NULL) {
        last = link;
    } else {
        last->next = link;
        link->prev = last;
    }
    last = link;
}

void printList() {
    Node *ptr = head;    
    while(ptr != NULL) {
        printf("%d %d \n",ptr->key, ptr->value);
        ptr = ptr->next;
    }   
}
