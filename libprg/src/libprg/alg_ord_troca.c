//
// Created by aluno on 25/11/2025.
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

void insertion_sort(int vetor[], int tamanho) {
        for (int i = 1; i < tamanho; i++) {
            int chave = vetor[i];
            int j = i - 1;

    while (j >= 0 && vetor[j] > chave) {
        vetor[j + 1] = vetor[j];
        j--;
    }

    vetor[j + 1] = chave;
        }
}

void selection_sort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }
        if (indice_minimo != i) {
            int aux = vetor[i];
            vetor[i] = vetor[indice_minimo];
            vetor[indice_minimo] = aux;
        }
    }
}

void merge(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[n1];
    int direita[n2];

    for (int i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];

    for (int j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}
