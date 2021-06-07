#include <stdio.h>

int main(){
    int salario,vendas;
    scanf("%d %d",salario,vendas);
    int resposta = (salario+(vendas*0.04));
    printf("%d",resposta);
    return 0;
}