//
// Created by aluno on 18/11/2025.
//
#include <stdlib.h>
#include <stdbool.h>

#include "libprg/libprg.h"
typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
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
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }
            if (raiz->esquerda == NULL) {
                no_arvore_t *temp = raiz->direita;
                free(raiz);
                return temp;
            }
            if (raiz->direita == NULL) {
                no_arvore_t *temp = raiz->esquerda;
                free(raiz);
                return temp;
            }
            no_arvore_t *temp = raiz->esquerda;
            while (temp->direita != NULL)
                temp = temp->direita;

            raiz->valor = temp->valor;
            raiz->esquerda = remover_valor(raiz->esquerda, temp->valor);
        }
    return raiz;
}
// void em_ordem(no_arvore_t *raiz) {
//     if (raiz == NULL) return;
//     em_ordem(raiz->esquerda);
//     printf("%d ", raiz->valor);
//     em_ordem(raiz->direita);
// }


    typedef struct no_avl {
        int valor;
        int altura;
        struct no_avl *esquerda;
        struct no_avl *direita;
    } no_avl_t;

    no_avl_t *criar_no_avl(int valor){
        no_avl_t *no = malloc(sizeof(no_avl_t));
        no->valor = valor;
        no->altura = 1;
        no->esquerda = no->direita = NULL;
        return no;
    }

    int altura(no_avl_t *v){
        return v ? v->altura : 0;
    }

    int fator_balanceamento(no_avl_t *v){
        return altura(v->esquerda) - altura(v->direita);
    }

    #define max(a,b) ((a)>(b)?(a):(b))

    no_avl_t *rotacao_direita(no_avl_t *v){
        no_avl_t *u = v->esquerda;
        v->esquerda = u->direita;
        u->direita = v;

        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        u->altura = 1 + max(altura(u->esquerda), altura(u->direita));

        return u;
    }

    no_avl_t *rotacao_esquerda(no_avl_t *v){
        no_avl_t *u = v->direita;
        v->direita = u->esquerda;
        u->esquerda = v;

        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        u->altura = 1 + max(altura(u->esquerda), altura(u->direita));

        return u;
    }

    no_avl_t *rotacao_dupla_direita(no_avl_t *v){
        v->esquerda = rotacao_esquerda(v->esquerda);
        return rotacao_direita(v);
    }

    no_avl_t *rotacao_dupla_esquerda(no_avl_t *v){
        v->direita = rotacao_direita(v->direita);
        return rotacao_esquerda(v);
    }

    no_avl_t *balancear(no_avl_t *v){
        int fb = fator_balanceamento(v);

        if (fb > 1){
            if (fator_balanceamento(v->esquerda) >= 0)
                return rotacao_direita(v);
            else
                return rotacao_dupla_direita(v);
        }
        else if (fb < -1){
            if (fator_balanceamento(v->direita) <= 0)
                return rotacao_esquerda(v);
            else
                return rotacao_dupla_esquerda(v);
        }
        return v;
    }

    no_avl_t *inserir_avl(no_avl_t *v, int valor){
        if (v == NULL)
            return criar_no_avl(valor);

        if (valor < v->valor)
            v->esquerda = inserir_avl(v->esquerda, valor);
        else if (valor > v->valor)
            v->direita = inserir_avl(v->direita, valor);
        else
            return v;

        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        return balancear(v);
    }

    no_avl_t *remover(no_avl_t *v, int valor){
        if (v == NULL) return NULL;

        if (valor < v->valor)
            v->esquerda = remover(v->esquerda, valor);
        else if (valor > v->valor)
            v->direita = remover(v->direita, valor);
        else {

            // 0 ou 1 filho
            if (v->esquerda == NULL || v->direita == NULL){
                no_avl_t *temp = v->esquerda ? v->esquerda : v->direita;

                if (temp == NULL){
                    temp = v;
                    v = NULL;
                } else {
                    *v = *temp;
                }
                free(temp);
            }
            // 2 filhos
            else {
                no_avl_t *aux = v->esquerda;
                while (aux->direita != NULL)
                    aux = aux->direita;

                v->valor = aux->valor;
                v->esquerda = remover(v->esquerda, aux->valor);
            }
        }

        if (v == NULL) return NULL;

        v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
        return balancear(v);
    }
// void em_ordem_avl(no_avl_t *raiz) {
//         if (raiz == NULL) return;
//         em_ordem_avl(raiz->esquerda);
//         printf("%d ", raiz->valor);
//         em_ordem_avl(raiz->direita);
//     }