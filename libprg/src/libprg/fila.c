//
// Created by aluno on 09/09/2025.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct fila {
    int inicio;
    int* elementos;
    int tamanho;
    int capacidade;
    int fim;
} fila_t;


fila_t* criar_fila(int capacidade) {
    fila_t* f = malloc(sizeof(fila_t));
    if (!f) {
        exit(EXIT_FAILURE);
    }

    f->elementos = malloc(capacidade * sizeof(int));
    if (!f->elementos) {
        free(f);
        exit(EXIT_FAILURE);
    }

    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}


bool fila_cheia(fila_t* fila) {
    return fila->tamanho == fila->capacidade;
}


bool vazia(fila_t* fila) {
    return fila->tamanho == 0;
}

int tamanho_fila(fila_t* fila) {
    if (fila == NULL)
        return 0;
    return fila->tamanho;
}


void enfileirar(fila_t* fila, int valor) {
    if (fila_cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int desenfileirar(fila_t* fila) {
    if (vazia(fila)) {
        printf("Fila vazia! Não é possível desinfileirar.\n");
        exit(EXIT_FAILURE);
    }

    int valor = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}


void destruir_fila(fila_t* fila) {
    free(fila->elementos);
    free(fila);
}


void exibir(fila_t* fila) {
    printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int indeci = (fila->inicio + i) % fila->capacidade;
        printf("%d ", fila->elementos[indeci]);
    }
}


