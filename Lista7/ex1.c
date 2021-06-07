#include <stdio.h>

int p_nome();

int main(){
    p_nome(1);
    return 0;
}

int p_nome(){
    char name[30];
    printf("digite seu nomen");
    scanf(" %[^n]", name);
    printf("%s", name);
    return 0;
}