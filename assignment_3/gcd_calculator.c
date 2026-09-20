#include <stdio.h>
void gcd_calculator(int user_int_input_1, int user_int_input_2, int * gcd);

//function to test gcd
void gcd_calculator(int user_int_input_1, int user_int_input_2, int * gcd){
    //find smaller int
    int smaller_int;
    if(user_int_input_1 <= user_int_input_2){
        smaller_int = user_int_input_1;
    }else{
        smaller_int = user_int_input_2;
    }
    //loop backwards through smaller int
    for(int i = smaller_int; i >= 1; i--){
        //if common denominator set gcd and return
        if(user_int_input_1 % i == 0 && user_int_input_2 % i == 0){
            *gcd = i;
            return;
        }
    }
}

/*
Euclids Algorithm: (this would be more efficient for the future)
void gcd_calc(int user_int_input_1, int user_int_input_2, int * gcd){
    while(user_int_input_2 != 0){
        int remainder = user_int_input_1 % user_int_input_2;
        user_int_input_1 = user_int_input_2;
        user_int_input_2 = remainder;
    }
    *gcd = user_int_input_1;
}
*/

void user_int_input_funct(int * user_int_input_1, int * user_int_input_2){
    //char for user input
    char user_input[1000];
    // char for user input if user inputs too many variables
    char extra_input;
    // while loop that is always true
    while(1){
        printf("-----Please enter two integers greater than 1-----\n");
        //gets user input and puts that input into stdin
        fgets(user_input, sizeof(user_input), stdin);
        // scans user input and counts how many integers are in the input and writes those values into the neccesarry variables
        int number_of_input_ints = sscanf(user_input, "%d %d %c", user_int_input_1, user_int_input_2, &extra_input);
        // if user only entered one integer and no other inputs return to main function
        if (number_of_input_ints == 2 && *user_int_input_1 > 1 && *user_int_input_2 > 1){
            return;
        }
        // user entered too many inputs prompt user to enter integers again
        printf("-----Your input is not valid-----\n");
    }
}

int main (){
    int user_int_input_1, user_int_input_2;
    int gcd = 1;
    user_int_input_funct(&user_int_input_1, &user_int_input_2);
    gcd_calculator(user_int_input_1, user_int_input_2, &gcd);
    printf("Your values were %d and %d\ntheir Greatest Common Divisor is: %d", user_int_input_1, user_int_input_2, gcd);
    return 0;
}