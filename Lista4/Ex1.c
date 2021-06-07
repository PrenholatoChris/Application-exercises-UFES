#include <stdio.h>

int main(){
    int i,A[20],B[20],C[20];

    for (i = 0; i < 20; i++){
        scanf("%d",&A[i]);
    }
    for (i = 0; i < 20; i++){
        scanf("%d",&B[i]);
    }
    for (i = 0; i < 20; i++){
        C[i] = A[i]+B[i];
        printf("%d valor - %d\n",i+1,C[i]);
    }

    return 0;
}