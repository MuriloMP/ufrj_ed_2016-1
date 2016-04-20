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

typedef struct _Word {
	int count;
	char word[100];
} Word;

//typedef struct _Word Word;

int main(int argc, char const *argv[]) {

	Word *wordList;

	//int count = 0;
	int i;
	char word[100];
	int hasWord = 0;
	int n = 10;
	int countWords = 0; //quantas palavras tem na lista

	wordList = NULL;
	wordList = ( Word* )malloc( n * sizeof( Word ) );

	if ( !wordList ) {
		printf("Memória insuficiente\n");
	}
	else {
		while(scanf( "%[^\n]%*c", word ) == 1) {
			for (i = 0; i < countWords; i++) {
				if ( (strcmp(wordList[i].word, word) == 0) ) {
					wordList[i].count += 1;
					hasWord = 1;
				}
			}

			if (!hasWord) {
				if (countWords == n) {
					n += 10;
					realloc(wordList, ((n + 10) * sizeof(Word)) );
				}
				strcpy(wordList[countWords].word, word);
				wordList[countWords].count = 1;
				countWords ++;
			}
			hasWord = 0;
		}
	}

	int x, y;
	Word temp;
	
	for ( x = 0 ; x < (countWords); x++ ) {
		for ( y = x+1 ;  y < countWords; y++ ) {
			if ( wordList[y].count > wordList[x].count ){
				temp = wordList[y];
				wordList[y] = wordList[x];
				wordList[x] = temp;
			}
		}
	}

	for (i = 0; i  <= 14; i++) {
		printf("%s %d \n", wordList[i].word, wordList[i].count );
	}

	free(wordList);

	return 0;
}