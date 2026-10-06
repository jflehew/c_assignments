#include <stdio.h>
#include <stdlib.h>

int f(int x, int y){
    if(x == 0) return 0;
    printf("x: %d, y: %d\n", x, y);
    return y + f(x-1, y);
}

int main(){
    int z;
    z = f(5, 5);
    printf("z: %d", z);
    return 0;
}