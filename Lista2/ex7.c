#include <stdio.h>

int main(){
    float funcionario;
    printf("Quanto o funionario recebe?\n");
    scanf("%f",&funcionario);
        if (funcionario<300){
            funcionario += (funcionario*0.35);
            printf("Salario reajustado para R$:%f\n",funcionario);
        }

        else{
            funcionario += (funcionario*0.15);
            printf("Salario reajustado para R$:%f\n",funcionario);
        }

    return 0;
}