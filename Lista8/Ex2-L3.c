#include <stdio.h>
#include <string.h>

int data_in(char aluno[][30]);
void ordenar(char aluno[][30], int total);

int main(){
    int total = 0;
    char aluno[40][30];

    total = data_in(aluno);

    ordenar(aluno, total);



    for (int i = 0; i <total; i++){
        printf("%s\n",aluno[i]);
    }
    

    return 0;
}

int data_in(char aluno[][30]){

    int total=0;

    FILE *arq1;
    FILE *arq2;
    FILE *arq3;

    arq1 = fopen("aprovados.txt", "r");
    arq2 = fopen("repnota.txt", "r");
    arq3 = fopen("repfalta.txt", "r");

    while (!feof(arq1)){
        fscanf(arq1, "%s", aluno[total]);
        (total)++;
    }
    total--;
    
    while (!feof(arq2)){
        fscanf(arq2, "%s", aluno[total]);
        (total)++;
    }
    total--;

    while (!feof(arq3)){
        fscanf(arq3, "%s", aluno[total]);
        (total)++;
    }

    total--;


    printf("Dados lidos com sucesso\n");

    return total;
}

void ordenar(char aluno[][30], int total){
    char aux[30];

    for (int i = 0; i < total; i++){
        for (int j = 0; j < total; j++){
            if (strcmp(aluno[i], aluno[j]) < 0){
                strcpy(aux, aluno[i]);
                strcpy(aluno[i],aluno[j]);
                strcpy(aluno[j],aux);
            }
        }
    }
    

}