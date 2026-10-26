#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int email_check(char *email){
    assert(email != NULL);
    int length = strlen(email);
    printf("%s\n", email);
    for (int i = 0; i < length; i++){
        if(i+1 == length){
        return -1;
        }
        if(email[i] == '@'){
            if(i==0){
                return -1;
            }
            if(email[i+1] == '.'){
                return -1;
            }
            for(int j = i+1; j < length; j++){
                if(j+1 == length){
                    return -1;
                }
                if(email[j] == '.'){
                    if(email[j] == '.' && j + 1 == length){
                        return -1;
                    }
                    for(int k = j+1; k < length; k++){
                        if(!isalnum(email[k])){
                            return -1;
                        }
                        if(k+1 == length){
                            return 0;
                        }
                    }
                }
                if(!isalnum(email[j])){
                    return -1;
                }
            }
        }
        if(!isalnum(email[i]) && email[i] != '.' && email[i] != '_' && email[i] != '-'){
            return -1;
        }
    }
    return 0;
}


int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Please enter a single email address\n");
        return -1;
    }
    int return_value;
    return_value = email_check(argv[1]);
    if(return_value == -1){
        printf("you did not enter a valid email address\n");
    }else{
        printf("Your email address is %s\n", argv[1]);
    }
    return return_value;
}