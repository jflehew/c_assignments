#include <stdio.h>

void f(int * q, int **p , int *i){
    *q = *q * 5;
    *p = i;
    printf("the value of *q = %d\n", *q);
    printf("the value of i = %d\n", i);
}

int main(){
    int j, i = 3;
    int *p = &i;
    int **q = &p;
    f(p, q, &j);
    *p = i + 1;
    printf("-----You are not out of the function-----\n");
    printf("the value of j = %d\n", j);
    printf("the address of j = %d\n", &j);
    printf("the value of i = %d\n", i);
    printf("the value of p = %d\n", p);
    printf("the value of q = %d\n", q);
    return 0;

}
    
