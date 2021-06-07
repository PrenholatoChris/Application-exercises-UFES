#include <stdio.h>
#define linha 3
#define k 10
#define coluna 3
int main(){
    int VET[linha][coluna], existe=0;
    int i, j;
    
    
    for (i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            scanf("%d", &VET[i][j]);
            if (VET[i][j] == k){
                existe = 1;
            }
        }
    }
 
    if (existe == 1){
        for (i = 0; i < linha; i++){
            for(j = 0; j < coluna; j++){
                if (VET[i][j] == k){
                    printf("Existe k na linha %d e coluna %d\n",i+1,j+1);
                }
            }
        }   
    }

    else{
        printf("nao encontrei K no vetor.\n");
    }


    return 0;
}