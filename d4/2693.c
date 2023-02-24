#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 1000

typedef struct
{
    char nome[TAM];
    char regiao;
    int distancia;
} Aluno;

void ordenaDistancia(Aluno *vetor, int inicio, int final)
{
    int pivo, esquerda, direita;
    Aluno aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (vetor[esquerda].distancia < vetor[pivo].distancia))
        {
            esquerda++;
        }

        while ((direita > inicio) && (vetor[direita].distancia > vetor[pivo].distancia))
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
        ordenaDistancia(vetor, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaDistancia(vetor, esquerda, final);
    }
}

void ordenaRegiao(Aluno *vetor, int inicio, int final)
{
    int pivo, esquerda, direita;
    Aluno aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (vetor[esquerda].regiao < vetor[pivo].regiao))
        {
            esquerda++;
        }

        while ((direita > inicio) && (vetor[direita].regiao > vetor[pivo].regiao))
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
        ordenaRegiao(vetor, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaRegiao(vetor, esquerda, final);
    }
}

void ordenaNome(Aluno *vetor, int inicio, int final)
{
    int pivo, esquerda, direita;
    Aluno aux;
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
        ordenaNome(vetor, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaNome(vetor, esquerda, final);
    }
}

void ordena(Aluno *vetor, int n)
{

    ordenaDistancia(vetor, 0, n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        if (vetor[i].distancia == vetor[i + 1].distancia)
        {
            int novoFinal = i;
            while ((novoFinal < n) && (vetor[i].distancia == vetor[novoFinal].distancia))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaRegiao(vetor, i, novoFinal);
            i = novoFinal;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if ((vetor[i].distancia == vetor[i + 1].distancia) && (vetor[i].regiao == vetor[i + 1].regiao))
        {
            int novoFinal = i;
            while ((novoFinal < n) && (vetor[i].distancia == vetor[novoFinal].distancia) && (vetor[i].regiao == vetor[novoFinal].regiao))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaNome(vetor, i, novoFinal);
            i = novoFinal;
        }
    }
}

int main(int argc, char const *argv[])
{
    int q;
    while (scanf("%d", &q) != EOF)
    {
        Aluno *alunos = (Aluno *)malloc(q * sizeof(Aluno));
        for (int i = 0; i < q; i++)
        {
            scanf("%s %c %d", alunos[i].nome, &alunos[i].regiao, &alunos[i].distancia);
            // printf("%s %c %d\n", alunos[i].nome, alunos[i].regiao, alunos[i].distancia);
        }
        ordena(alunos, q);
        for (int j = 0; j < q; j++)
        {
            printf("%s\n", alunos[j].nome);
        }

        free(alunos);
    }
    return 0;
}
