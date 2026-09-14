#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
// function to determine if something is a multiple of 3
int multiple_of_3(int n){
    //if statement tests to see if there is a remainder after dividing the number by 3
    if(n % 3 != 0){
        //returns 0 if remainder exists
        return 0;
    }else{
        //returns 1 if remainder = 0
        return 1;
    }
}

//function to take in a user input to test
int scan_int(){
    int user_int;
    int test_user_input;
    while(1){
        printf("-----Please enter an integer-----\n");
        test_user_input = scanf("%d", &user_int);
        if(test_user_input == 1){
            return user_int;
        }
        printf("-----You did not enter an integer-----\n");
        while(getchar() != '\n'){
        }
    }
}
//main function
int main(){
    //calls scan_int funct and sets it's value to this int
    int divisible_by_3 = scan_int();
    printf("You're number is %d\n", divisible_by_3);
    //creates variable to know whether what was returned was true or false and calls multiple of 3 function
    int multiple_of_3_test = multiple_of_3(divisible_by_3);
    //if statements to determine if what you got back was true or false
    if(multiple_of_3_test == 0){
        printf("Your number is not divisible by 3");
    }else{
        printf("Your number is divisible by 3");
    }
    return 0;
}