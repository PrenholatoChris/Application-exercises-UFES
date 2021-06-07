#include <stdio.h>

int main(){
    int nota1,nota2,nota3,nota4;
    printf("Digite suas 4 notas\n");
    scanf("%d %d %d %d",nota1,nota2,nota3,nota4);
    float media = (nota1+nota2+nota3+nota4)/4;

        if (media>=7){
            printf("Aluno aprovado\n");
        }
        else{
            printf("Aluno reprovado\n");
        }

    return 0;
}
