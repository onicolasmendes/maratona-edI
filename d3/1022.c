#include <stdio.h>

void simplifica(int *n, int *d)
{
    int menor;
    if (*n < *d)
    {
        menor = *d;
    }
    else
    {
        menor = *n;
    }
    int control = 0;

    for (int i = menor; i >= 1 && control == 0; i--)
    {
        if (*n % i == 0 && *d % i == 0)
        {
            *n = *n / i;
            *d = *d / i;
            control = 1;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int n1, d1, n2, d2;
        char b1, b2, op;
        scanf("%d %c %d %c %d %c %d", &n1, &b1, &d1, &op, &n2, &b2, &d2);
        int n3, d3;
        switch (op)
        {
        case '+':
            if (d1 == d2)
            {
                d3 = d1;
                n3 = n1 + n2;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            else
            {
                d3 = d1 * d2;
                n3 = (d3 / d1 * n1) + (d3 / d2 * n2);
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            break;
        case '-':
            if (d1 == d2)
            {
                d3 = d1;
                n3 = n1 - n2;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            else
            {
                d3 = d1 * d2;
                n3 = (d3 / d1 * n1) - (d3 / d2 * n2);
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            break;
        case '*':
            if (n1 == n2 && d1 == d2)
            {
                n3 = n1;
                d3 = d1;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            else
            {
                d3 = d1 * d2;
                n3 = n1 * n2;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            break;
        case '/':
            if (n1 == n2 && d1 == d2)
            {
                n3 = n1;
                d3 = d1;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            else
            {
                d3 = d1 * n2;
                n3 = n1 * d2;
                printf("%d/%d = ", n3, d3);
                simplifica(&n3, &d3);
                printf("%d/%d\n", n3, d3);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
