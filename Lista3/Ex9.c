#include <stdio.h>

int main(){
    float Salario,SalarioNovo;
    char *Nome;
    int Jogadores,i;
    
    for (i = 1; i <= 22; i++){
        scanf("%s %f",Nome,&Salario);
    
        if (Salario >= 0 && Salario <= 1000){
        SalarioNovo = Salario*1.2;
        }
        
        if (Salario > 1000 && Salario <= 5000){
        SalarioNovo = Salario*1.1;
        }
        
        if (Salario>5000){
        SalarioNovo = Salario*1;
        }
    }

    
    return 0;
}
