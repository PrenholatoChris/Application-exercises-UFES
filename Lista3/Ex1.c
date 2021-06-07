#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i,testes;
    float n1,n2,n3;

    scanf("%d", &testes);
    for (i = 1; i <= testes; i++){
        scanf("%f %f %f",&n1,&n2,&n3);
        float media = ((n1*2) + (n2*3) + (n3*5))/10;

        printf("%.1f\n",media);


    }




    return 0;
}