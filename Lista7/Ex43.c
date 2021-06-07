/* 43. Faça uma função em C que realize a conversão de pés (feet) para metros (m), sendo que feet é
passado como parâmetro e m é retornado. Sabe-se que 1 metro está para 3,281 pés. Crie também um
programa para testar tal função. */


#include <stdio.h>

float pe_metro(float feet);

int main(){
    float metros, pes;
    printf("Digite a quantidade de pes a ser convetida para metros\n");
    scanf("%f", &pes);
    
    printf("%.2f metros\n", pe_metro(pes));

    return 0;
}




float pe_metro(float feet){
    float metro = (feet/3.281);
    return metro;
}