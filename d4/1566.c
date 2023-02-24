#include <stdio.h>
#include <stdlib.h>

void ordena(int *vetor, int inicio, int final)
{
    int esquerda, direita, pivo;
    int aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while((esquerda < final) && (vetor[esquerda] < vetor[pivo]))
        {
            esquerda++;
        }

        while((direita > inicio) && (vetor[direita] > vetor[pivo]))
        {
            direita--;
        }

        if(esquerda <= direita)
        {
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if(direita > inicio)
    {
        ordena(vetor, inicio, direita);
    }

    if(esquerda < final)
    {
        ordena(vetor, esquerda, final);
    }
    
}
int main(int argc, char const *argv[])
{
    int nc;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++)
    {
        int n;
        scanf("%d", &n);
        int *vetor = (int*) malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &vetor[j]);
        }
        ordena(vetor, 0, n - 1);
        for (int  k = 0; k  < n; k++)
        {
            printf("%d ", vetor[k]);
            if(k != n - 1)
            {
                printf(" ");
            }
        }

        printf("\n");
        free(vetor);
    }
    
    return 0;
}
