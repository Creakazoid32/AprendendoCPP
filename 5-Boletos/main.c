#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bancos.h"

int main()
{
    char boleto[50];
    int i;
    int opt;
    int tipoEntrada = 0;

    do
    {
        opt = 0;
        system("CLS");
        printf("Digite os dados do boleto: ");
        scanf("%s", &boleto);

        tipoEntrada = strlen(boleto); 

        switch (tipoEntrada)
        {
        case 47:
            trataLinhaDigitavel(boleto);
            break;
        
        case 44:
            trataCodigoDeBarras(boleto);
            break;

        default:
            {
                printf("Boleto invalido(%d)!\n\n", tipoEntrada);
                printf("O que gostaria de fazer?\n");
                printf("1 - Tentar novamente\n");
                printf("9 - Sair do programa\n");
                scanf("%d", &opt);

                if(opt == 9)
                {
                    printf("\n");
                    system("PAUSE");
                    return 0;
                }

                break;
            }
        }

    } while (opt == 1);
    
    printf("\n");
    system("PAUSE");
    return 0;
}