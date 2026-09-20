#include <stdio.h>
#include <stdlib.h>
void for_factorial (int user_int_input, long long * factorial);

void for_factorial (int user_int_input, long long * factorial){
    long long factorial_multiple = 1;
    for(int i = 1; i  <= user_int_input; i++){
        factorial_multiple *= i;
    }
    *factorial = factorial_multiple;
}
//function that takes in an input from the command line from a user when prompted
void user_int_input_funct(int * user_int_input){
    //char for user input
    char user_input[1000];
    // char for user input if user inputs too many variables
    char extra_input;
    // while loop that is always true
    while(1){
        printf("-----Please enter a single integer between 1 and 20-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %c", user_int_input, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 1 && *user_int_input > 1 && *user_int_input < 21){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

int main(){
    int user_int_input;
    long long factorial = 0;
    user_int_input_funct(&user_int_input);
    for_factorial(user_int_input, &factorial);
    printf("your number is: %d\nIts factorial is: %lld", user_int_input, factorial);
    return 0;
}