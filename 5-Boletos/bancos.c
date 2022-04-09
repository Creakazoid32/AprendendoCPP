#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bancos.h"

int getBanco(char* dadoBanco);
void procITAU(char* data, int barra);
void procBB(char* data, int barra);
float getValor(char* dadoBanco, int barra);
int getFatorVencimento(char* dadoBanco, int barra);
void printVencimento(int fatorVcto);

void versao(void)
{
    printf("v 0.0.0\n");
}

void trataLinhaDigitavel(char* linhaDigitavel)
{
    int banco;

    printf("Linha digitavel identificada.\n");

    //Identificar Banco
    banco = getBanco(linhaDigitavel);
    
    switch (banco)
    {
    case 341:
        procITAU(linhaDigitavel, 0);
        break;
    
    case 001:
        procBB(linhaDigitavel, 0);
        break;

    default:
        printf("Banco nao identificaod!\n");
        break;
    }
}

void trataCodigoDeBarras(char* codigoDeBarras)
{
    int banco;

    printf("Codigo de barras identificado.\n");

    //Identificar Banco
    banco = getBanco(codigoDeBarras);
    
    switch (banco)
    {
    case 341:
        procITAU(codigoDeBarras, 1);
        break;
    
    case 001:
        procBB(codigoDeBarras, 1);
        break;

    default:
        printf("Banco nao identificaod!\n");
        break;
    }
}

int getBanco(char* dadoBanco)
{
    int i;
    char banco[4];

    for (i = 0; i < 3; i++)
    {
        banco[i] = dadoBanco[i];
    }

    banco[3] = '\0';

    return atoi(banco);   
}

float getValor(char* dadoBanco, int barra)
{
    char *str = malloc(strlen(dadoBanco));
    float valor;

    if(barra == 0)
    {
        valor = atof(strncpy(str, dadoBanco + 37, 10));
    }
    else
    {
        valor = atof(strncpy(str, dadoBanco + 9, 10));
    }

    valor = valor / 100;

    free(str);
    return valor;   
}

int getFatorVencimento(char* dadoBanco, int barra)
{
    char *str = malloc(strlen(dadoBanco));
    int fatorVencimento;

    if(barra == 0)
    {
        fatorVencimento = atof(strncpy(str, dadoBanco + 33, 4));
    }
    else
    {
        fatorVencimento = atof(strncpy(str, dadoBanco + 5, 4));        
    }

    free(str);
    return fatorVencimento;   

}

void printVencimento(int fatorVcto)
{
    //Data base do fator de vencimento 07/10/1997
    int day = 7;
    int month = 10; 
    int year = 1997; 
    int days_to_add = fatorVcto;
    char strBuffer[3];
    char strDay[3];
    char strMon[3];
    struct tm tm;

    // initialize the structure
    memset(&tm,0,sizeof(struct tm));

    tm.tm_year = year-1900; 
    tm.tm_mon = month-1; // 0 = Jan, 1 = Feb etc
    tm.tm_mday = day;
    tm.tm_hour = 12; // fictious
    tm.tm_mday += days_to_add;
    mktime(&tm);

    strBuffer[0] = '\0';
    strDay[0] = '\0';
    itoa(tm.tm_mday, strDay, 10);

    if(tm.tm_mday < 10)
    {
        strcat(strBuffer, "0");
        strcat(strBuffer, strDay);
        strcpy(strDay, strBuffer);
        strDay[2] = '\0';
    }
    else
    {
        strDay[2] = '\0';
    }
    
    strBuffer[0] = '\0';
    strMon[0] = '\0';
    itoa(tm.tm_mon + 1, strMon, 10);

    if(tm.tm_mon < 10)
    {
        strcat(strBuffer, "0");
        strcat(strBuffer, strMon);
        strcpy(strMon, strBuffer);
        strMon[2] = '\0';
    }
    else
    {
        strMon[2] = '\0';
    }

    //printf("%s", asctime(&tm));    
    printf("Vencimento: %s/%s/%d\n", strDay, strMon, tm.tm_year + 1900);
}


/*ITAU*/
void procITAU(char* data, int barra)
{
    float valor = 0.00;
    int fatorVencimento = 0;

    printf("Boleto do banco: ITAU\n");

    valor = getValor(data, barra);
    printf("Valor: %1.2f\n", valor);


    fatorVencimento = getFatorVencimento(data, barra);
    printVencimento(fatorVencimento);
}

/*BB*/
void procBB(char* data, int barra)
{
    float valor = 0.00;
    int fatorVencimento = 0;

    printf("Boleto do banco: Banco do Brasil\n");

    valor = getValor(data, barra);
    printf("Valor: %1.2f\n", valor);


    fatorVencimento = getFatorVencimento(data ,barra);
    printVencimento(fatorVencimento);

}

