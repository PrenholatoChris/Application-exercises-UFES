#include <stdio.h>

#define qtdlin 2
#define qtdcol 4

int main(){
    
    int B[qtdlin][qtdcol],maior=-2147483647,posicaolin[qtdlin*qtdcol], posicaocol[qtdlin*qtdcol];
    int i,j;
    int q=0;


    for (i = 0; i < qtdlin; i++){
        for ( j = 0; j < qtdcol; j++){
            scanf("%d", &B[i][j]);
            if (maior <= B[i][j]){
                maior = B[i][j];
            }
        }
    }

    for (i = 0; i < qtdlin; i++){
        for ( j = 0; j < qtdcol; j++){
            if (B[i][j] == maior){
                posicaolin[q] = i;
                posicaocol[q] = j;
                printf("O maior elemento %d, esta na linha %d e coluna %d\n",maior,posicaolin[q]+1,posicaocol[q]+1);
                q++;
                
            }
        }
    }
    
    return 0;
}