#include <stdio.h>
#include <stdlib.h>

#define TAM 128

typedef struct _node {
    int value;
    struct _node *next;
}Node;

void destroyList(Node *ptList);

int main(int argc, char const *argv[]) {
    int i;
    int count=1;
    int key, value;
    Node List[TAM];
    int vetorOc[TAM];
    Node *aux;
    for (i = 0; i < TAM; i++) {        
        List[i].next = NULL;
        vetorOc[i]=0;
    }
    while(scanf( "%d %d", &key, &value ) != EOF) {
        if( key == 0 && value == 0 ) break;
        Node *nozinho = (Node*)malloc(sizeof(Node));
        nozinho->value = value;
        nozinho->next=NULL;
        if(List[key].next==NULL)	List[key].next = nozinho;
        else{
		    aux = List[key].next;
		    while(aux->next!=NULL){
		    	aux = aux->next;
		    }
		    aux->next=nozinho;
		    vetorOc[value]++;
		}
		count++;
	    printf("%d\n", List[key].next  ->value);
    }
    int vetorResp[TAM];
    int j = 0;
    for(i=1;i<count;i++){
    	if(vetorOc[i]==0){
    		vetorResp[j]=i;
    		if(List[i].next!=NULL){
				aux = List[i].next;
                printf("\n%d\n", aux->value);
				while(aux->next!=NULL){
                    printf("\n%d\n", aux->next->value);
					if(vetorOc[aux->value]>0){
						vetorResp[j]=aux->value;
                        j++;
						vetorOc[aux->value]--;
					}
					aux = aux->next;
				}
				j++;
				vetorResp[j]=aux->value;
				vetorOc[aux->value]--;
				if(vetorOc[aux->value]==0) vetorOc[aux->value]--;
			}
    	}
    }
    for (i = 0; i < count; i++){
    	printf("%d ", vetorResp[i]);
    }
   	printf("\n");
    return 0;
}
