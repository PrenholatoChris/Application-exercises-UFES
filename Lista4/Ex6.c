#include <stdio.h>
#include <string.h>
#define questoes 10

int main(){
    int i,nota=0,media;
    char resposta[10][30], gabarito[10][30];
    printf("Gabarito\n");
    for (i = 0; i < 10; i++){
        scanf("%s",&gabarito[i]);
    }

    printf("Resposta do aluno\n");
    for (i = 0; i < questoes; i++){      
        scanf("%s",&resposta[i]);
        printf("%s - %s\n",resposta[i],gabarito[i]);
        if (strcmp(resposta[i], gabarito[i])==0){
            nota ++;
        }
        
    }

printf("nota = %d\n",nota);
    media = questoes*0.7;
    if (nota>=media){
        printf("Aluno Aprovado\n");
    }
    else{
        printf("Aluno reprovado\n");
    }

    return 0;
}