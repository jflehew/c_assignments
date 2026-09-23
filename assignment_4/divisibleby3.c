#include <stdlib.h>
#include <stdio.h>

void divisible_by_3(int upper, int lower);

void divisible_by_3(int upper, int lower){
    if(upper < lower){
        return;
    }
    if(upper % 3 == 0){
        printf("%d is divisible by 3", upper);
    }
    divisible_by_3(upper--, lower);
}

void set_upper_lower(int user_input_1, int user_input_2){
    int upper;
    int lower;
    if(user_input_1 == user_input_2){
        printf("-----Your numbers were the same-----");
        if(user_input_1 % 3 == 0){
            printf("your number %d is divisible by three", user_input_1);
            return;
        }else{
            printf("Your number %d is not divisible by 3\n", user_input_1);
            return;
        }
    }
    if(user_input_1 > user_input_2){
        upper = user_input_1;
        lower = user_input_2;
    }else{
        upper = user_input_2;
        lower = user_input_1;
    }
    divisible_by_3(upper, lower);
}

void user_int_input_funct(int * user_int_input_1, int * user_int_input_2){
    //char for user input
    char user_input[1000];
    // char for user input if user inputs too many variables
    char extra_input;
    // while loop that is always true
    while(1){
        printf("-----Please enter two integers-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %d %c", user_int_input_1, user_int_input_2, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 2){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

int main(){
    int user_int_input_1, user_int_input_2;
    user_int_input_funct(&user_int_input_1, &user_int_input_2);
    printf("-----you have completed your function-----");
    return 0;
}