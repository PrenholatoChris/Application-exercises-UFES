#include <stdio.h>

#define linhas 3
#define colunas 3

int main(){
    int i, j, k, l, tdsnumeros = linhas*colunas;
    int Matriz[linhas][colunas];
    int Resposta[tdsnumeros][2];
    int numeros = 0;

    for (i = 0; i < linhas; i++){
        for ( j = 0; j < colunas; j++){
            scanf("%d", &Matriz[i][j]);
        }
    }

    for (i = 0; i < linhas; i++){
        for ( j = 0; j < colunas; j++){
            for (k = 0; k < linhas; k++){
                for (l = 0; l < colunas; l++){
                    if (Matriz[i][j] == Matriz[k][l]){
                        Resposta[numeros][0] = Matriz[i][j];
                        Resposta[numeros][1]++;
                        numeros++;
                        printf("não ta funcionando nao\n");
                        
                    }  
                    printf("Cada termo passa pelos outros termos\n");                            
                }              
                
            } 
            printf("passo por cada termo\n");         
        }
    }

    for (i = 0; i < numeros; i++){
        printf("O numero %d repete %d vezes",Resposta[i][0],Resposta[i][1]);                
    }
    





    return 0;
}