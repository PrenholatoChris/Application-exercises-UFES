#include <stdio.h>

float SEG(float x,float y, float z);
int main(){
    float x, y, z;
    printf("digite as horas, minutos e segundos\n");
    scanf("%f %f %f", &x,&y, &z);
    printf("%.2f", SEG(x, y, z));
    return 0;
}

float SEG(float x,float y, float z){
    float total;
    total = (x * 3600) + (y * 60) + z;
    return total;
}
