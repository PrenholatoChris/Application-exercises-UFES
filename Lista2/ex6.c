#include <stdio.h>

int main(){
    float salario = 500, funcionario;
    printf("Quanto o funionario recebe?\n");
    scanf("%f",&funcionario);
    if (funcionario<500){
        funcionario += (funcionario*0.3);
        printf("Salario reajustado para R$:%f\n",funcionario);
    }
    else{
        printf("Nao tem direito ao aumento\n");
    }
    return 0;
}