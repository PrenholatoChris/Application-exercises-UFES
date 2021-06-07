#include <stdio.h>


int main(){
    int numeros[10],i;

    for (i = 0; i < 10; i++){
        scanf("%d",&numeros[i]);
    }
    
    for (i = 9; i >= 0 ; i--){
        printf("%d\n",numeros[i]);
    }
    
    return 0;
}