#include <stdio.h>

float MEDIA(float a, float b, float c);
int main(){
    
    float x, y, z;
    printf("digite X, Y e z\n");
    scanf("%f %f %f", &x,&y, &z);
    printf("%.2f", MEDIA(x, y, z));
    return 0;
}

float MEDIA(float a, float b, float c){
    float media;
    media = (a + b + c)/3;
    return media;
}