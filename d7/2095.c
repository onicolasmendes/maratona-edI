#include <stdio.h>
#include <stdlib.h>

int recursive_binary_search(long vector[], int s, long item)
{
    int tam, meio, find;
    tam = s - 1; find = 0;
    int f = 0;
    while(f <= tam)
    {
        meio = (f + tam) / 2;
        if(item <= vector[meio])
        {
            tam = meio - 1;
        }else

        {
            find = 1;
            break;
            break;
        };
    }
    if (find)
    {
        return 1;
    }else
    {
        return -1;
    }
}

void swap(long *a, long *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(long array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(long array[], int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int s;
    scanf("%d\n", &s);
    long *quadradonia = (long *)malloc(s * sizeof(long));
    long *noglonia = (long *) malloc(s * sizeof(long));

    for (int i = 0; i < s; i++)
    {
        scanf("%ld", &quadradonia[i]);
    }

    for (int i = 0; i < s; i++)
    {
        scanf("%ld", &noglonia[i]);
    }

    quickSort(quadradonia, 0, s - 1);
    quickSort(noglonia, 0, s -1);

    int maxVitorias = 0;
    int control = 0;

    
 
    for (int i = 0; i < s; i++)
    {
        control = recursive_binary_search(quadradonia, s, noglonia[i]);
        if(control  == 1)
        {
            maxVitorias++;
        }
    }

    printf("%d\n", maxVitorias);
    free(noglonia);
    free(quadradonia);
    
    return 0;
}
