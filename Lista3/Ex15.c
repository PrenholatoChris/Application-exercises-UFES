#include <stdio.h>

int main(){
    int qtdArroba;
    float precoArroba,PrecoTotal=0,PesoTotal=0,PesoAnimal;

    scanf("%f",&precoArroba);
    scanf("%f",&PesoAnimal);
    while (PesoAnimal != 0){
        PesoTotal += PesoAnimal;

        scanf("%f",&PesoAnimal);
    }
    
    PesoTotal = PesoTotal/2;
    qtdArroba = PesoTotal/15;
    printf("PesoTotal= %.2f QtdArroba= %.2f\n",PesoTotal,qtdArroba);
    PesoTotal = qtdArroba*precoArroba;
    printf("%.2f\n",PrecoTotal);
}