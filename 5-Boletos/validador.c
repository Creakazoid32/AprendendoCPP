#include <stdio.h>

int verificador(int pos, int* cpf) {
    int i, p=0;
    for(i=1;i<=pos;i++){
        p+=cpf[i]*(pos+2-i);
    }

    int d = 11 - p%11;
    if (d >= 10) {
        d = 0;
    }
    return d == cpf[i];
}

int main(){
    int cpf[12]={0},i,d1,d2;

    printf("Digite o CPF: ");
    scanf("%s", &cpf);

    d1 = verificador(9, cpf);

    d2 = verificador(10, cpf);

    if(d1 && d2){
        printf("CPF Valido\n");
    }
    else{
        printf("CPF Invalido");
    }

    return 0;
}