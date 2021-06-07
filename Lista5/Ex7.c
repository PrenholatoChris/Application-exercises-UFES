#include <stdio.h>

#define linA 5
#define colA 10
int main(){
 
    int A[linA][colA],matriz[linA][3];
    int i,j;
    int maior=-2147483647,menor=2147483647,soma=0;

    for (i = 0; i < linA; i++){
        for ( j = 0; j < colA; j++){
            scanf("%d", &A[i][j]);
        }        
    }

    for (i = 0; i < linA; i++){
        for ( j = 0; j < colA; j++){
            if (maior<A[i][j]){
                maior = A[i][j];
                matriz[i][0] = A[i][j];
            }

            if (menor>A[i][j]){
                menor = A[i][j];
                matriz[i][1] = A[i][j];
            }
            soma += A[i][j];
            matriz[i][2] = soma;
        }        

        soma = 0;
        maior=-2147483647;
        menor=2147483647;
    }


    for (i = 0; i < linA; i++){
        for ( j = 0; j < 3; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}