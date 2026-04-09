#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Ant = NULL;
    Lista->Primeiro->Prox = NULL;
    /* IMPLEMENTAR */
}

int Vazia(TipoLista Lista) {
     return (Lista.Primeiro == Lista.Ultimo);
    /* IMPLEMENTAR */
}

void Insere(TipoItem x, TipoLista *Lista) {
    TipoApontador novo = (TipoApontador) malloc(sizeof(TipoCelula));

    novo->Item = x;
    novo->Prox = NULL;
    novo->Ant = Lista->Ultimo;

    Lista->Ultimo->Prox = novo;
    Lista->Ultimo = novo;
    /* IMPLEMENTAR */
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    if (p == NULL || Vazia(*Lista)) return;

    *Item = p->Item;

    if (p->Prox != NULL)
        p->Prox->Ant = p->Ant;
    else
        Lista->Ultimo = p->Ant;

    p->Ant->Prox = p->Prox;

    free(p);
    /* IMPLEMENTAR */
}

void Imprime(TipoLista Lista) {
    TipoApontador p = Lista.Primeiro->Prox;

    while (p != NULL) {
        printf("%d ", p->Item.Chave);
        p = p->Prox;
    }
    printf("\n");

    /* IMPLEMENTAR */
}

void Inverte(TipoLista *Lista) {
    if (Vazia(*Lista)) return;

    TipoApontador atual = Lista->Primeiro->Prox;
    TipoApontador temp = NULL;

    // Troca Prox e Ant de cada nó
    while (atual != NULL) {
        temp = atual->Prox;
        atual->Prox = atual->Ant;
        atual->Ant = temp;
        atual = temp;
    /* IMPLEMENTAR */
}

