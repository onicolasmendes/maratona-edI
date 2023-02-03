#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int carta;
} TItem;

typedef struct celula
{
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula *cabeca, *cauda;
} TPilha;

int PilhaInicia(TPilha *pilha)
{
    pilha->cabeca = (TCelula *)malloc(sizeof(TCelula));
    if (pilha->cabeca == NULL)
    {
        return 0;
    }
    pilha->cabeca->prox = NULL;
    pilha->cauda = pilha->cabeca;
    return 1;
}

int PilhaPushFinal(TPilha *pilha, TItem item)
{
    TCelula *new = (TCelula *)malloc(sizeof(TCelula));
    if (new == NULL)
    {
        return 0;
    }
    new->item = item;
    pilha->cauda->prox = new;
    pilha->cauda = new;
    new->prox = NULL;
    return 1;
}

int CaptaNumeroDeElementosNaPilha(TPilha *pilha)
{
    int numElementos = 0;
    TCelula *aux;
    aux = pilha->cabeca->prox;
    while (aux != NULL)
    {
        numElementos++;
        aux = aux->prox;
    }
    return numElementos;
}
void PilhaTiraTopoEMandaProFinal(TPilha *pilha, int *cartaDescartado)
{
    TCelula *aux1;
    aux1 = pilha->cabeca->prox;
    pilha->cabeca->prox = aux1->prox;
    *cartaDescartado = aux1->item.carta;
    free(aux1);
    TCelula *aux;
    aux = pilha->cabeca->prox;
    pilha->cabeca->prox = aux->prox;
    PilhaPushFinal(pilha, aux->item);
    free(aux);
}

void PilhaLibera(TPilha *pilha)
{
    free(pilha->cabeca->prox);
    free(pilha->cabeca);
    free(pilha->cauda);
}

int main(int argc, char const *argv[])
{
    int qtdCartas;
    scanf("%d", &qtdCartas);
    while (qtdCartas != 0)
    {
        TPilha pilha;
        PilhaInicia(&pilha);

        for (int i = 1; i <= qtdCartas; i++)
        {
            TItem item;
            item.carta = i;
            PilhaPushFinal(&pilha, item);
        }
        int cartasDescartadas[qtdCartas];
        int j = 0;
        while (CaptaNumeroDeElementosNaPilha(&pilha) >= 2)
        {
            int cartaRetirada;
            PilhaTiraTopoEMandaProFinal(&pilha, &cartaRetirada);
            cartasDescartadas[j] = cartaRetirada;
            j++;
        }
        printf("Discarded cards: %d", cartasDescartadas[0]);
        for (int n = 1; n < j; n++)
        {
            printf(", %d", cartasDescartadas[n]);
        }
        printf("\n");

        printf("Remaining card: %d\n", pilha.cauda->item.carta);

        PilhaLibera(&pilha);
        scanf("%d", &qtdCartas);
    }
    return 0;
}
