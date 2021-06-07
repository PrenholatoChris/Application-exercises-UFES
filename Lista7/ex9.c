#include <stdio.h>

void sinal(int n);
int main(){
    int n;
    printf("digite n\n");
    scanf("%d", &n);
    sinal(n);
    return 0;
}

void sinal(int n){
    if(n > 0){
        printf("positivo\n");
    }
    else if(n < 0){
        printf("negativo\n");
    }
    else{
        printf("zero\n");
    }
}

