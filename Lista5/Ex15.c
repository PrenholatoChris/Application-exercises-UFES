#include <stdio.h>
#define linha 60
#define coluna 10

int main(){
    int Matriz[linha+1][coluna];
    int i,j;

    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            scanf("%d", &Matriz[i][j]);
            Matriz[linha][i] += Matriz[j][i];
        }
    }
    
    for (j = 0; j < coluna; j++){
        Matriz[linha][j] = 0;
        printf("%d ",Matriz[linha][i]);
    }

    return 0;
}