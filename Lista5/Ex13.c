#include <stdio.h>
#define linha 3
#define coluna 3

int main(){
    int Matriz[linha][coluna];
    int i,j;
    int soma = 0;
    float media;
    for ( i = 0; i < linha; i++){
        for ( j = 0; j < coluna; j++){
            scanf("%d", &Matriz[i][j]);
        }
    }
    
    for (i = 0; i < linha; i++){
        soma += Matriz[i][i];
    }
    media = (float)soma/linha;
    printf("A media da diagonal principal e = %.f\n", media);

    return 0;
}