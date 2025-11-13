//
// Created by aluno on 06/11/2025.
//
#include "libprg/libprg.h"

void bubble_sort(int vetor[], int tamanho) {
    int aux, troca;

    for (int i = 0; i < tamanho - 1; i++) {
        troca = 0;
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                troca = 1;
            }
        }
        if (!troca)break;
    }
}