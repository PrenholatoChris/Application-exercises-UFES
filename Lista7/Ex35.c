// n! / ( p! * (n-p)!)
#include <stdio.h>

int combinacao(int n, int p);
int fatorial(int x);

int main(){
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);

    printf("%d\n", combinacao( n, p));
    return 0;
}


int combinacao(int n, int p){
    int resposta;
    if (n < p){
        return -1;
    }
    
    resposta = fatorial(n)/ (fatorial(p) * fatorial(n-p));
    return resposta;
}



int fatorial(int x){
    int fat = 1;


    if (x != 1){
        fat =  x * fatorial(x-1);
    }
    

    return fat;
}

