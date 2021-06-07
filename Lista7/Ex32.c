#include <stdio.h>
#include <string.h>

int main(){
    char numero[30];
    scanf("%s", numero);
    printf("%d\n", capicuia(numero));

    return 0;
}


int capicuia(char numero[]){
    int tam = strlen(numero);
    int tam1 = 0;


    for (int i = 0; i < tam; i++){
        if (numero[i] == numero[(tam-1)-i]){
            tam1++;
        }
    }
    

    if (tam == tam1){
        return 1;
    }
    
    return 0;
}