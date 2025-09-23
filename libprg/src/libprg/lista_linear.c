//
// Created by aluno on 16/09/2025.
//
#include "libprg/libprg.h"

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

lista_linear_t* criar(int capacidade) {
    lista_linear_t* lista = (lista_linear_t*)malloc(sizeof(lista_linear_t));
    lista->elementos = (int*)malloc(capacidade * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

void inserir(lista_linear_t* lista, int valor) {
    if (!cheia(lista)) {
        lista->elementos[lista->tamanho] = valor;
        lista->tamanho++;
    } else {
        printf("Lista cheia, não foi possível inserir %d\n", valor);
    }
}

int buscar(lista_linear_t* lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            return i; // retorna a posição
        }
    }
    return -1; // não encontrado
}

void remover(lista_linear_t* lista, int valor) {
    int indice = buscar(lista, valor);
    if (indice != -1) {
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
        lista->tamanho--;
    } else {
        printf("Valor %d não encontrado, não removido\n", valor);
    }
}

int vazia(lista_linear_t* lista) {
    return lista->tamanho == 0;
}

int cheia(lista_linear_t* lista) {
    return lista->tamanho == lista->capacidade;
}

void destruir(lista_linear_t* lista) {
    free(lista->elementos);
    free(lista);
}
