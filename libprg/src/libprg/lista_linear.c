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
    if (lista_cheia(lista)) {
        lista->elementos = realloc(lista->elementos, sizeof(int) * lista->capacidade *2);
    }
    if (lista->ordenada) inserir_ordenada(lista, valor);
    else inserir_nao_ordenada(lista, valor);
}

void inserir_nao_ordenada(lista_linear_t *lista, int valor) {
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inserir_ordenada(lista_linear_t *lista, int valor) {
    for (int i = lista->tamanho - 1; i > 0; --i) {
        if (lista->elementos[i] < valor) {
            lista->elementos[i+ 1] = valor;
            break;
        }
        lista->elementos[i] = lista->elementos[i - 1];
    }
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
void remover_linear(lista_linear_t* lista, int valor) {
    int indice = buscar(lista, valor);
    if (indice > -1) {
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
    }
}

int limitar_posicao(lista_linear_t *lista, int posicao) {
    if (posicao > lista->tamanho) return lista->tamanho;
    if (posicao < 0) return 0;
}

    void remover_da_posicao(lista_linear_t* lista, int posicao){
    int indice = limitar_posicao(lista, posicao);

        int valor = lista->elementos[indice];
        remover_linear(lista, valor);
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

int busca_na_posicao(lista_linear_t* lista, int posicao) {
    return lista->elementos[posicao];
}

int inserir_na_posicao(lista_linear_t* lista,int valor, int posicao) {
    int indice = busca_na_posicao(lista, posicao);

    inserir(lista, lista->elementos[indice]);
    lista->elementos[indice] = valor;
}