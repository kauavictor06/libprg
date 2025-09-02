//
// Created by aluno on 02/09/2025.
#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
    int * elementos;
int topo;
int capacidade;
    } pilha_t;

pilha_t* criar_pilha(int capacidade)  {

    pilha_t* p = malloc(sizeof(pilha_t));

    p->elementos = malloc(capacidade * sizeof(int));

    p->topo = -1;
    p->capacidade = capacidade;

    return p;
}
