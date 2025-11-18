//
// Created by aluno on 18/11/2025.
//
#include <stdlib.h>

#include "libprg/libprg.h"
typedef struct no_arvore {
    int valor;
    struct no *esquerda;
    struct no *direita;
} no_arvore_t;

no_arvore_t *criar_no_arvore(int valor){
    no_arvore_t *no_arvore = (no_arvore_t *) malloc(sizeof(no_arvore_t));
    no_arvore->valor = valor;
    no_arvore->esquerda = no_arvore->direita = NULL;
    return no_arvore;
}

void destruir_no_arvore(no_arvore_t *no_arvore) {
    if (no_arvore != NULL) {
        destruir_no_arvore(no_arvore->esquerda);
        destruir_no_arvore(no_arvore->direita);
        free(no_arvore);
    }
}
no_arvore_t *inserir_valor(no_arvore_t *raiz, int valor){
    if (raiz == NULL) return criar_no_arvore(valor);
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}
bool busca(no_arvore_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}
no_arvore_t *remover_valor(no_arvore_t *raiz, int valor){
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor) {
        raiz->esquerda = remover_valor(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_valor(raiz->direita, valor);
    } else {
        // IF nó folha ou nó com um filho
        // ELSE nó com dois filhos
    }
    return raiz;
}