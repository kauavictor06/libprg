#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

typedef struct pilha {
    int* elementos;
    int topo;
    int capacidade;
} pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t* p, int valor);
int desempilhar(pilha_t* p);
int topo_pilha(pilha_t* p, int* valor);
int tamanho_pilha(pilha_t* p);
void imprimir_pilha(pilha_t* p);
void destruir_pilha(pilha_t* p);

// /---fila---/
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
bool fila_cheia(fila_t* fila);
int desinfileirar(fila_t* fila);
bool vazia(fila_t* fila);
void destruir_fila(fila_t* fila);
void exibir(fila_t* fila);




typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada);
bool lista_cheia (lista_linear_t* lista);
void inserir(lista_linear_t* lista, int valor);
int buscar(lista_linear_t* lista, int valor);
bool lista_vazia(lista_linear_t* lista);
void remover(lista_linear_t* lista);
void destruir_lista(lista_linear_t* lista);
void exibir_lista(lista_linear_t* lista);
int primeiro(lista_linear_t* lista);


typedef struct no no_t;
no_t* criar_lista_enc(int valor);
void adicionar_lista_enc(no_t** inicio, int valor);
no_t* buscar_lista_enc(no_t** inicio, int valor);
void remover_lista_enc(no_t** inicio, int valor);
void destruir_lista_enc(no_t** inicio);
#endif

typedef struct no_duplo no_duplo_t;
no_duplo_t* criar_lista_encadeada_dupla(int valor);
void adicionar_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void remover_lista_encadeada_dupla(no_duplo_t** inicio, int valor);