#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int reverse(int user_input, int * reversed_user_input){
    int remainder, quotient;
    if(user_input > 0){
        remainder = user_input % 10;
        quotient = user_input / 10;
        *reversed_user_input = (*reversed_user_input*10) + remainder;
        reverse(quotient, reversed_user_input);
    }
    // while(n>0){
    //     r = n % 10;
    //     q = n / 10;
    //     printf("%c\n", r + '0');
    //     putchar(r+'0'); 
    //     n = q;
    // }
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

int main (){
    int user_int_input;
    int reversed_user_input = 0;
    user_int_input_funct(&user_int_input);
    reverse(user_int_input, &reversed_user_input);
    printf("\nyour input reversed is: %d", reversed_user_input);
}

/*horners method
\0 is char for null in a string
*/

// void int_to_string(int n){
//     int r, q;
//     while(n>0){
//         r = n % 10;
//         q = n / 10;
//         printf("%c\n", r + '0');
//         putchar(r+'0'); 
//         n = q;
//     }
// }

// int main(int argc, char *argv[]){
    //     int i = 0;
    //     char *p;
    //     p = &argv[1][0];
    //     while (*p != '\0'){
        //         printf("I got %c\n", *p);
        //         if(*p >= '0' && *p <= '9'){
            //             i = i *10 + (*p - '0');
            //         }else{
                //             break;
                //         }
                //         p++;
                //     }
                //     int_to_string(12345);
                // }
                