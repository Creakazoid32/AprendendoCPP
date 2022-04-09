#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    float res;

    system("CLS");

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    res = num1 - num2;

    printf("O resultado da subtracao %1.2f - %1.2f = %1.2f\n", num1, num2, res);

    system("PAUSE");

    return 0;
}