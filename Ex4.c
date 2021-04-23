#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtd 4

//Estruta que cada obra tem
typedef struct{
    int codigo;
    char nome_obra[30];
    char nome_autor[30];
    int procedencia;
    char editora[30];
    int numero_de_paginas;
    char palavras_chaves[3][30];
    char assunto[30]; // exatas - biomedicas - humanas 
}Biblioteca;

int main(){
    
    Biblioteca obra[qtd];
    int i, j, escolha=0;
    int search_cod;
    char search_all[30];

    for (i = 0; i < qtd; i++){
        printf("Digite o codigo da obra\n");
        scanf("%d", &obra[i].codigo);
        
        printf("Digite o nome da obra\n");
        scanf(" %[^\n]", obra[i].nome_obra);

        printf("Digite o nome do autor\n");
        scanf(" %[^\n]", obra[i].nome_autor);

        printf("Digite o nome da editora\n");
        scanf(" %[^\n]", obra[i].editora);

        printf("Digite a quantidade de paginas\n");
        scanf("%d", &obra[i].numero_de_paginas);

        printf("Digite 3 palavras chaves para buscar pela obra depois\n");
        for (j = 0; j < 3; j++){
            scanf("%s", obra[i].palavras_chaves[j]);
        }
        
        printf("Digite qual e o assunto\n");
        printf("exatas | biomedicas | humanas\n");
        scanf("%s", obra[i].assunto);
        
        printf("Digite a procedencia\n");
        printf("1 - Comprado\n");
        printf("2 - Doado\n");
        scanf("%d", &obra[i].procedencia);
    }
    
    while (escolha != 3){
        system("cls");
        printf("O que deseja fazer?\n");
        printf("1 - Pesquisa por codigo\n");
        printf("2 - Pesquisa Generica\n");
        printf("3 - Encerrar o programa\n");
        scanf("%d", &escolha);
        

        switch (escolha){
        case 1:
            system("cls");
            printf("Digite o codigo a ser procurado\n");
            scanf("%d", &search_cod);
            for (i = 0; i < qtd; i++){
                int encontrado = 0;
                if ( search_cod == obra[i].codigo){
                    encontrado = 1;
                    printf("Obra guardada na posicao de vetor: %d\n",i);
                    printf("Obra: %s\n", obra[i].nome_obra);
                    printf("Assunto: %s\n", obra[i].assunto);  
                    printf("Autor: %s\n", obra[i].nome_autor);
                    printf("Editora: %s\n", obra[i].editora);
                    printf("Numero de pgs: %d\n", obra[i].numero_de_paginas);
                    printf("Palavras chaves:");
                    for (j = 0; j < 3; j++){
                        printf(" %s", obra[i].palavras_chaves[j]);
                    }
                    printf("\n");

                    if (obra[i].procedencia == 1){
                        printf("Livro Comprado\n");
                    }
                    else{
                        printf("Livro Doado\n");
                    }
                    break;
                }
                
            }
            system("PAUSE");
            break;

        case 2:
            system("cls");
            printf("Digite uma palavra a ser pesquisada\n");
            scanf(" %[^\n]", search_all);

            int encontrado = 0;
            for (i = 0; i < qtd; i++){
                if (0 == strcmp(search_all, obra[i].nome_obra)){
                    printf("Voce pesquisou por nome da obra\n");
                    encontrado = 1;
                }

                else if (0 == strcmp(search_all, obra[i].nome_autor)){
                    printf("Voce pesquisou por nome de autor\n");
                    encontrado = 1;                    
                }
                
                else if (0 == strcmp(search_all, obra[i].editora)){
                    printf("Voce pesquisou pela editora\n");
                    encontrado = 1;
                }


                else if (0 == strcmp(search_all, obra[i].assunto)){
                    printf("Voce pesquisou pelo assunto\n");
                    //PRINTAR SOMENTE CODIGO - NOME
                    encontrado = 1;
                }
                

                for (j = 0; j < 3; j++){     
                    if (0 == strcmp(search_all, obra[i].palavras_chaves[j])){
                        printf("Voce pesquisou por palavras chaves\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 1){
                    printf("Obra: %s\n", obra[i].nome_obra);
                    printf("Assunto: %s\n", obra[i].assunto);  
                    printf("Autor: %s\n", obra[i].nome_autor);
                    printf("Editora: %s\n", obra[i].editora);
                    printf("Numero de pgs: %d\n", obra[i].numero_de_paginas);
                    printf("Palavras chaves:");
                    for (j = 0; j < 3; j++){
                        printf(" %s", obra[i].palavras_chaves[j]);
                    }
                    printf("\n");

                    if (obra[i].procedencia == 1){
                        printf("Livro Comprado\n");
                    }
                    else{
                        printf("Livro Doado\n");
                    }
                    //ADICIONAR PRINT DA PROCEDENCIA
                    encontrado = 0;
                }
            }

            system("PAUSE");            
            break;       

        default:
            break;
        }
    }
    printf("Obrigado por utilizar meu programa\n");
    printf("Made by Christian Prenholato\n");
    return 0;
}