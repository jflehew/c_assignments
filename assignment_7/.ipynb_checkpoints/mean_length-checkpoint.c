#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int mean_length_funct(char *test_string, float *mean_length){
    assert(test_string != NULL);
    assert(mean_length != NULL);
    int char_count = 0;
    int word_count = 0;
    int total_chars = 0;
    int length = strlen(test_string);
    for(int i = 0; i < length; i++){
        if(isspace(test_string[i])){
            if(char_count != 0){
                total_chars += char_count;
                word_count++;
                char_count = 0;
            }
        }else{
            char_count++;
        }
    }
    if(char_count != 0){
        total_chars += char_count;
        word_count++;
    }
    if(word_count == 0){
        printf("no words were entered");
        return -1;
    }
    *mean_length = (float)total_chars/word_count;
    return 0;
}

int main(){
    char test_string[10000];
    if(fgets(test_string, sizeof(test_string), stdin) == NULL){
        printf("Please enter any input\n");
        return -1;
    }
    float mean_length = 0;
    assert(mean_length_funct(test_string, &mean_length) == 0);
    printf("your string is: %s\nits mean length is: %f\n", test_string, mean_length);
    return 0;
}