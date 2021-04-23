#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Empresa contrata

#define qtd 10

typedef struct infos{
    int inscricao;
    int idade;
    char sexo[2];
    char experiencia[2];
}Candidato;



int main(){
    Candidato candidato[qtd];
    int contarm=0,contarh=0;
    int homens_exp=0;
    float idademediah=0;
    float porcent_homens_45=0;
    int mulheres_exp_35=0;
    int mulher_nova_exp;
    int i;

    //Ler informações
    for (i = 0; i < qtd; i++){        
        printf("Digite o numero de inscricao\n");
        scanf("%d", &candidato[i].inscricao);
        
        printf("Digite a idade\n");
        scanf("%d", &candidato[i].idade);
        
        printf("Qual o sexo? H ou M\n");
        scanf("%s", &candidato[i].sexo);
        candidato[i].sexo[0] = tolower(candidato[i].sexo[0]);

        printf("O candidatro tem experiencia? S ou N\n");
        scanf("%s", &candidato[i].experiencia);
        candidato[i].experiencia[0] = tolower(candidato[i].experiencia[0]);
    }

    //definir a idade de da primeira mulher com experiencia para achar a mais nova depois
    for (i = 0; i < qtd; i++){
        if ((strcmp(candidato[i].sexo, "m")==0) && (strcmp(candidato[i].experiencia, "s")==0)){
            mulher_nova_exp = candidato[i].idade;
            break;
        }
        else{
            mulher_nova_exp = 0;
        }
    }
    //Calculo
    for (i = 0; i < qtd; i++){
        //MULHERES
        if (strcmp(candidato[i].sexo, "m") == 0) {
            //calcular qtd de mulheres
            contarm++;

            if (strcmp(candidato[i].experiencia, "s")==0){
                //calcular mulher com +35 anos
                if (candidato[i].idade < 35){
                    mulheres_exp_35++;
                }
                
                //calcular mulher mais nova c experiencia
                if (mulher_nova_exp>candidato[i].idade){
                    
                    mulher_nova_exp = candidato[i].idade;
                }
            }
        }

        //HOMENS
        else if (strcmp(candidato[i].sexo, "h") == 0) {
            //calcular qtd de homens
            contarh++;
            
            //calcular media idade homens c experiencia
            if (strcmp(candidato[i].experiencia, "s") ==0){
                idademediah += candidato[i].idade;
                homens_exp++;            
            }
            
            //calcular porcentagem de homens com mais de 45 anos entre o total de homens
            if (candidato[i].idade > 45){
                porcent_homens_45++;    
            }
               
        }
    }
    idademediah = idademediah/homens_exp;
    porcent_homens_45 = (porcent_homens_45/contarh)*100;

    system("cls");
    printf("O numero de candidatos do sexo Feminino = %d\n",contarm);
    printf("O numero de candidatos do sexo Masculino = %d\n",contarh);
    printf("Idade media dos homens com experiencia no servico = %.1f\n",idademediah);
    printf("Porcentagem de homens com + de 45 anos, entre o total de homens = %.2f%%\n",porcent_homens_45);
    printf("Quatidade de mulheres mais novas que 35 anos com experiencia = %d\n",mulheres_exp_35);
    printf("A mulher mais nova com experiencia tem %d anos\n",mulher_nova_exp);

    return 0;
}
