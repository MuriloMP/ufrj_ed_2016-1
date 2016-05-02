/**
* MAC 2301 - Laboratório de Programação
*
* Exercício da aula 3
*
* Assunto: Lista ligada e fila
* Aplicação: ordenação topológica em tempo linear
*
* Programa que executa a mesma tarefa do da aula anterior mas mais rapidamente
* A única modificação é a introdução da fila de saída
*
**/

#include 
#include 

#define MAX 100

struct cel
{
 int chave; /* conteúdo */
 struct cel *prox; /* ponteiro para o próximo elemento */
} ;

/* Para não termos que digitar struct cel toda hora, definimos: */
typedef struct cel celula;

/* Inserção no começo de uma lista com cabeça */
void insereNaLista (int x, celula *lista)
{
 celula *nova;
 nova = malloc (sizeof (celula));
 nova->chave = x;
 nova->prox = lista->prox;
 lista->prox = nova;
}

/* Função de remoção. Remove a lista inteira. */
void removeLista(celula *lista)
{
 celula *temp;
 if(lista != NULL)
 {
   temp = lista->prox;
   while(temp != NULL)
   {
     lista->prox = temp->prox;
     free(temp);
     temp = lista->prox;
   }
   free(lista);
 }
}

void inicializaLista(celula ** ptrLista) /* com cabeça */
{
 *ptrLista = malloc(sizeof(celula));
 (*ptrLista)->prox = NULL;
 (*ptrLista)->chave = -1;
}

/* usada apenas para depuração */
void imprimeLista(celula *lista)
{
 celula *varre = lista->prox;
 printf("\n Conteúdo da lista: \n");
 while(varre != NULL)
 {
   printf(" %d ", varre->chave);
   varre = varre->prox;
 }
 printf("\n-----\n\n");
}

/* Precisaremos de uma fila.
* Vamos implementá-la usando lista ligada com cabeça */
void insereNaFila (int x, celula * fila)
{
 if(fila != NULL)
 {
   celula *nova = malloc(sizeof(celula));
   nova->chave = x;
   /* esta implementação insere no começo e retira do fim */
   nova->prox = fila->prox;
   fila->prox = nova;
 }
}

/* Recebe a fila e devolve a chave do primeiro da fila
* Se a fila estiver vazia, devolve -1
* Possui efeito colateral!! Remove o elemento da fila */
int proximoDaFila (celula * fila)
{
 int valorDeDevolucao;
 celula *anterior;
 celula *percorre;

 anterior = fila;
 percorre = fila->prox;
 while(percorre != NULL)
 {
   if(percorre->prox == NULL)
   {
     anterior->prox = NULL;
     valorDeDevolucao = percorre->chave;
     free(percorre);
     return valorDeDevolucao;
   }
   anterior = percorre;
   percorre = percorre->prox;
 }
 return -1;
}

int main()
{
 int i; /* contador */
 celula *sucessores[MAX]; /* vetor com as listas (no livro é o CB)*/
 int antecessores[MAX];  /* vetor que guarda em [i] o número de
                           antecessores pendentes da tarefa i */
 celula *filaDeSaida; /*  a saída de fato é a impressão na tela,
                         mas usaremos esta fila para guardar as tarefas
                         que já podem ser executadas (i.é, que têm nenhum
                         predecessor) antes de imprimirmos */
 int quantidadeDePares;
 int quantidadeDeTarefas;

 /* variáveis temporárias */
 int umaTarefa, outraTarefa; /* usadas na leitura */

 /* usada para percorrer listas */
 celula *varreSucessores;

 int valorDoProxDaFila;

 printf("\n  Ordenação topológica\n  --------------------\n\n");

 /* vamos agora ler os dados e preencher o vetor de listas */

 printf("\n  Digite a quantidade de tarefas a serem executadas: ");
 scanf("%d", &quantidadeDeTarefas);
 printf("\n  Digite a quantidade de dependências entre as elas: ");
 scanf("%d", &quantidadeDePares);

 /* inicializando os dois vetores */
 for(i = 0; i < quantidadeDeTarefas; i++)
 {
   inicializaLista(&(sucessores[i]));
   antecessores[i] = 0;
 }

 inicializaLista(&filaDeSaida);

 /* lendo dimensões do problema */
 printf("\n  Digite os pares representando as precedências entre as");
 printf("\n  tarefas. As tarefas devem ser números inteiros de zero a ");
 printf("\n  %d e os pares devem relacionar tarefas ", quantidadeDeTarefas-1);
 printf("\"vizinhas\", ou seja,\n  se A antecede B que antecede C, entre");
 printf(" com os pares \n    A B\n  e\n    B C\n  e não entre com o par");
 printf(" implícito A C.\n\n    ");

 /* agora leremos os pares da entrada padrão e montaremos as listas */
 for(i = 0; i < quantidadeDePares; i++)
 {
   scanf("%d %d", &umaTarefa, &outraTarefa);
   /* Esta entrada quer nos dizer que umaTarefa precede outraTarefa */
  
   /* Então insiro outraTarefa na lista de sucessores de umaTarefa */
   insereNaLista(outraTarefa, sucessores[umaTarefa]);
  
   /* E incremento o número de antecessores de outraTarefa */
   antecessores[outraTarefa]++;
  
   printf("    ");
 }

 printf("\n  >>> Uma ordem possível: ");

 /* Agora vamos descobrir a resposta.
  * Para isso varremos uma vez o vetor "antecessores" e guardamos na lista
  * de saída todas as tarefas que já podem ser executadas. Depois, para cada
  * tarefa na lista de saída, imprimimos seu valor (ou seja, mandamos
  * o usuário executar tal tarefa) e varremos sua lista de sucessores
  * decrementado deles em uma unidade o número de antecessores pendentes. Se
  * nesse decremento já encontrarmos um zero, colocamos a tarefa
  * correspondente na fila de saida.
  */

 /* coloca na fila de saída quem não tem pré-requisito */
 for(i = 0; i < quantidadeDeTarefas; i++)
 {
   if(antecessores[i] == 0)
     insereNaFila(i, filaDeSaida);
 }

 valorDoProxDaFila = proximoDaFila(filaDeSaida);
 while(valorDoProxDaFila != -1)
 {
   /* varremos a lista de sucessores da tarefa (varre->chave) e
      decrementaremos o número de antecessores deles e já
      adicionando-os na fila de saída se for o caso */
   varreSucessores = sucessores[valorDoProxDaFila]->prox;
   printf("%d ", valorDoProxDaFila);
   while(varreSucessores != NULL)
   {
     antecessores[varreSucessores->chave]--;
     if(antecessores[varreSucessores->chave] == 0)
       insereNaFila(varreSucessores->chave, filaDeSaida);
     varreSucessores = varreSucessores->prox;
   }
  
   valorDoProxDaFila = proximoDaFila(filaDeSaida);
 }
 removeLista(filaDeSaida);
 printf("\n\n  ");
 system("pause");
 return 0;
}