#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
} TItem;

typedef struct celula
{
    TItem item;
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula *cabeca;
} TPilha;

int PilhaInicia(TPilha *pilha)
{
    pilha->cabeca = (TCelula *)malloc(sizeof(TCelula));
    if (pilha->cabeca == NULL)
        return 0;
    pilha->cabeca->prox = NULL;
    return 1;
}

int PilhaEhVazia(TPilha *pilha)
{
    if (pilha->cabeca->prox == NULL)
    {
        return 1;
    }
    return 0;
}

int PilhaPush(TPilha *pilha, TItem item)
{
    TCelula *newCelula = (TCelula *)malloc(sizeof(TCelula));
    if (newCelula == NULL)
    {
        return 0;
    }
    newCelula->item = item;
    newCelula->prox = pilha->cabeca->prox;
    pilha->cabeca->prox = newCelula;
    return 1;
}

int PilhaPop(TPilha *pilha, TItem *item)
{
    if (PilhaEhVazia(pilha))
        return 0;
    TCelula *aux;
    aux = pilha->cabeca->prox;
    *item = aux->item;
    pilha->cabeca->prox = aux->prox;
    free(aux);
    return 1;
}

int CaptaMenorValor(TPilha *pilha)
{
    int menorValor = 1000000000;
    TCelula *aux;
    aux = pilha->cabeca->prox;
    while (aux != NULL)
    {
        if (aux->item.num < menorValor)
        {
            menorValor = aux->item.num;
        }
        aux = aux->prox;
    }

    return menorValor;
}

void PilhaLibera(TPilha *pilha)
{
    TCelula *aux, *aux2;
    aux = pilha->cabeca;

    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
}

int main(int argc, char const *argv[])
{
    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);
    TItem item;
    TPilha pilha;
    PilhaInicia(&pilha);

    for (int i = 0; i < qtdOperacoes; i++)
    {
        char comando[10];
        int v;
        scanf("%s", comando);

        if(strcmp(comando, "PUSH")==0)
        {
            scanf("%d", &v);
        }

        if (strcmp(comando, "PUSH") == 0)
        {
            item.num = v;
            PilhaPush(&pilha, item);
        }
        else if (strcmp(comando, "MIN") == 0)
        {
            if (PilhaEhVazia(&pilha))
            {
                printf("EMPTY\n");
            }
            else
            {
                int menor;
                menor = CaptaMenorValor(&pilha);
                printf("%d\n", menor);
            }
        }
        else if (strcmp(comando, "POP") == 0)
        {
            if (PilhaEhVazia(&pilha))
            {
                printf("EMPTY\n");
            }
            else
            {
                PilhaPop(&pilha, &item);
            }
        }
    }
    PilhaLibera(&pilha);

    return 0;
}
