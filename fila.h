/* fila.h */

/* Tipos exportado */
typedef struct fila Fila;
typedef struct lista Lista;

struct lista {	// estrutura lista para implementação da lista
	float info;
	int inf[5];
	struct lista* prox;
};

struct fila {
	Lista* ini;	// ponteiro para o nó do início da fila
	Lista* fim;	// ponteiro para o nó do fim da fila
};



void escalonador(Fila* f, Fila* g);

Lista* processo_retira(Lista* f, int id);

/* Função cria
** Aloca memória para uma estrutura do tipo Fila e retorna o ponteiro
*/
Fila* fila_cria(void);

/* Função insere
** Insere um elemento no fim da Fila
*/
void fila_insere(Fila* f, float v);

/* Função retira
** Remove o elemento do início da Fila
*/
float fila_retira(Fila* f);

/* Função vazia
** Retorna um inteiro (0 ou 1), indicando se a Fila está vazia ou não
*/
int fila_vazia(Fila* f);

/* Função libera
** Libera a memória alocada para a Fila
*/
void fila_libera(Fila* f);

void fila_imprime(Fila* f);


