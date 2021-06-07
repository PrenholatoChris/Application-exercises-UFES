#include <stdio.h>

int main(){
    float valor;
    int tipo;
    printf("Digite o tipo de investimento e o valor\n");
    scanf("%d %f",&tipo,&valor);

    switch (tipo)
    {
    case 1:
        valor = valor*1.05;
        printf("%.2f\n",valor);

        break;
    
    default:
        valor = valor*1.4;
        printf(".2%f\n",valor);
        break;
    }
    return 0;
}