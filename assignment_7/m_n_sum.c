#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

int m_n_sum(int *m, int *n, int *result){
    int placeholder = 0;
    assert (m != NULL);
    assert (n != NULL);
    assert (result != NULL);
    if(*m > *n){
        placeholder = *m;
        *m = *n;
        *n = placeholder;
    }
    *result = *m;
    for(int i = *m+1; i <= *n; i++){
        *result += i; 
    }
    return 0;
}

int main(int argc, char * argv[3]){
    if(argc != 3){
        printf("Please enter two integers\n");
        return -1;
    }
    int m = 0;
    int n = 0;
    if(sscanf(argv[1], "%d", &m) == 0 || sscanf(argv [2], "%d", &n) == 0){
        printf("Both inputs must be integers\n");
        return -1;
    }
    if(m <= 0 || n <= 0){
        printf("Both integers must be posiitve\n");
        return -1;
    }
    int result = 0;
    assert(m_n_sum(&m, &n, &result) == 0);
    printf("the numbers you enered are: (%d, %d)\ntheir m_n_sum is: %d\n", m, n, result);
    return 0;
}