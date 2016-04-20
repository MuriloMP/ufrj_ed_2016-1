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

typedef struct Word {
    char word[50];
    int count;
} Word;

int main(int argc, char const *argv[]) {

    Word wordList[6000];
    char line[100];
    int i = 0;
    int j = 0;
    int k = 0;

    while( (scanf("%[^\n]%*c", &line) == 1) ) {
        strcpy(wordList[i].word, line);
        wordList[i].count = 1;
        i += 1;
    }
    
    for( j = 0; j < i; j++ ){
      for( k = 0; k < j; k++ ){
        if( strcmp(wordList[j].word,wordList[k].word) > 1 ){
            wordList[j].count += 1;
        }
      }
      printf("%s %d ", wordList[j].word, wordList[j].count);
    }
    

    return 0;
}
