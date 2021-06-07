#include <stdio.h>
int main(){
    
    int senha,input;
    printf("Digite a senha\n");
    scanf("%d",&input);
    senha = 4531;

        if (input == senha){
            printf("Acesso concedido\n");
            
        }
        else{
            printf("Acesso negado\n");
        }

    return 0;
}