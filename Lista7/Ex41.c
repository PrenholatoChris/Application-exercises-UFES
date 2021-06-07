#include <stdio.h>

float f_p_celsius(float f);

int main(){
    float f;
    scanf("%f", &f);
    printf("%.2f graus celsius\n",f_p_celsius(f));

    return 0;
}

float f_p_celsius(float f){
    float C;
    C = (5*(f - 32))/9;
    return C;
}