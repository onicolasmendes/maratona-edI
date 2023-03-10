#include <stdio.h>

long double fat(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * fat(n-1);
    }
}

int main(int argc, char const *argv[])
{
    int m, n;
    while(scanf("%d %d\n", &m, &n) != EOF)
    {
        long double a = fat(m);
        long double b = fat(n);
        //printf("%lf %lf\n", a, b);
        long double soma = a + b;
        printf("%.0Lf\n", soma);
    }
    return 0;
}
