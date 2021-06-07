#include <stdio.h>

int main(){
    float salariomin,salario;
    printf("Digite salario minimo");
    scanf("%f",salariomin);
    printf("Digite salario do funcionario"); 
    scanf("%f",salario);
    float recebe = salario/salariomin;
    printf("Funcionario recebe %d salarios minimos",recebe);
    return 0;
}