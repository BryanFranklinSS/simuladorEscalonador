// a parte que verifica o processo de maior prioridade
// deve ser implementado na fun��o de cria��o de processos
// para que a fila de prontos seja organizada de acordo com as
// prioridades dos processos que ser�o inseridos nela

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

	
	

	
Fila* fila_cria(void) {						// cria uma fila, alocando mem�ria para ela
	Fila* f = (Fila*) malloc(sizeof(Fila));	// aloca mem�ria do tamanho de uma fila
	f->ini = f->fim = NULL;	
					// inicializa os dois ponteiros (ini e fim) como nulos, pois a fila est� vazia
	return f;								// retorna o ponteiro que aponta para o endere�o alocado
}

void insere(Fila* f, Lista* n){
	n->prox = NULL;
	if(f->fim !=NULL)
	   f->fim->prox =n;
	else
	   f->ini = n;
	   f->fim = n;
}


	
void fila_insere(Fila* f, float v) {			// insere um elemento (n�) no fim da fila 
	Lista* n = (Lista*) malloc(sizeof(Lista));	// aloca mem�ria para o novo n�
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
	n->inf[4] = 1;                              //o estado dos processos criados s�o considerados como pronto
						
	n->prox = NULL;	
								// faz o pr�ximo do n� ser nulo, pois ser� o �ltimo
	if(f->fim != NULL){
	
		f->fim->prox = n;
									// verifica se a fila n�o est� vazia...
				}					// se n�o estiver, apenas faz o atual n� do fim apontar para o novo n� criado
	else										// caso contr�rio...
		f->ini = n;									// j� que a fila est� vazia, o novo n� ser� tanto o �ltimo como o primeiro. Ent�o, � preciso atualizar "ini" tamb�m
	f->fim = n;	
	
	
	printf("PROCESSO (id: %d) CRIADO...", n->inf[0]);
	for(i = 0; i<5; i++){
		printf("\nv[%d] = %d", i, f->fim->inf[i]);
	}printf("\n\n");				
}

int fila_vazia(Fila* f) {		// verifica se a fila est� vazia ou n�o
	return (f->ini == NULL);	// retorna o resultado (0 ou 1) da opera��o l�gica de igualdade entre o ponteiro "ini" e NULL (se for NULL, a fila est� vazia: retorna 1)
}

float fila_retira(Fila* f) {		// remove o primeiro elemento da fila (FIFO)
	Lista* t;						// ponteiro auxiliar para guardar o n� que vai ser removido
	float v;
	if(fila_vazia(f)) {				// verifica se a fila est� vazia. Se estiver...
		printf("Fila vazia!\n");		// imprime mensagem de fila vazia
		exit(1);						// e encerra o programa
	}								// se n�o estiver, continua a fun��o
	t = f->ini;						// guarda temporariamente o endere�o do primeiro n�
	v = t->info;					// guarda temporariamente a informa��o do primeiro n�
	f->ini = t->prox;				// atualiza ponteiro "ini" para o pr�ximo elemento da fila
	if(f->ini == NULL)				// se a fila tiver ficado vazia ap�s a remo��o...
		f->fim = NULL;					// atualiza tamb�m o ponteiro do fim para NULL
	free(t);						// libera o endere�o do n� removido
	return v;						// retorna o valor do n� removido (float)
}

void fila_libera(Fila* f) {		// libera a mem�ria alocada para a fila
	Lista* q = f->ini;			// ponteiro auxiliar para come�ar a percorrer a lista da fila desde o in�cio
	while(q != NULL) {			// la�o para percorrer a lista da fila
		Lista* t = q->prox;			// guarda o endere�o do pr�ximo n� para que o atual seja liberado sem perder a lista
		free(q);					// libera o n� atual
		q = t;						// aponta para o pr�ximo n� (que estava guardado em "t")
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

