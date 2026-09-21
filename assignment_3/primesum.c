#include <stdio.h>
#include <stdlib.h>
// Declaring functions so they can be called whenever needed
void prime_sum_funct(int user_number_input, long long *prime_sum);
void user_number_input_funct(int * user_number_input);
int is_prime_number(int current_number);

//function to test if a number is prime
int is_prime_number(int current_number){
    // printf("current number is %d\n", current_number);
    //for loop that goes up to the sqrt of the current number
    for(int i = 2; i <= current_number/i; i++){
        // printf("you've entered your for loop i = %d\n", i);
        // printf("current_number/i = %d\n", current_number/i);
        // if number is divisible returns 0
        if (current_number % i == 0){
            return 0;
        }}
        //if number is prime returns 1
    return 1;

}

//function to add all prime numbers of user input
void prime_sum_funct(int user_number_input, long long *prime_sum){
    //allows sum to be a 64 bit integer
    //set sum to 2 which is the lowest prime sum
    long long sum = 2;
    //if user input is 2 send back their input as lowest prime sum
    if (user_number_input == 2){
        *prime_sum = sum;
        return;
    }
    //for loop that starts at 3 and iterates in incremints of 2, all even numbers don't need to be tested (they aren't prime)
    for(int i = 3; i <= user_number_input; i+=2){
        // printf("i is: %d\n", i);
        //checks if is_prime_number function is true then adds current number to sum if true
        if(is_prime_number(i)){
            // printf("i'm adding the sum\n");
            sum += i;
        }
        // printf("your sum should increment as is now: %d\n", sum);
    }
    // printf("final sum is: %d\n", sum);
    //sets address of prime_sum equal to sum after all numbers checked
    *prime_sum = sum;
}

//function that takes in an input from the command line from a user when prompted
void user_number_input_funct(int * user_number_input){
    //char for user input
    char user_input[1000];
    // char for user input if user inputs too many variables
    char extra_input;
    // while loop that is always true
    while(1){
        printf("-----Please enter a single integer greater than 1-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %c", user_number_input, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 1 && *user_number_input > 1){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

// main function runs the program
int main(){
    //declaration of the user input and the variable that will host our sum
    long long prime_sum = 0;
    int user_number_input;
    //calling the user input function to get users integer to test
    user_number_input_funct(&user_number_input);
    //calls the prime sum function to get the prime sum of users input
    prime_sum_funct(user_number_input, &prime_sum);
    printf("you entered: %d\nYour Prime Sum is: %lld\n", user_number_input, prime_sum);
    return 0;
}