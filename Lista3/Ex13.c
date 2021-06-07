#include <stdio.h>

int main(){
    int Ncons,tipo,Qtdcons=0;
    float Energia,Preco,Totaltipo1=0,Totaltipo2=0,Totaltipo3=0,MediaGeral=0,TotalGeral=0;
        scanf("%d",&Ncons);

    while (Ncons != 0){
        scanf("%f %d",&Energia,&tipo);

        switch (tipo){
        case 1:
            Preco = Energia*0.3;
            Totaltipo1 += Preco;

            break;

        case 2:
            Preco = Energia*0.5;
            Totaltipo2 += Preco;

            break;
        case 3:
            Preco = Energia*0.7;
            Totaltipo3 += Preco;

            break;           
        default:
            break;
        }

        Qtdcons ++;
        TotalGeral += Preco;
        printf("O custo total = R$%.2f\n",Preco);
        scanf("%d",&Ncons);
        
    }

    printf("Total consumido pelo tipo 1 = R$%.2f\n",Totaltipo1);
    printf("Total consumido pelo tipo 2 = R$%.2f\n",Totaltipo2);
    printf("Total consumido pelo tipo 3 = R$%.2f\n",Totaltipo3);
     
    MediaGeral = TotalGeral/Qtdcons;
    printf("A Media geral consumida = R$%.2f\n",MediaGeral);

    return 0;

}