#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char permuta[12];
} Permuta;

void trocaChar(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void permuta(char *str, int left, int right, Permuta *perms, int *count)
{
    if (left == right)
    {
        strcpy(perms[*count].permuta, str);
        (*count)++;
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            trocaChar(str + left, str + i);
            permuta(str, left + 1, right, perms, count);
            trocaChar(str + left, str + i);
        }
    }
}

int fat(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * fat(n - 1);
    }
}

void imprime(Permuta *vetor, int tam)
{
    Permuta anterior;
    anterior = vetor[0];

    for (int i = 0; i < tam; i++)
    {
        if (strcmp(vetor[i].permuta, anterior.permuta) == 0)
        {
            continue;
        }
        else
        {
            printf("%s\n", anterior.permuta);
            anterior = vetor[i];
        }
    }

    printf("%s\n\n", anterior.permuta); // Imprime o último elemento do vetor
}

void shell_sort_strings(Permuta *strings, int tamanho)
{
    int intervalo, i, j;
    Permuta temp;
    for (intervalo = tamanho / 2; intervalo > 0; intervalo /= 2)
    {
        for (i = intervalo; i < tamanho; i++)
        {
            temp = strings[i];
            for (j = i; j >= intervalo && strcmp(strings[j - intervalo].permuta, temp.permuta) > 0; j -= intervalo)
            {
                strings[j] = strings[j - intervalo];
            }
            strings[j] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char palavra[12];
        scanf("%s", palavra);
        int tam = strlen(palavra);
        int tam2 = tam;
        tam = fat(tam);
        Permuta *permutacoes = malloc(tam * sizeof(Permuta));

        int pos = 0;
        permuta(palavra, 0, tam2 - 1, permutacoes, &pos);
        shell_sort_strings(permutacoes, pos);
        imprime(permutacoes, pos);
        free(permutacoes);
        pos = 0;
    }

    return 0;
}
