#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
	Lista* aux;
	int i;
	
	Fila* f_espera = fila_cria();
	Fila* f_pronto = fila_cria();
	Fila* MP = fila_cria();
	
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	fila_insere(f_pronto, 3);
	
	    printf("fila de processos prontos:\n");

    fila_imprime(f_pronto);

    escalonador(MP, f_pronto);

    printf("\nfila de processos prontos\napos retirada:\n");
    fila_imprime(f_pronto);
	
	printf("\n processos em MP:\n");
	fila_imprime(MP);
	
	fila_libera(f_espera);
	fila_libera(f_pronto);
	fila_libera(MP);
	
	return 0;
}
