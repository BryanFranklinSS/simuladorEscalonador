/* fila.h */

/* Tipos exportado */
typedef struct fila Fila;
typedef struct lista Lista;

struct lista {	// estrutura lista para implementa��o da lista
	float info;
	int inf[5];
	struct lista* prox;
};

struct fila {
	Lista* ini;	// ponteiro para o n� do in�cio da fila
	Lista* fim;	// ponteiro para o n� do fim da fila
};



void escalonador(Fila* f, Fila* g);

Lista* processo_retira(Lista* f, int id);

/* Fun��o cria
** Aloca mem�ria para uma estrutura do tipo Fila e retorna o ponteiro
*/
Fila* fila_cria(void);

/* Fun��o insere
** Insere um elemento no fim da Fila
*/
void fila_insere(Fila* f, float v);

/* Fun��o retira
** Remove o elemento do in�cio da Fila
*/
float fila_retira(Fila* f);

/* Fun��o vazia
** Retorna um inteiro (0 ou 1), indicando se a Fila est� vazia ou n�o
*/
int fila_vazia(Fila* f);

/* Fun��o libera
** Libera a mem�ria alocada para a Fila
*/
void fila_libera(Fila* f);

void fila_imprime(Fila* f);


