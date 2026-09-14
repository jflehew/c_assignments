#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//function that takes in the address of an negative integer and modifies that integer to be positive
void calc_abs_value(int* negative_int){
    //turns an intger positive
    *negative_int = *negative_int * -1;
}

//function that takes in two integers and determines which has the smaller absolute value
int smaller_abs_val(int x, int y){
    //creates a variable which will be returned
    int smaller;
    //if x is negative get it's absolute value
    if(x < 0){
        calc_abs_value(&x);
    }
    //if y is negative get it's absolute value
    if(y < 0){
        calc_abs_value(&y);
    }
    //print the abs value of integers
    printf("-----The Absolute Values of your intgers are x = %d and y = %d\n", x, y);
    //if x is smaller set variable to x
    if(x < y){
        smaller = x;
    }
    //if y is smaller do the same
    if(x > y){
        smaller = y;
    }
    //edge case if they are equal set smaller
    if(x == y){
        printf("-----the absolute value of your integers are equal-----\n");
        smaller = x;
    }
    //return the smaller of the two variables
    return smaller;
}

//function that allows a user to enter two seperate variables and modifiy those variables at their address
void scan_int(int*x, int*y){
    //creates a char that a user can input into
    char user_input[1000];
    char extra_input;
    //a loop that keeps a user entering integers until they meet the programs criterai
    while(1){
        //tells the user what to do
        printf("-----Please Enter two integers seperated by a space-----\n");
        // takes in the users input
        fgets(user_input, sizeof(user_input), stdin);
        // creates an int and sets it to the number of arguments a user gave and verifies those arguments are ints
        int number_of_ints = sscanf(user_input, "%d %d %c", x, y, &extra_input);
        // verifies the user only had 2 inputs
        if(number_of_ints == 2){
            //ends loop if input is correct
            return;
        }
        //informs user they did not enter the correct information
        printf("-----You did not enter the correct number of integers-----\n");

    }
}

//main function
int main(){
    // initialize two variables to test
    int x, y;
    //call function to have user set variables
    scan_int(&x, &y);
    // initialze variable to set smallest abs to  and calls function to find that number
    int smallest_abs = smaller_abs_val(x, y);
    //informs user of smallest abs value
    printf("the integers you entered were:\n x = %d\n y = %d\n The smaller absolute value is %d", x, y, smallest_abs);
    return 0;
}
