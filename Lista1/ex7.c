#include <stdio.h>

int main(){
    float pesokg,pesog;
    printf("Digite seu peso em Kg\n");
    scanf("%f",pesokg);
    pesog = (pesokg*1000);
    printf("Seu peso em gramas eh %f\n",pesog);
    return 0;
}