#include <stdio.h>

void TOTAL(int *x, int *y, int *z);
int main(){
    int x, y, z;
    printf("digite os segundos\n");
    scanf("%d", &z);
    TOTAL(&x, &y, &z);
    printf("%d: %d: %d\n", x, y, z);
    return 0;
}

void TOTAL(int *x, int *y, int *z){
    if(*z >3600){
        *x = *z/3600;
        *z -= (*x )* 3600;
    }
    if(*z > 60){
        *y = (*z/60);
        *z -= (*y) * 60;
    }
}
