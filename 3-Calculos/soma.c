//Um programa que receba dois números e informe o resultado da soma entre eles.

//Inlusão das dependências
#include <stdio.h>
#include <stdlib.h>

//Função principal
int main()
{
    //Declaração de variáveis
    float num1;
    float num2;
    float res;


    system("CLS");

    //Entrada de dados
    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    //Processamentos dos dados
    res = num1 + num2;

    //Saida das informações
    printf("Resultado da soma %1.2f + %1.2f = %1.2f\n", num1, num2, res);

    //Finalização do programa
    system("PAUSE");

    return 0;
}