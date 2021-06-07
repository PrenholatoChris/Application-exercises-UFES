// Faça uma função em C que verifique quantas vezes um número inteiro x é divisível por um número
// inteiro y. A função deve retornar -1 caso não seja possível calcular. Escreva também um algoritmo para
// testar tal função.
#include <stdio.h>

int dividindo(float x, int y);


int main(){
    float x;
    int y;
    scanf("%f", &x);
    scanf("%d", &y);

    printf("%d vezes\n", dividindo(x,y));
    
    return 0;
}

int dividindo(float x, int y){
    int contar=0;
    if (x<y){
        return -1;
    }
    

    while (x>=y){
        x -= y;
        contar++;
    }
    

    return contar;
}