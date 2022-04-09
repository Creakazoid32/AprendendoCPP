#ifndef __BANCOS__
#define __BANCOS__

void versao(void);
void trataLinhaDigitavel(char* linhaDigitavel);
void trataCodigoDeBarras(char* codigoDeBarras);
int getBanco(char* dadoBanco);
float getValor(char* dadoBanco, int barra);
int getFatorVencimento(char* dadoBanco, int barra);
void printVencimento(int fatorVcto);

#endif