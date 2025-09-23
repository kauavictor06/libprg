#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p, int* valor);
int topo_pilha(pilha_t* p, int* valor);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);

typedef struct fila fila_t;
fila_t criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
} lista_linear_t;
lista_linear_t* criar(int capacidade);
void inserir(lista_linear_t* lista, int valor);
int buscar(lista_linear_t* lista, int valor);
void remover(lista_linear_t* lista, int valor);
int vazia(lista_linear_t* lista);
int cheia(lista_linear_t* lista);
void destruir(lista_linear_t* lista);

#endif

//teste
