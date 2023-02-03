#include <stdio.h>
#include <string.h>

typedef struct{
    char pais[30];
    int idioma;
}Pais;

int main(int argc, char const *argv[])
{
   
    Pais paises[24];

    strcpy(paises[0].pais, "brasil"); paises[0].idioma = 1;
    strcpy(paises[1].pais, "alemanha"); paises[1].idioma = 2;
    strcpy(paises[2].pais, "austria"); paises[2].idioma = 3;
    strcpy(paises[3].pais, "coreia"); paises[3].idioma = 4;
    strcpy(paises[4].pais, "espanha"); paises[4].idioma = 5;
    strcpy(paises[5].pais, "grecia"); paises[5].idioma = 6;
    strcpy(paises[6].pais, "estados-unidos"); paises[6].idioma = 7;
    strcpy(paises[7].pais, "inglaterra"); paises[7].idioma = 7;
    strcpy(paises[8].pais, "australia"); paises[8].idioma = 7;
    strcpy(paises[9].pais, "portugal"); paises[9].idioma = 1;
    strcpy(paises[10].pais, "suecia"); paises[10].idioma = 8;
    strcpy(paises[11].pais, "turquia"); paises[11].idioma = 9;
    strcpy(paises[12].pais, "argentina"); paises[12].idioma = 5;
    strcpy(paises[13].pais, "chile"); paises[13].idioma = 5;
    strcpy(paises[14].pais, "mexico"); paises[14].idioma = 5;
    strcpy(paises[15].pais, "antardida"); paises[15].idioma = 7;
    strcpy(paises[16].pais, "canada"); paises[16].idioma = 7;
    strcpy(paises[17].pais, "irlanda"); paises[17].idioma = 10;
    strcpy(paises[18].pais, "belgica"); paises[18].idioma = 11;
    strcpy(paises[19].pais, "italia"); paises[19].idioma = 12;
    strcpy(paises[20].pais, "libia"); paises[20].idioma = 12;
    strcpy(paises[21].pais, "siria"); paises[21].idioma = 13;
    strcpy(paises[22].pais, "marrocos"); paises[22].idioma = 13;
    strcpy(paises[23].pais, "japao"); paises[23].idioma = 14;
    
   

    char input[10000];
 
    while(scanf("%s", input) != EOF)
    {
        int paisesNaoIguais = 0;
        for (int i = 0; i < 24; i++)
        {
            if(strcmp(input, paises[i].pais) == 0)
            {
                if(paises[i].idioma == 1)
                {
                    printf("Feliz Natal!\n");
                }else if(paises[i].idioma == 2)
                {
                    printf("Frohliche Weihnachten!\n");
                }
                else if(paises[i].idioma == 3)
                {
                    printf("Frohe Weihnacht!\n");
                }else if(paises[i].idioma == 4)
                {
                    printf("Chuk Sung Tan!\n");
                }else if(paises[i].idioma == 5)
                {
                    printf("Feliz Navidad!\n");
                }else if(paises[i].idioma == 6)
                {
                    printf("Kala Christougena!\n");
                }else if(paises[i].idioma == 7)
                {
                    printf("Merry Christmas!\n");
                }
                else if(paises[i].idioma == 8)
                {
                    printf("God Jul!\n");
                }
                else if(paises[i].idioma == 9)
                {
                    printf("Mutlu Noeller\n");
                }
                else if(paises[i].idioma == 10)
                {
                    printf("Nollaig Shona Dhuit!\n");
                }
                else if(paises[i].idioma == 11)
                {
                    printf("Zalig Kerstfeest!\n");
                }
                else if(paises[i].idioma == 12)
                {
                    printf("Buon Natale!\n");
                }
                else if(paises[i].idioma == 13)
                {
                    printf("Milad Mubarak!\n");
                }
                else if(paises[i].idioma == 14)
                {
                    printf("Merii Kurisumasu!\n");
                }
                break;
            }
            else
            {
                paisesNaoIguais++;
            }
        }
        if(paisesNaoIguais == 24)
        {
            printf("--- NOT FOUND ---\n");
        }

        
    }

    return 0;
}
