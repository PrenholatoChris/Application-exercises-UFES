#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define limite 10

typedef struct {
    char nome[30];
    float media;
    float prova;
    int faltas;
}al;

void save_data(al aluno[], int total);
void criar_aluno(al aluno[], int i);

int main(){
    al aluno[limite]; 
    int i = 0;
    char escolha[2]; 

    while (strcmp(escolha,"N") != 0){
        printf("Digite o nome do aluno\n");
        scanf("%s",aluno[i].nome);
        printf("Digite a media do aluno\n");
        scanf("%f", &aluno[i].media);
        printf("Digite a nota da prova do aluno\n");
        scanf("%f", &aluno[i].prova);
        printf("Digite as faltas do aluno\n");
        scanf("%d", &aluno[i].faltas);
        printf("Deseja registrar outro aluno?\n");
        printf("S ou N\n");
        scanf("%s", escolha);
        i++;
    }
    
    printf("Deseja incluir mais alunos?\n");
    scanf("%s", escolha);
    
    while (strcmp(escolha,"N") != 0){
        if (strcmp(escolha,"S") == 0){
            criar_aluno(aluno, i);
            i++;
        }
        printf("Deseja incluir mais alunos?\n");
        scanf("%s", escolha);
    }
        
    save_data(aluno, i);

    return 0;
}


void save_data(al aluno[], int total){
    FILE *arq;
    FILE *arq1;
    FILE *arq2;
    arq = fopen("aprovados.txt", "w");
    arq1 = fopen("repfalta.txt", "w");
    arq2 = fopen("repnota.txt", "w");

    for (int i = 0; i < total; i++){
        float media_f = (aluno[i].media + aluno[i].prova)/2;
        if (aluno[i].media >= 7 || media_f >= 7){
            if (aluno[i].faltas >= 10){
                fprintf(arq1,"%s\n", aluno[i].nome);
            }
            else{
            fprintf(arq,"%s\n", aluno[i].nome);
            }
        }

        else{
            fprintf(arq2,"%s\n", aluno[i].nome);
        }
    }

    fclose(arq);
    fclose(arq1);
    fclose(arq2);
}


void criar_aluno(al aluno[], int i){
    printf("Digite o nome do aluno\n");
    scanf("%s",aluno[i].nome);
    printf("Digite a media do aluno\n");
    scanf("%f", &aluno[i].media);
    printf("Digite a nota da prova do aluno\n");
    scanf("%f", &aluno[i].prova);
    printf("Digite as faltas do aluno\n");
    scanf("%d", &aluno[i].faltas);
}