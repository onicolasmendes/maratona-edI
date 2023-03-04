#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t, trocas = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, trocas = 0;
        int vet[100000], pos[100000];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            vet[i] = temp - 1;
            pos[temp - 1] = i;

        }
        for (int i = 0; i < n; i++)
        {
            if(vet[i] != i)
            {
                vet[pos[i]] = vet[i];
                pos[vet[i]] = pos[i];
                vet[i] = i;
                pos[i] = i;
                trocas++;
            }
        }
        
        printf("%d\n", trocas);
        trocas = 0;
        
    }
    
    return 0;
}
