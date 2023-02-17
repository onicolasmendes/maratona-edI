#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tamnome 100000

typedef struct
{
    char nome[100000];
    int qtd;
    double percent;
} Arvores;

void calculaPercentual(Arvores *arvores, int *realCont, int n)
{
    printf("%d\n", n);
    for (int j = 0; j < *realCont; j++)
    {
        // printf("%d\n", arvores[j].qtd);
        double percent = ((double)arvores[j].qtd / n) * 100.;
        arvores[j].percent = percent;
        // printf("%d\n", arvores[j].qtd);
        printf("%.4lf\n", arvores[j].percent);
    }
}

void imprimeArvores(Arvores *arvores, int *realCont)
{
    printf("%d\n", *realCont);
    for (int i = 0; i < *realCont; i++)
    {
        printf("%s\n", arvores[i].nome);
    }
}

void incrementaContador(Arvores *arvores, char *nome, int *realcont)
{
    for (int i = 0; i < *realcont; i++)
    {
        if (strcmp(arvores[i].nome, nome) == 0)
        {
            arvores[i].qtd++;
            return;
        }
    }
    strcpy(arvores[*realcont].nome, nome);
    arvores[*realcont].qtd = 1;
    *realcont += 1;
    return;
}

void ordenaVetor(Arvores *arvores, int inicio, int final)
{
    int esquerda, direita, pivo;
    Arvores aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (strcmp(arvores[esquerda].nome, arvores[pivo].nome) < 0))
        {
            esquerda++;
        }

        while ((direita > inicio) && (strcmp(arvores[direita].nome, arvores[pivo].nome) > 0))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            // changePosition(rotas, esquerda, direita);
            aux = arvores[esquerda];
            arvores[esquerda] = arvores[direita];
            arvores[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if (direita > inicio)
    {
        ordenaVetor(arvores, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaVetor(arvores, esquerda, final);
    }
}

int main(int argc, char const *argv[])
{
    int n = 0, realcont = 0, qtdTeste;
    scanf("%d", &qtdTeste);
    getchar();
    getchar();

    for (int ctr = 0; ctr < qtdTeste; ctr++)
    {
        Arvores *arvores = malloc(1000000 * sizeof(Arvores));
        int qtdArvores = -1;
        char nome[tamnome];

        do
        {
            nome[0] = '\0';
            fgets(nome, tamnome, stdin);
            int tam = strlen(nome);

            if (nome[tam - 1] == '\n')
            {
                nome[tam - 1] = '\0';
            }

            qtdArvores++;
            strcpy(arvores[qtdArvores].nome, nome);

        } while (nome[0] != '\0');

        ordenaVetor(arvores, 0, qtdArvores-1);

        int rep;
        for (int i = 0; i < qtdArvores; i++)
        {
            rep = 1;
            int j;
            for (j = i + 1; j < qtdArvores && strcmp(arvores[i].nome, arvores[j].nome) == 0; j++)
            {
                rep++;
            }
            printf("%s %.4lf\n", arvores[i].nome, ((double) rep/qtdArvores) * 100.00);
            
            i = j -1;
            
        }

        if(ctr != qtdTeste - 1)
        {
            printf("\n");
        }

        free(arvores);
        
    }

    return 0;
}
