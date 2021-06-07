#include <stdio.h>

int leitura(int n);
void sinal(int n);
int main(){
    int n=0;
    n = leitura(n);
    sinal(n);
    return 0;
}

int leitura(int n){
    printf("digite n\n");
    scanf("%d", &n);
    return n;
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