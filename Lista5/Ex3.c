#include <stdio.h>
#define linhaA 3
#define ColunaA 5
#define LinhaB 5
#define ColunaB 3

int main(){
    int A[linhaA][ColunaA], B[LinhaB][ColunaB], MSOMA[linhaA][ColunaB];
    int i,j,x,aux = 0;
    
    
    for (i = 0; i < linhaA; i++){
        for ( j = 0; j < ColunaA; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < LinhaB; i++){
        for ( j = 0; j < ColunaB; j++){
            scanf("%d", &B[i][j]);

        }
    }

    for (i = 0; i < linhaA; i++){
        for (j = 0; j < ColunaB; j++){
            for ( x = 0; x < LinhaB; x++){
                aux += A[i][x]*B[x][j];
            }
            MSOMA[i][j] = aux;
            aux = 0;

        }
    }

    for (i = 0; i < linhaA; i++){
        for ( j = 0; j < ColunaB; j++){
            printf("%d ",MSOMA[i][j]);
        }
        printf("\n");
    }
    return 0;
}