#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {

        int n;
        scanf("%d", &n);

        double alunos[1001];
        double soma = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &alunos[j]);
            soma += alunos[j];
        }

        double media;
        media = (soma) / n;

        int acima = 0;
        for (int i = 0; i < n; i++)
        {
            if (alunos[i] > media)
            {
                acima++;
            }
        }

        double porcentagem;

        porcentagem = ((double)acima / n) * 100;

        printf("%.3lf\n", porcentagem);
    }

    return 0;
}
