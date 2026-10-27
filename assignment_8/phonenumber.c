#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int test_phone_number(char * phone_number){
    assert(phone_number != NULL);
    int length = strlen(phone_number);
    if(phone_number[0] == '('){
        if (length != 14 || phone_number[4] != ')' || phone_number[5] != ' ' || phone_number[9] != '-'){
            // printf("I failed on line 16\n");
            return -1;
        }
        for(int i = 1; i < length; i++){
            // printf("I'm in loop iteration: %d my char is: %c\n", i, phone_number[i]);
            if(i == 4 || i == 5 || i == 9){
                continue;
            }
            if(!isdigit(phone_number[i])){
                // printf("I failed on line 24\n");
                return -1;
            }
        }
    }else if(isdigit(phone_number[0])){
        if(length != 12 || phone_number[3] != '-' || phone_number[7] != '-'){
            // printf("I failed on line 30\n");
            return -1;
        }
        for(int i = 1; i < length; i++){
            // printf("I'm in loop iteration: %d my char is: %c\n", i, phone_number[i]);
            if(i == 3 || i == 7){
                continue;
            }
            if(!isdigit(phone_number[i])){
                // printf("I failed on line 38\n");
                return -1;
            }
        }
    }else{
        // printf("I failed on line 43\n");
        return -1;
    }
    return 0;
}

int main(){
    int return_value;
    char test_string[20];
    if(fgets(test_string, sizeof(test_string), stdin) == NULL){
        printf("Please enter a valid phone number");
        return -1;
    }
    test_string[strcspn(test_string, "\n")] = '\0';
    return_value = test_phone_number(test_string);
    if(return_value == -1){
        printf("You did not enter a phone number in the correct format\nCorrect format:\n1. (XXX) XXX-XXXX\n2.   XXX-XXX-XXXX\n");
        // printf("String Length: %lld\n", strlen(test_string));
    }else{
        printf("Your phone number is %s\n", test_string);
    }
    return return_value;
}