#include <stdio.h>

int main(){
    int angulo1,angulo2;
    printf("Digite 2 angulos do triangulo");
    scanf("%d %d",angulo1,angulo2);
    int angulo3 = 180-(angulo1+angulo2);
    printf("O terceiro angulo eh %d",angulo3);
    return 0;
}