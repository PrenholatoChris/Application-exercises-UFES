#include <stdio.h>
#define quantidade 30
#define valorespecifico 10

int main(){
    int VET[quantidade], i, k = valorespecifico, existe=0;
    for (i = 0; i < quantidade; i++){
        scanf("%d",&VET[i]);
        if (VET[i] == k){
            existe = 1;
        }
    }
 
    if (existe == 1){
        for (i = 0; i < quantidade; i++){
            if (VET[i] == k){
                printf("Existe k na posicao = %d\n",i+1);
            }
        }
    }

    else{
        printf("nao encontrei K no vetor.\n");
    }


    return 0;
}