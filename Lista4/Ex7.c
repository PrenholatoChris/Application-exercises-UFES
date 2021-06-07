#include <stdio.h>

int main(){
    int i,posicao, A[50],B[50];

    for ( i = 0; i < 50; i++){
        scanf("%d",&A[i]);
        

        if (A[i] % 2 == 0){
            B[i] = A[i]/2;
        }
        else{
            B[i] = A[i]*3;
        }
    }
    
    for ( i = 0; i < 50; i++){
        printf("A - %d\n",A[i]);
    }
    
    for ( i = 0; i < 50; i++){
        printf("B - %d\n",B[i]);
    }

    return 0;
}