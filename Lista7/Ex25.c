#include <stdio.h>

void mes(int X);

int main(){
    int X;
    scanf("%d", &X);
    mes(X);

    return 0;
}



void mes(int X){
    char retorno[20];
    switch (X){

    case 1:
    printf("janeiro");
        break;
    
    case 2:
    printf("fevereiro\n");
        break;

    case 3:
    printf("marco");
        break;

    case 4:
    printf("abril");
        break;

    case 5:
    printf("maio");
        break;

    case 6:
    printf("junho");
        break;

    case 7:
    printf("julho");
        break;

    case 8:
    printf("agosto");
        break;

    case 9:
    printf("setembro");
        break;

    case 10:
    printf("outubro");
        break;
    
    case 11:
    printf("novembro");
        break;

    case 12:
    printf("dezembro");
        break;

    default:
    printf("erro");
        break;
    }

}
