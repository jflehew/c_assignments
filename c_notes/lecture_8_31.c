#include <stdio.h> //* This includes the library stdio.h which is used for input and output operations in C.
int main() { //* This is the main function where the program execution starts.
    for (int i = 7; i >= 0; i--){
        if(i == 0){
            printf("You've reached the end of the loop! i = %d\n", i); //* This line prints a message when 'i' reaches 0.
        } else{
            printf("You're not quite there yet! i = %d\n", i); //* This line prints a message when 'i' is not 0.
        }
    }
    return 0;
}