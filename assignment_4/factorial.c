#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void find_factorial (int user_int_input, long long * factorial);



void find_factorial (int user_int_input, long long * factorial){
    assert(factorial != NULL);
    if (user_int_input == 0){
        return;
    }
    printf("user input is %d\nfactorial = %lld\n", user_int_input, *factorial);
    *factorial = *factorial * (user_int_input);
    user_int_input-=1;
    // printf("user input is %d\n ", user_int_input);
    find_factorial(user_int_input, factorial);
}



//function that takes in an input from the command line from a user when prompted
void user_int_input_funct(int * user_int_input){
    assert(user_int_input != NULL);
    //char for user input
    char user_input[1000];
    // char for user input if user inputs too many variables
    char extra_input;
    // while loop that is always true
    while(1){
        //input 21 is too big for long long
        printf("-----Please enter a single integer greater than or equal to 0 and less than or equal to 20-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %c", user_int_input, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 1 && *user_int_input >= 0 && *user_int_input <= 20){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

int main () {
    int user_int_input;
    long long factorial = 1;
    user_int_input_funct(&user_int_input);
    find_factorial(user_int_input, &factorial);
    printf("the factorial of your number: %d = %lld", user_int_input, factorial);
    return 0;
}
