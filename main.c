#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


 void execucao(Fila* mp, Fila* pnt, Fila* esp);
 
int main(void){

	
	Fila* f_espera = fila_cria();
	Fila* f_pronto = fila_cria();
	Fila* MP = fila_cria();
	
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	
	    printf("fila[processos pronto]: ");

    fila_imprime(f_pronto);
    
        printf("\nESCALONAMENTO DE PROCESSOS INICIADO...");
    escalonador(MP, f_pronto);
    escalonador(MP, f_pronto);
    escalonador(MP, f_pronto);
	
	    printf("\nEXECUCAO INICIADA...\n");
	execucao(MP, f_pronto, f_espera);
	
	fila_libera(f_espera);
	fila_libera(f_pronto);
	fila_libera(MP);
	
	return 0;
}

 void execucao(Fila* mp, Fila* pnt, Fila* esp){
 	Lista* l;
 	
 	l = mp->ini;
 	mp->ini = l->prox;
 	if(mp->ini == NULL)
 	  mp->fim == NULL;
 	  
 	  if(l->inf[1] == 1){
 	  	insere(pnt, l);	
 	  
	   }
	   if(l->inf[1] == 2){
	   	insere(esp, l);
	   }
	   
	   printf("\================================\n ");
	   printf("processo (id:%d) executado...\n", l->inf[0]);
	   if(l->inf[1] == 1)
	     printf("retorna para fila[processos prontos]\n");
	   if(l->inf[1] == 2)
	     printf("retorna para fila[espera]\n");
	   
	    printf("\nfila[MP]: ");
	    fila_imprime(mp);
	   
	   	printf("\nfila[processos prontos]: ");
 	  	fila_imprime(pnt);
 	  	  
 	  	printf("\nfila[espera]: ");
	   	fila_imprime(esp);
       
	  free(l); 
 	
 	
 }
