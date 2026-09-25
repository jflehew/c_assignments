#include <stdio.h>
#include <stdlib.h>

/*horners method
\0 is char for null in a string
*/

void int_to_string(int n){
    int r, q;
    while(n>0){
        r = n % 10;
        q = n / 10;
        printf("Digit: %c\n", r + '0');
        putchar(r+'0'); 
        n = q;
    }
}

int reverse();

int main(int argc, char *argv[]){
    int i = 0;
    char *p;
    p = &argv[1][0];
    while (*p != '\0'){
        printf("I got %c", *p);
        if(*p >= '0' && *p <= '9'){
            i = i *10 + (*p - '0');
        }else{
            break;
        }
        p++;
    }
}