#include <stdio.h>
#define qtdaluno 10
#define qtdmateria 5


typedef struct {
    char materia[qtdmateria][40];
    float media[qtdmateria];
    float pf[qtdmateria];
} disciplinas;


typedef struct {
    char nome[40];
    disciplinas materias;
} alunos;




int main(){
    int i,j;
    alunos aluno[qtdaluno];
    //Receber quais sao as materias
    for (i = 0; i < qtdmateria; i++){
        printf("Digite as %d materias dos alunos de medicina\n%d - ",qtdmateria, i+1);
        scanf(" %[^\n]",aluno->materias.materia[i]);
        //scanf("%s", aluno->materias.materia[i]);
    }
    
    //receber aas infos dos alunos
    for (i = 0; i < qtdaluno; i++){
        printf("Digite o nome do aluno\n");
        scanf(" %[^\n]", aluno[i].nome);
        //scanf("%s", aluno[i].nome);

        for (j = 0; j < qtdmateria; j++){
            printf("Digite a media do(a) aluno(a) %s na materia %s.\n",aluno[i].nome,aluno->materias.materia[j]);
            scanf("%f", &aluno[i].materias.media[j]);

            if (aluno[i].materias.media[j] < 7){
                printf("Digite a nota da Prova final\n");
                scanf("%f", &aluno[i].materias.pf[j]);
                aluno[i].materias.media[j] = (aluno[i].materias.media[j]+aluno[i].materias.pf[j])/2;
            }   
        }
    }    

    //printar Tudo sobre o aluno
    for (i = 0; i < qtdaluno; i++){
        printf("Nome: %s\n", aluno[i].nome);
        printf("Materias : notas\n");
        for (j = 0; j < qtdmateria; j++){
            printf("%s : %.1f ", aluno->materias.materia[j], aluno[i].materias.media[j]); 
            if (aluno[i].materias.media[j] >=7 ){
                printf("Aprovado\n");
            }

            else{
                printf("Reprovado\n");
            }
                       
        }
        printf("\n");
    }

    //printar alunos reprovados e a materia
    printf("Alunos reprovados:\n");
    for (i = 0; i < qtdaluno; i++){        
        for (j=0; j <qtdmateria; j++){
            if (aluno[i].materias.media[j] < 7){
                printf("%s reprovado em %s\n",aluno[i].nome,aluno->materias.materia[j]);
            }
        }
    }
    
    return 0;
}