//
// Created by aluno on 09/09/2025.
//
#include "libprg/libprg.h"
#include <stdlib.h>
typedef struct fila {
    int* elementos;
    int tamanho;
    int inicio;
    int fim;
    int capacidade;
} fila_t;

    fila_t criar_fila(int capacidade) {

        fila_t* f = malloc(sizeof(fila_t));
        f->elementos = malloc(capacidade * sizeof(int));
        f->inicio = 0;
        f->fim = 0;
        f->elementos = 0;
        f->capacidade = 0;

    }
    void enfileirar(fila_t* fila, int valor) {
        fila->elementos[fila->fim] = valor;
        fila->fim ++;

    }

    // desenfileirar
    // inicio
    // fim
    // tamanho
    // destruir_fila


