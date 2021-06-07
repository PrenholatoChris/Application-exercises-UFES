#include <stdio.h>
int main(){

    int num1, maior=-1, menor, i;
    float media=0;

    printf("Digite 20 numeros inteiros: \n");

        for (i = 0; i < 20; i++){

            
            scanf("%d", &num1);

            if (maior<num1){
                maior = num1;
            }

            else if (menor>num1){
                menor = num1;            
            }
        
        media += num1;
    }


    media = media/20;

    printf("O maior = %d\n",maior);
    printf("O menor = %d\n",menor);
    printf("A media = %.2f\n",media);



    return 0;
}