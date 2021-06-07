#include <stdio.h>


int main(){
    int valores[20],i,pares=0;

    for (i = 0; i < 20; i++){
        scanf("%d",&valores[i]);
        if (valores[i] % 2 == 0){
            pares++;
        }
        
    }
    printf("Existem %d valores pares",pares);

    return 0;
}