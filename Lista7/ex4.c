#include <stdio.h>

int dobro(float n);

int main(){
    float n;
    printf("digite o valor\n");
    scanf("%f", &n);
    dobro(1);
    n = dobro(n);
    printf("%.2f", n);
    return 0;
}

int dobro(float n){
    n = 2 * n;
    return n;
}