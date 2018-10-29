// a parte que verifica o processo de maior prioridade
// deve ser implementado na função de criação de processos
// para que a fila de prontos seja organizada de acordo com as
// prioridades dos processos que serão inseridos nela

/* fila.c */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Lista* processo_retira(Fila* f, int prio){
	Lista* p;
	Lista* ant;
	
	p = f->ini;
	if( p->inf[2] == prio){
		f->ini = f->ini->prox;
		return p;
		free(p);
		
   }
	 else{
	   for( p = f->ini; p->inf[2]!= prio; p= p->prox){
	              ant = p;
	 }
	    ant->prox = p->prox;
	 
	    return p;
	    free(p);
  }
}


 
 void escalonador(Fila* mp, Fila* pronto){
	int maiorprio = 0, tempoexe = 0;
	Lista* aux;
	Lista* aux2;
	
	for(aux = pronto->ini; aux!=NULL; aux = aux->prox){
		if(aux->inf[2]>maiorprio){
			maiorprio = aux->inf[2];
			tempoexe = aux->inf[3];
			aux2 = aux;
		} 
		else if(aux->inf[2] == maiorprio){
			if(aux->inf[3]<tempoexe)
			aux2 = aux;		
		}

	}
	printf("\nPROCESSO  (id %d) MOVIDO PARA MP...\n", aux2->inf[0]);
	 insere(mp, processo_retira(pronto, maiorprio)) ;
	        printf("\n");
	 printf("fila[processos pronto]: ");
	 fila_imprime(pronto);
	        printf("\n");
	 printf("fila[MP]: ");
	 fila_imprime(mp);
	 printf("===========================");
}

	
	

	
Fila* fila_cria(void) {						// cria uma fila, alocando memória para ela
	Fila* f = (Fila*) malloc(sizeof(Fila));	// aloca memória do tamanho de uma fila
	f->ini = f->fim = NULL;	
					// inicializa os dois ponteiros (ini e fim) como nulos, pois a fila está vazia
	return f;								// retorna o ponteiro que aponta para o endereço alocado
}

void insere(Fila* f, Lista* n){
	n->prox = NULL;
	if(f->fim !=NULL)
	   f->fim->prox =n;
	else
	   f->ini = n;
	   f->fim = n;
}


	
void fila_insere(Fila* f, float v) {			// insere um elemento (nó) no fim da fila 
	Lista* n = (Lista*) malloc(sizeof(Lista));	// aloca memória para o novo nó
	n->info = v;
	Lista* aux;
	int i, maiorprio;
	srand(time(NULL));
	
//	for(i=1; i<=3; i++){
	//	printf("v[%d]: ", i);
	printf("prio "); // apagar
		scanf("%d", &n->inf[2]);
	printf("tipo de processo: ");
	    scanf("%d", &n->inf[1]);
//		}
		printf("\n");
		

	n->inf[0] = (1000*(1 + rand() % 9)) + (100*(1 + rand() % 9)) + (10*(1 + rand() % 9)) + (1 + rand() % 9);
	n->inf[3] = (1 + rand() % 9);
	n->inf[4] = 1;                              //o estado dos processos criados são considerados como pronto
						
	n->prox = NULL;	
								// faz o próximo do nó ser nulo, pois será o último
	if(f->fim != NULL){
	
		f->fim->prox = n;
									// verifica se a fila não está vazia...
				}					// se não estiver, apenas faz o atual nó do fim apontar para o novo nó criado
	else										// caso contrário...
		f->ini = n;									// já que a fila está vazia, o novo nó será tanto o último como o primeiro. Então, é preciso atualizar "ini" também
	f->fim = n;	
	
	
	printf("PROCESSO (id: %d) CRIADO...", n->inf[0]);
	for(i = 0; i<5; i++){
		printf("\nv[%d] = %d", i, f->fim->inf[i]);
	}printf("\n\n");				
}

int fila_vazia(Fila* f) {		// verifica se a fila está vazia ou não
	return (f->ini == NULL);	// retorna o resultado (0 ou 1) da operação lógica de igualdade entre o ponteiro "ini" e NULL (se for NULL, a fila está vazia: retorna 1)
}

float fila_retira(Fila* f) {		// remove o primeiro elemento da fila (FIFO)
	Lista* t;						// ponteiro auxiliar para guardar o nó que vai ser removido
	float v;
	if(fila_vazia(f)) {				// verifica se a fila está vazia. Se estiver...
		printf("Fila vazia!\n");		// imprime mensagem de fila vazia
		exit(1);						// e encerra o programa
	}								// se não estiver, continua a função
	t = f->ini;						// guarda temporariamente o endereço do primeiro nó
	v = t->info;					// guarda temporariamente a informação do primeiro nó
	f->ini = t->prox;				// atualiza ponteiro "ini" para o próximo elemento da fila
	if(f->ini == NULL)				// se a fila tiver ficado vazia após a remoção...
		f->fim = NULL;					// atualiza também o ponteiro do fim para NULL
	free(t);						// libera o endereço do nó removido
	return v;						// retorna o valor do nó removido (float)
}

void fila_libera(Fila* f) {		// libera a memória alocada para a fila
	Lista* q = f->ini;			// ponteiro auxiliar para começar a percorrer a lista da fila desde o início
	while(q != NULL) {			// laço para percorrer a lista da fila
		Lista* t = q->prox;			// guarda o endereço do próximo nó para que o atual seja liberado sem perder a lista
		free(q);					// libera o nó atual
		q = t;						// aponta para o próximo nó (que estava guardado em "t")
	}
	free(f);					// libera, por fim, o ponteiro da fila inteira
}

void fila_imprime(Fila* f){
	Lista* aux;
	int i = 0;
			for(aux = f->ini; aux!= NULL; aux = aux->prox){
	  // for(i=0; i<5; i++){
	   
	       printf("\n(id:%d) ", aux->inf[0]);
        // } 
		//printf("\n");
	} printf("\n");
}

