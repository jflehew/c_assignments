#include <stdio.h>

int main(void) {
    int * p;
    int rc = scanf("%d", p);
    return rc != 1;
}
