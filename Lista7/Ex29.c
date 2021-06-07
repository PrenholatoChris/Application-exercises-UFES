#include <stdio.h>

int divisivel(int x, int y);

int main(){
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    
    printf("%d\n", divisivel(x,y));
}


int divisivel(int x, int y){
    if (x % y == 0){
        return 1;
    }
    return 0;
}