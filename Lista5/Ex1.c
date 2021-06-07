#include <stdio.h>

#define lin 3
#define col 5
int main(){
    int MAT1[lin][col],MAT2[lin][col],MSOMA[lin][col];
    int i,j;
    
    
    for (i = 0; i < lin; i++){
        for ( j = 0; j < col; j++){
            scanf("%d", &MAT1[i][j]);

        }
    }

    for (i = 0; i < lin; i++){
        for ( j = 0; j < col; j++){
            scanf("%d", &MAT2[i][j]);
        }
    }
    
    for (i = 0; i < lin; i++){
        for ( j = 0; j < col; j++){
            MSOMA[i][j] = MAT1[i][j] + MAT2[i][j];
            printf("%d ", MSOMA[i][j]);
        }
        printf("\n");
    }

    return 0;
}