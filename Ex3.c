#include <stdio.h>
#include <stdlib.h>
#define qtd 5
#define mat 6

typedef struct{
    float disciplinas[mat];
}provafinal;


typedef struct{
  int matricula;
  char nome[20];
  float media;
  provafinal pf;  
}alunos;


int main(){
    alunos aluno[qtd];
    int i,j;
    float notaX = 0;
    int escolha = 0;
    int aux = 1;
    int nmatricula;
    float somadaspfs; 

    printf("Cadastrando o aluno\n");
    //CADASTRO DOS ALUNOS
    for (i = 0; i < qtd; i++){
        somadaspfs = 0;
        printf("Digite a matricula\n");
        //scanf("%s", &aluno->matricula[i])
        scanf(" %d", &aluno[i].matricula);

        printf("Digite o nome\n");
        //scanf("%s", aluno[i].nome);
        scanf(" %[^\n]", aluno[i].nome);
        

        for (j = 0; j < mat; j++){
            //Scan das notas
            printf("Digite a nota final da materia %d\n",j+1);
            scanf("%f", &aluno[i].pf.disciplinas[j]);
            while(aluno[i].pf.disciplinas[j] > 10 || aluno[i].pf.disciplinas[j] < 0){
                printf("Nota invalida, digite novamente\n");
                scanf("%f", &aluno[i].pf.disciplinas[j]);                
            }

            somadaspfs += aluno[i].pf.disciplinas[j];
        }
        aluno[i].media = somadaspfs/mat;
        somadaspfs = 0;
    }

    //Escolha do usuario
    while (escolha != 4){
        system("cls");
        printf("O que deseja fazer?\n");
        printf("1 - Listar todos os alunos\n");
        printf("2 - Listar alunos com media acima de X\n");
        printf("3 - Alterar a nota de um aluno\n");
        printf("4 - Sair do programa\n");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
        printf("| Matricula  |         Nome         | Media | Notas finais 1 | 2 | 3 | 4 | 5 | 6 |\n");
            for (i = 0; i < qtd; i++){
                for (j = 0; j < mat; j++){
                    somadaspfs += aluno[i].pf.disciplinas[j];
                } 
                aluno[i].media = somadaspfs/mat;
                somadaspfs = 0;
                printf("| %d | %20s | %6.1f |",aluno[i].matricula,aluno[i].nome,aluno[i].media);

                for ( j = 0; j < mat; j++){
                    printf(" %4.1f |",aluno[i].pf.disciplinas[j]);
                }
                printf("\n");
            }
            system("PAUSE");
            break;
    
        case 2:
            printf("Digite uma nota para ver os alunos com media maior ou igual a digitada.\n");
            scanf("%f", &notaX);
            
            for (i = 0; i < qtd; i++){
                if (aluno[i].media >= notaX){
                    printf("%s - CR = %.1f\n",aluno[i].nome, aluno[i].media);
                    aux = 0;
                }
            }
            if (aux == 1){
                printf("Nenhum aluno com media maior ou igual a %.1f\n",notaX);
            }            
            system("PAUSE");
            break;
        

            //tese 2
            // printf("Digite uma nota para ver os alunos com media maior ou igual a digitada.\n");
            // scanf("%f", &notaX);
            // for (i = 0; i < qtd; i++){
            //     for (j = 0; j < mat; j++){
            //         if(aluno[i].pf.disciplinas[j] >= notaX){
            //             printf("%s - nota %.1f na materia %d\n",aluno[i].nome,aluno[i].pf.disciplinas[j],j+1);       
            //             aux = 0;
            //         }
            //     }        
            // }
            //
            // if (aux == 1){
            //         printf("Nenhum aluno com media igual ou maior a %.1f\n",notaX);
            //     }
            // system("PAUSE");
            // break;


        case 3:
            printf("Digite o numero da matricula?\n");
            scanf("%d", &nmatricula);
            int matricula_inexistente = 1;
            for (i = 0; i < qtd; i++){
                if (nmatricula == aluno[i].matricula){
                    printf("Aluno(a) encontrado(a) - %s\n",aluno[i].nome);
                    printf("Qual das 1-6 notas da provas finais deseja mudar?\n");
                    int qualprova;
                    scanf("%d", &qualprova);
                    printf("Digite a nova nota\n");
                    scanf("%f", &aluno[i].pf.disciplinas[qualprova-1]);
                    printf("Atualizada\n");
                    matricula_inexistente = 0;
                }
            }

            if (matricula_inexistente == 1){
                printf("Matricula nao encontrada\n");
            }
            system("PAUSE");
            break;


        default:
            break;
        }
        
    }
    printf("Obrigado por utilizar meu programa\n");
    printf("Made by: Christian Prenholato\n");
    return 0;
}