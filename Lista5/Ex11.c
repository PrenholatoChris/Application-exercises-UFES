#include <stdio.h>

#define linhas 3
#define colunas 3

int main(){
    int i, j, k, l;
    int Matriz[linhas][colunas];
    int repete = 0;
    int Xrepetido,Numerosrepetidos,qtdrepetido=0;
    int javerificados[linhas*colunas];
    //javerificados[0] = 0;
    for (i = 0; i < linhas; i++){
        for ( j = 0; j < colunas; j++){
            scanf("%d", &Matriz[i][j]);
            for (k = 0; k < linhas; k++){
                for (l = 0;l < colunas; l++){
                    if (Matriz[i][j] == Matriz[k][l]){
                        Xrepetido = Matriz[i][j];
                        qtdrepetido++;
                    }                    
                }
            }
            printf("O numero %d se repete %d\n",Xrepetido,qtdrepetido);
        }
    }

    return 0;
}