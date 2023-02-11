#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *c, int i, int m, int f) {
  int z, iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

void sort(int *v, int *c, int i, int f)
{
    if (i >= f)
        return;

    int m = (i + f) / 2;

    sort(v, c, i, m);
    sort(v, c, m + 1, f);

    if (v[m] <= v[m + 1])
        return;

    merge(v, c, i, m, f);
}
void mergesort(int *v, int n)
{
    int *c = malloc(sizeof(int) * n);
    sort(v, c, 0, n - 1);
    free(c);
}



int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int *pares = (int *)malloc(n * sizeof(int));
    int *impares = (int *)malloc(n * sizeof(int));

    int qtdPares = 0, qtdImpares = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0)
        {
            pares[qtdPares] = num;
            qtdPares++;
        }
        else
        {
            impares[qtdImpares] = num;
            qtdImpares++;
        }
    }

    mergesort(pares, qtdPares);
    mergesort(impares, qtdImpares);

    for (int i = 0; i < qtdPares; i++)
    {
        printf("%d\n", pares[i]);
    }

    for (int j = qtdImpares - 1 ; j >= 0; j--)
    {
        printf("%d\n", impares[j]);
    }
    
    free(pares);
    free(impares);
    return 0;
}
