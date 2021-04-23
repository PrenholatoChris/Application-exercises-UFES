#include <stdio.h>

typedef struct{
    char modelo[10];
    char marca[10];
    int ano;
    char cor[10];
    float preco;
}Concessionaria;

#define qtd 10

int main(){
    Concessionaria Carros[qtd];
    int i;    
    for (i = 0; i < qtd; i++){    
        printf("Digite o modelo do carro\n");
        scanf("%s", Carros[i].modelo);
        printf("Digite a marca\n");
        scanf("%s", Carros[i].marca);
        printf("Digite o ano\n");
        scanf("%d", &Carros[i].ano);
        printf("Digite a cor\n");
        scanf("%s", Carros[i].cor);
        printf("Digite o preco\n");
        scanf("%f", &Carros[i].preco);
        printf("\n");
    }    

    printf("O programa printara os carros com valor abaixo de R$ 20.000,00.\n");

    for (i = 0; i < qtd; i++){
        if (Carros[i].preco < 20000){
        printf("O carro %s\n",Carros[i].modelo);
        printf("da marca %s\n",Carros[i].marca);
        printf("do ano %d\n",Carros[i].ano);
        printf("de cor %s\n",Carros[i].cor);
        printf("custa %.2f\n",Carros[i].preco);
        printf("\n");
        }
    }
    system("PAUSE");

    return 0;
}