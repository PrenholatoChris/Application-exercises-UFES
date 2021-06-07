#include <stdio.h>
#define lin 30
#define col 30
int main(){
    int matriz[lin][col],A,vezes=0,i,j;
    
    scanf("%d",&A);
    
    for (i = 0; i < lin ; i++){
        for (j = 0; j < col; j++){
            scanf("%d",&matriz[i][j]);
            if (matriz[i][j] == A){
                vezes++;
            }
        }
    }
    
    printf("%d",vezes);



    return 0;
}