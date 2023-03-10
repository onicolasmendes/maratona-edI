#include <stdio.h>
#include <stdlib.h>

int Aux[1000];

int calculaFuro(int n, int c, int t1, int t2, int *f, int pos, int posicaoCom)
{
    int j, resp1, resp2;

    if (Aux[pos] > 0)
        return Aux[pos];

    if (f[pos] - f[posicaoCom] <= t1)
        resp1 = t1;
    else
    {
        j = n;
        while (j-- > 0)
            if (f[pos] - f[j] > t1)
                break;
        resp1 = calculaFuro(n, c, t1, t2, f, j, posicaoCom) + t1;
    }
    if (f[pos] - f[posicaoCom] <= t2)
        resp2 = t2;
    else
    {

        j = n;

        while (j-- > 0)
            if (f[pos] - f[j] > t2)
                break;
        resp2 = calculaFuro(n, c, t1, t2, f, j, posicaoCom) + t2;
    }

    if (resp1 < resp2)
    {
        Aux[pos] = resp1;
    }
    else
    {
        Aux[pos] = resp2;
    }
    return Aux[pos];
}

int main(int argc, char const *argv[])
{
    int i, j, n, c, t1, t2;
    while (scanf("%d %d %d %d\n", &n, &c, &t1, &t2) != EOF)
    {
        for (i = 0; i < 1000; i++)
        {
            Aux[i] = 0;
        }

        int *furos = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &furos[i]);
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    calculaFuro(n, c, t1, t2, furos, i, j);
                }
            }
        }
        printf("%d\n", Aux[n - 1]);
        free(furos);
    }
    return 0;
}
