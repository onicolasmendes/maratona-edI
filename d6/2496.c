#include <stdio.h>
#include <stdlib.h>

int selectionSort(char *arr, int n)
    {
        int i, j, min_idx, trocas = 0;

        for (i = 0; i < n - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            if (min_idx != i)
            {
                int temp = arr[i];
                arr[i] = arr[min_idx];
                arr[min_idx] = temp;
                trocas++;
            }
        }

        if(trocas == 1)
        {
            return 1;
        }

        return 0;

    }

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        int m;
        scanf("%d\n", &m);
        char *seq = (char *) malloc( m * sizeof(char));
        scanf("%s\n", seq);
        if(selectionSort(seq, m))
        {
            printf("There are the chance.\n");
        }else
        {
            printf("There aren't the chance.\n");
        }
        free(seq);
    }
    
    return 0;
}
