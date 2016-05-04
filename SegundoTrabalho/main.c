#include <stdio.h>
#include <stdlib.h>

#define MAX 128

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node Node;

int main(int argc, char const *argv[]) {
    int key, value, i, count;
    int occurrencyList[MAX];
    Node *tmp = (Node*)malloc(sizeof(Node));
    Node List[MAX];

    //initialize vector
    for (i = 0; i < MAX; i++) {
        List[i].next = NULL;
        occurrencyList[i] = 0;
    }

    while(scanf( "%d %d", &key, &value ) != EOF) {
        if(key == 0 && value == 0) break;

        occurrencyList[value]++;
        count++;

        Node *ptr = (Node*)malloc(sizeof(Node) );

        ptr->value = value;
        ptr->next = NULL;

        if(List[key].next == NULL) {
            List[key].next = ptr;
        } else {
            tmp = List[key].next;
            while( tmp->next != NULL ) {
                tmp = tmp->next;
            }
            tmp->next = ptr;
        }     
    }

    for ( i = 1; i <= count; ++i) {
        printf("%d: %d\n", i, occurrencyList[i]);
    }

    printf("Fim de programa\n");
    
    return 0;
}