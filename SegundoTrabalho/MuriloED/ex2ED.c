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
    int vetorOrdem[TAM];
    Node *aux;
    for (i = 0; i < TAM; i++) {        
        List[i].next = NULL;
        vetorOc[i]=0;
    }
    while(scanf( "%d %d", &key, &value ) != EOF) {
        if( key == 0 && value == 0 ) break;
        vetorOrdem[count]=value;
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
		}
        vetorOc[value]++;
		count++;
    }
    int vetorResp[TAM];
    int j,k;
    int contador=0;
    j=1;
    while(j<count){
       for(i=1;i<count;i++){
            if(j==1){
                if(vetorOc[i]==0){
                    vetorResp[j]=i;
                    j++;
                    break;
                }
            }
            else{
            	if(vetorOc[vetorOrdem[i]]==contador){
                    vetorResp[j]=vetorOrdem[i];
                    vetorOc[vetorOrdem[i]]--;
                    j++;
            	}
            }
        }
        contador++;
    }
    for(i=1;i<j;i++)    
        printf("%d ",vetorResp[i]);
   	printf("\n");
    return 0;
}
