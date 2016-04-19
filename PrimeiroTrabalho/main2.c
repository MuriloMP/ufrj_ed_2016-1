/*
 * Author: Leonardo Gonçalves
 * Data: 16/04/2016
 * Descript: O programa deverá receber uma lista de palavras 
 * de um arquivo de texto, avaliar quantas vezes cada 
 * palavra foi utilizada e exibir as cinco palavras mais
 * repetidas no texto.
 *
 * Plano: 
 * 1. Utilizar uma struct para armazenar a palavra e a
 * quantidade de vezes que ela foi utilizada;
 * 2. Armazenar as structs em um array estático.
 * 3. Ordernar o array em ordem decrescente de repetições
 * 4. Exibir os cinco primeiros elementos do array
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _node {
    char word[50];
    int count;
    struct _node *next;
    struct _node *previous;
} ;

typedef struct _node List;

int main(int argc, char const *argv[]) {

    List *head_node;
    char line[100];

    head_node = (List*)malloc(sizeof(List));

    if (!head_node) {
        printf("você alocou errado seu filho da puta\n");
    }
    else {
        head_node->next = NULL;
        head_node->previous = NULL;
        free(head_node);
    }

    return 0;
}
