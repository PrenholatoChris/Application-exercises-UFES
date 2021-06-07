#include <stdio.h>

int main(){
    int i,posicao, vetor[80],menor=2147483647;
    for ( i = 0; i < 80; i++){
        scanf("%d",&vetor[i]);
        if (menor>vetor[i]){
            menor = vetor[i];
            posicao = i;
        }
    }
    
    printf("O menor valor eh %d na posicao %d\n", menor, posicao);

    return 0;
}