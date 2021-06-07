#include <stdio.h>

int arranjo(int n, int p);
int fatorial(int x);
int main(){
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    printf("%d\n", arranjo( n, p));
    return 0;
}


int arranjo(int n, int p){
    int resposta;
    resposta = fatorial(n) / fatorial(n-p);
    return resposta;
}


int fatorial(int x){
    int fat = 1;

    if (x != 1){
        fat =  x * fatorial(x-1);
    }
    
    return fat;
}