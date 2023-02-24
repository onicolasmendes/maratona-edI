#include <stdio.h>
void ordena(int *vetor, int n, int *cont)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if(vetor[j] < vetor[j-1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j-1] = aux;
                *cont = *cont + 1;
            }
        }
        
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, s = 0;
        int vetor[1000];
        scanf("%d", &l);
        for (int j = 0; j < l; j++)
        {
            scanf("%d", &vetor[j]);
        }
        ordena(vetor, l, &s);
        printf("Optimal train swapping takes %d swaps.\n", s);
    }
    
    return 0;
}
