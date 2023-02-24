#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000

typedef struct
{
    char nome[TAM];
    char op[3];
    int impressa;
} Pessoas;

int verifica(Pessoas *pessoas, int n, char *nome)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nome, pessoas[i].nome) == 0)
        {
            return 0;
        }
    }

    return 1;
}
void ordena(Pessoas *vetor, int inicio, int final)
{
    int pivo, esquerda, direita;
    Pessoas aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (strcmp(vetor[esquerda].nome, vetor[pivo].nome) < 0))
        {
            esquerda++;
        }

        while ((direita > inicio) && (strcmp(vetor[direita].nome, vetor[pivo].nome) > 0))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if (direita > inicio)
    {
        ordena(vetor, inicio, direita);
    }

    if (esquerda < final)
    {
        ordena(vetor, esquerda, final);
    }
}

int main(int argc, char const *argv[])
{
    int pos = 0, posWinner = 0;
    char winner[TAM] = ")";
    char nomeTemp[TAM];
    Pessoas *pessoas = (Pessoas *)malloc(99999 * sizeof(Pessoas));

    while (scanf("%s", nomeTemp) != EOF && (strcmp(nomeTemp, "FIM") != 0))
    {
        if (verifica(pessoas, pos, nomeTemp))
        {
            strcpy(pessoas[pos].nome, nomeTemp);
            scanf("%s", pessoas[pos].op);
            pessoas[pos].impressa = 1;
            // printf("%s %s\n", pessoas[pos].nome, pessoas[pos].op);
            int tamWinner = (int)strlen(winner);
            int tamNome = (int)strlen(pessoas[pos].nome);
            if (((tamNome > tamWinner) && (strcmp(pessoas[pos].op, "YES") == 0)) || ((tamNome == tamWinner) && (pos < posWinner) && (strcmp(pessoas[pos].op, "YES") == 0)))
            {
                strcpy(winner, pessoas[pos].nome);
                posWinner = pos;
            }
            pos++;
        }
        else
        {
            char lixo[4];
            scanf("%s", lixo);
        }
    }
    ordena(pessoas, 0, pos - 1);

     for(int i = 0; i < pos; i++)
     {
         if(strcmp(pessoas[i].op, "YES") == 0 )
         {
             printf("%s\n", pessoas[i].nome);

         }
     }

    for(int i = 0; i < pos; i++)
    {
        if(strcmp(pessoas[i].op, "YES") != 0)
        {
            printf("%s\n", pessoas[i].nome);

        }
    }

    printf("\nAmigo do Habay:\n%s\n", winner);
    free(pessoas);

    return 0;
}
