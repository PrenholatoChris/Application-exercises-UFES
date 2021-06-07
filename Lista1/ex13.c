#include <stdio.h>

int main(){
    int anonascimento;
    printf("Digite seu ano de nascimento");
    scanf("%f",anonascimento);

    int anos,meses,dias,semanas;
    anos = 2021 - anonascimento;
    meses = anos*12;
    dias = meses*30;
    semanas = dias/7;
    
    printf("%d",anos);
    printf("%d",meses);
    printf("%d",dias);
    printf("%d",semanas);

    return 0;
}