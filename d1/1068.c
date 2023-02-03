#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    char linha[10002];

    while (scanf("%s", linha) != EOF)
    {
        int nParentesesAbre = 0;
        int nParentesesFecha = 0;
        int tamanho = strlen(linha);
        for (int i = 0; i < tamanho; i++)
        {
            if (linha[i] == '(')
            {
                nParentesesAbre++;
            }
            else if (linha[i] == ')')
            {
                nParentesesFecha++;
            }

            if (nParentesesFecha > nParentesesAbre)
            {
                break;
            }
        }

        if (nParentesesFecha != nParentesesAbre)
        {
            printf("incorrect\n");
        }
        else
        {
            printf("correct\n");
        }
    }
    return 0;
}
