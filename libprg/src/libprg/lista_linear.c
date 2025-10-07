//
// Created by aluno on 16/09/2025.
//
#include "libprg/libprg.h"

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

// Função para criar a lista
lista_linear_t* criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t* lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
    return lista;
}


void inserir(lista_linear_t* lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}


bool lista_cheia(lista_linear_t* lista) {
    return lista->tamanho == lista->capacidade;
}


bool lista_vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

int buscar(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; ++i) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1; // se não encontrar o valor
}

// Função para remover um valor da lista (do início, típico de uma fila)
void remover(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        exit(EXIT_FAILURE);
        return;
    }
    // // Desloca os elementos pra esquerda
    // for (int i = 0; i < lista->tamanho - 1; ++i) {
    //     lista->elementos[i] = lista->elementos[i + 1];
    // }
    lista->tamanho--;  // Diminui o tamanho da lista
}


void destruir_lista(lista_linear_t* lista) {
    free(lista->elementos);  // Libera a memória dos elementos
    free(lista);  // Libera a memória da estrutura
}


void exibir_lista(lista_linear_t* lista) {

    for (int i = 0; i < lista->tamanho; i++) {
        lista->elementos[i];
    }
}


int primeiro(lista_linear_t* lista) {
    if (lista_vazia(lista)) {
        exit(EXIT_FAILURE);
        return -1;
    }
    return lista->elementos[0];
}