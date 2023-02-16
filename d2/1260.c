#include <stdio.h>
#include <string.h>


typedef struct{
    char nome[100000];
    int qtd;
    float percent;
}Arvores;

imprimeArvores();
ConsultaNomeNoVetor();



int main(int argc, char const *argv[])
{
    int n, cont = 0;
    scanf("%d", &n);
    getchar();

    Arvores *arvores = malloc(100000 * sizeof(Arvores));

    while(fgets(nome, 100000, stdin) != NULL)
    {
        int tam = strlen(nome);
        nome[tam-1] = '\0';

        if(strcmp(nome, "\n") == 0)
        {
          imprimeArvores();
          free(arvores);
          Arvores *arvores = malloc(100000 * sizeof(Arvores));
          cont = 0;
          continue;  
        }






    }

    //para o ultimo caso

    return 0;
}
