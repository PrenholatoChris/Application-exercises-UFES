#include <stdio.h>

int main(){
    float raio,pi = 3.14;
    printf("Digite o Raio da esfera");
    scanf("%f",raio);
float comprimento = (2*pi*raio);
float area = (pi*raio*raio);
float volume = (4*pi*raio*raio*raio)/3;
    printf("O comprimento fa esfera eh %f",comprimento);
    printf("A area da esfera eh %f",area);
    printf("O volume da esfera eh %f",volume);
    return 0;
}
