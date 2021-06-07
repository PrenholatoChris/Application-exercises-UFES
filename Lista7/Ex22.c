#include <stdio.h>

#define lin 5
#define col 5

void ler_matriz(int A[lin][col]);
void soma(int A[lin][col], int B[lin][col], int C[lin][col]);
void printar_matriz(int C[lin][col]);

int main(){
    int A[lin][col], B[lin][col], C[lin][col];
    ler_matriz(A);
    ler_matriz(B);
    soma(A, B, C);
    printar_matriz(C);
 
    return 0;
}


void ler_matriz(int A[lin][col]){

    for (int i = 0; i < lin ; i++){
        for (int j = 0; j < col; j++){
            scanf("%d", &A[i][j]);            
        }
    }
    printf("Matriz lida\n");
}

void soma(int A[lin][col], int B[lin][col], int C[lin][col]){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Matriz somada\n");
}

void printar_matriz(int C[lin][col]){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("Fim\n");
}