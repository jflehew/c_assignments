#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int fibonacci (int user_int_input, int * fibo_result);
void run_fibo(int user_int_input, int iterator, int * fibo_number, int prev_fib);

void run_fibo(int user_int_input, int iterator, int * fibo_number, int prev_fib){
    assert(fibo_number != NULL);
    int current_fib = *fibo_number;
    printf("fibbo number: %d\nprev fib: %d\niterator: %d\n", *fibo_number, prev_fib, iterator);
    if(iterator > user_int_input){
        return;
    }
    *fibo_number = *fibo_number + prev_fib;
    run_fibo(user_int_input, ++iterator, fibo_number, current_fib);
}

int fibonacci(int user_int_input, int *fibo_result){
    assert(fibo_result != NULL);
    if(user_int_input == 0){
        *fibo_result = 0;
        return 0;
    }
    int fibo_number = 1;
    int iterator = 2;
    run_fibo(user_int_input, iterator, &fibo_number, 0);
    *fibo_result = fibo_number;
    return 0;
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
        printf("-----Please enter a single integer greater than or equal to 0-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %c", user_int_input, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 1 && *user_int_input >= 0){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

int main(){
    int user_int_input;
    int fibo_result;
    user_int_input_funct(&user_int_input);
    fibonacci(user_int_input, &fibo_result);
    printf("The Fibonacci number for your number %d = %d", user_int_input, fibo_result);
    return 0;
}