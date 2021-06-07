#include <stdio.h>
#define lin 5
#define col 4

int main(){
    float matriz[lin][col], transposta[col][lin];
    int i,j;
    for (i = 0; i < lin; i++){
        for ( j = 0; j < col; j++){
            scanf("%f", &matriz[i][j]);
            transposta[j][i] = matriz[i][j];
        }
    }
    
    for (i = 0; i < col; i++){
        for ( j = 0; j < lin; j++){
            printf("%f ",transposta[i][j]);
       }
        printf("\n");
    }

    return 0;
}