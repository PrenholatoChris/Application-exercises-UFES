#include <stdio.h>

#define quantidade 30
int main(){
    int i;
    int V1[quantidade],V2[quantidade],VR[quantidade];
    char operacao[2];

    for (i = 0; i < quantidade; i++){
        scanf("%d",&V1[i]);
    }
    

    for (i = 0; i < quantidade; i++){
        scanf("%d",&V2[i]);
    }

    scanf("%s", operacao);



    for(i = 0; i < quantidade; i++){
        if (operacao[0] == '+'){
            VR[i] = V1[i]+V2[i];
        }

        else if (operacao[0] == '-'){
            VR[i] = V1[i]-V2[i];
        }

        else if (operacao[0] == '*'){
            VR[i] = V1[i]*V2[i];
        }

        else if (operacao[0] == '/'){
            VR[i] = (float)V1[i]/V2[i];
        }

        printf("#%d - %d\n",i,VR[i]);
    }

    return 0;
}