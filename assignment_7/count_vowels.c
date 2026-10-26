#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int count_vowels(char *test_string, int *a_count, int *e_count, int *i_count, int *o_count, int *u_count){
    assert(test_string != NULL);
    assert(a_count != NULL);
    assert(e_count != NULL);
    assert(i_count != NULL);
    assert(o_count != NULL);
    assert(u_count != NULL);
    int length = strlen(test_string);
for(int i = 0; i < length; i++){
    switch(tolower(test_string[i])){
        case 'a':
            ++*a_count;
            break;
        case 'e':
            ++*e_count;
            break;
        case 'i':
            ++*i_count;
            break;
        case 'o':
            ++*o_count;
            break;
        case 'u':
            ++*u_count;
            break;
        default:
            break;
    }
}
    return 0;
}

int main(){
    char test_string[10000];
    if(fgets(test_string, sizeof(test_string), stdin) == NULL){
        printf("Please enter any input\n");
        return -1;
    }
    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;
    assert(count_vowels(test_string, &a_count, &e_count, &i_count, &o_count, &u_count) == 0);
    printf("your string is: %s\nit has: %d a's\nit has: %d e's\nit has: %d i's\nit has: %d o's\nit has: %d u's\n", test_string, a_count, e_count, i_count, o_count, u_count);
    return 0;
}