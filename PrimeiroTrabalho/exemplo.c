typedef struct palavra{
    char valor[50];
    int ocorrencia;
} WORD;

void mostraLista(WORD *lista, int n){
    printf("Palavra - Ocorrencias - %d\n", n);
    int i;
    for(i=0;i<n-1;i++){
        printf("%s - %d\n", lista[i].valor,lista[i].ocorrencia);
    }
}

int main(){
    WORD *listaNova=malloc(sizeof(WORD));
    char novaPalavra[50];
    int n,i;
    i = 0;
    n=2;
    scanf("%s", novaPalavra);
    strcpy(listaNova[0].valor,novaPalavra);
    listaNova[0].ocorrencia = 1;
    int teste = 0;
    mostraLista(listaNova,n);
    while(n>=0){
        listaNova=realloc(listaNova,(n)*sizeof(WORD));
        scanf("%s", novaPalavra);
        for(i=0;i<n;i++){
            if(strcmp(novaPalavra,listaNova[i].valor)==0){
                listaNova[i].ocorrencia++;
                teste=1;
                break;
            }
        }
        if(!teste){
            strcpy(listaNova[n-1].valor,novaPalavra);
            listaNova[n-1].ocorrencia = 1;
            n++;
        }
        else
            teste=0;
        mostraLista(listaNova,n);
    }
    return 0;
}