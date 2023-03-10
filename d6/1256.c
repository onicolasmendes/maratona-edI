#include <stdio.h>
#include <stdlib.h>
#define tamvetor 200;

int geraChave(int n, int tam)
{
    return (n % tam);
}

typedef struct{
    int item;
    int pos;
}Item;

void ordena(Item *v, int inicio, int final){
    int pivo, esquerda, direita;
    Item aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while(esquerda <= direita)
    {
        while((esquerda < final) && ((v[esquerda].pos < v[pivo].pos) || ((v[esquerda].pos == v[pivo].pos) && (v[esquerda].item)<v[pivo].item)))
        {
            esquerda++;
        }
        while((direita > inicio) && ((v[direita].pos > v[pivo].pos) || ((v[direita].pos == v[pivo].pos) && (v[direita].item > v[pivo].item))))
        {
            direita--;
        }
        if(esquerda <= direita)
        {
            aux = v[esquerda];
            v[esquerda] = v[direita];
            v[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if(direita>inicio)
    {
        ordena(v, inicio, direita);
    }

    if(esquerda < final)
    {
        ordena(v, esquerda, final);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int controlPrint = 0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        
        if(controlPrint > 0)
        {
            printf("\n");
        }
        int m, c;
        scanf("%d %d\n", &m, &c);
        // *chaves = (int *)malloc(m * sizeof(int));
        Item *aux = (Item *)malloc(c * sizeof(Item));
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &aux[j].item);
            aux[j].pos = aux[j].item % m;
            //printf("%d %d\n", aux[j].item, aux[j].pos);

        }
        getchar();
        ordena(aux, 0, c-1);
        int y = 0;
        while (y < m)
        {
        printf("%d ->", y);
        for (int i = 0; i < c; i++)
        {
            if(y == aux[i].pos)
            {
                printf(" %d ->", aux[i].item);
            }
        }
        printf(" \\");
        printf("\n");
        y++;
        }
       // free(chaves);
        free(aux);
        controlPrint++;
        

    }

    return 0;
}
