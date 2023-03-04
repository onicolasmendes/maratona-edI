#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[102];
    int qtd;
}Carne;

void ordena(Carne *carnes, int inicio, int final)
{
    int pivo, esquerda, direita;
    pivo = inicio;
    esquerda = inicio;
    direita = final;
    Carne aux;

    while(esquerda <= direita){

        while((esquerda < final) && (carnes[esquerda].qtd < carnes[pivo].qtd))
        {
            esquerda++;
        }

        while((direita > inicio) && (carnes[direita].qtd > carnes[pivo].qtd))
        {
            direita--;
        }

        if(esquerda <= direita)
        {
            aux = carnes[esquerda];
            carnes[esquerda] = carnes[direita];
            carnes[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if(direita > inicio)
    {
        ordena(carnes, inicio, direita);
    }

    if(esquerda < final)
    {
        ordena(carnes, esquerda, final);
    }
}


int main(int argc, char const *argv[])
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        Carne *carnes = (Carne*) malloc(n * sizeof(Carne));
        for (int i = 0; i < n; i++)
        {
            scanf("%s %d", carnes[i].nome, &carnes[i].qtd);
        }
        ordena(carnes, 0, n -1);
        for (int i = 0; i < n; i++)
        {
            printf("%s", carnes[i].nome);

            if(i != n - 1)
            {
                printf(" ");
            }
        }

        printf("\n");
        free(carnes);
    }
    return 0;
}
