#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"


 void execucao(Fila* mp, Fila* pnt, Fila* esp);
 
int main(void){

	
	Fila* f_espera = fila_cria();
	Fila* f_pronto = fila_cria();
	Fila* f_pronto2 = fila_cria();
	Fila* MP = fila_cria();
	

	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	
	    printf("fila[processos pronto]: ");

    fila_imprime(f_pronto);
    
        printf("\n================================\n ");
        printf("\nESCALONAMENTO DE PROCESSOS INICIADO...");
        printf("\n================================\n ");
    escalonador(MP, f_pronto);
    escalonador(MP, f_pronto);
    escalonador(MP, f_pronto);
	
	    printf("\nEXECUCAO INICIADA...\n");
	execucao(MP, f_pronto2, f_espera);
	execucao(MP, f_pronto2, f_espera);
	execucao(MP, f_pronto2, f_espera);
	
	fila_libera(f_espera);
	fila_libera(f_pronto);
	fila_libera(MP);
	
	return 0;
}

 void execucao(Fila* mp, Fila* pnt, Fila* esp){
 	Lista* k = (Lista*) malloc(sizeof(Lista));
 	Lista* l;
 	int cont, i;
 	
 	l = mp->ini;
 	mp->ini = mp->ini->prox;
 	if(mp->ini == NULL)
 	  mp->fim == NULL;
 	  
 	  for(i=0; i<4; i++){
			k->inf[i] = l->inf[i];
		}
 	  
 	  if(l->inf[1] == 1){
 	  	insere(pnt, k);	
 	  
	   }
	   if(l->inf[1] == 2){
	   	insere(esp, k);
	   }
	   
	   printf("================================\n");
	   printf("processo (id:%d) - prio: %d, executando...\n", l->inf[0], l->inf[2]);
	     printf("  tempo de execucao: %d segundos\n", l->inf[3]);
	     	sleep(1);
	      for(cont = 1; cont<=l->inf[3]; cont++ ){
	      	printf("  %d... ", cont);
	      	sleep(1);
		  } 
		  printf("\n  execucao concluida... ");
		  sleep(1);
	   
	   if(l->inf[1] == 1)
	     printf("  enviado para fila[processos prontos]\n");
	   if(l->inf[1] == 2)
	     printf("  enviado para fila[espera]\n");
	     
	    printf("================================\n");
	    printf("\nfila[MP]: ");
	    fila_imprime(mp);
	   
	   	printf("\nfila[processos prontos]: ");
 	  	fila_imprime(pnt);
 	  	  
 	  	printf("\nfila[espera]: ");
	   	fila_imprime(esp);
       
	  free(l); 
 	
 	
 }
