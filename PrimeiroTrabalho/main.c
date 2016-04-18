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

	Word wordList[5000];
	char line[50];
	int i = 0;

	while( (scanf("%[^\n]%*c", &line) == 1) ) {
		strcpy(wordList[i].word, line);
		//printf("palavra: %s\n", wordList[i].word);
		i += 1;
	}
	return 0;
}