#include <stdio.h>

int main(){
    int R=1,numero;

    scanf("%d",&numero);

    while (numero > 2){
        R = R * 2;
        printf("%d\n",R);
        numero--;
    }
    
    return 0;
}