#include <stdio.h>
#define tam 5

int main(){
    int i, j, k;
    int A[tam][tam], somal4 = 0, somac2 = 0, somadprin = 0, somadsec = 0, soma = 0;

    for (i = 0; i < tam; i++){
        for (j = 0; j < tam; j++){
            scanf("%d", &A[i][j]);
            soma += A[i][j];
        }        
    }
    
    for (j = 0; j < tam; j++){
        somal4 += A[3][j];
        somac2 += A[j][1];
        somadprin += A[j][j];
    }
    
    j = 4;

    for (i = 0; i < tam; i++){
        somadsec += A[i][j];
        j--;
    }
    

    j=4;
    i=0;
    while (i < ){
        somadsec += A[i][j];

        j--;
        i++;
    }
    

    printf("soma da linha 4 = %d\n",somal4);
    printf("soma da coluna 2 = %d\n",somac2);
    printf("soma da Diag principal = %d\n",somadprin);
    printf("soma da Diag Sec = %d\n",somadsec);
    printf("soma total = %d\n",soma);

    return 0;
}