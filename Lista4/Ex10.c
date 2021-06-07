#include <stdio.h>
int main(){
    int M[5][5],linha4=0,coluna2=0,diagonalprin=0,diagonalsec=0,todos=0;
    int i,j;

    for (i = 0; i < 5 ; i++){
        for (j = 0; j < 5 ; j++){
            scanf("%d",&M[i][j]);
            todos += M[i][j];
        }
    }
    
    for (i = 0; i < 5 ; i++){
        linha4 += M[3][i];
        diagonalprin += M[i][i];
        coluna2 += M[i][1];
    }

    
    for ( i = 0; i < 5 ; i++){
        for (j = 5; j >= 0 ; j--){
            diagonalsec += M[i][j];
        }
        
    }
    
    printf("Soma da linha 4 = %d\nSoma da coluna 2 = %d\nSoma da Diagonal principal = %d\nSoma da Diagonal Secundaria = %d\nSoma de todos os elementos = %d",linha4,coluna2,diagonalprin,diagonalsec,todos);

    return 0;
}