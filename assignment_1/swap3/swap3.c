// * include the library stdio.h, stdlib.h and assert.h
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// * initilize the function swap3 whose arguments are the addresses of your values in main
void swap3(int *address_a,
           int *address_b,
           int *address_c)
{
    // * protecting you funciton in case of a Null value
    assert(address_a != NULL && address_b != NULL && address_c != NULL);
    // * print to ensure you are in the swap3 function
    printf(
        "-----you have entered the function swap3-----\n");
    // * check that you values were properly sent to the fuction
    printf("The value of a = %d as taken from the pointer address_a\n", *address_a);
    printf("The value of b = %d as taken from the pointer address_b\n", *address_b);
    printf("The value of c = %d as taken from the pointer address_c\n", *address_c);
    // * initilize and set a place holder value
    int swap3_a = *address_a;
    // * move each value up one space for the swap so that a = c. b = a and c = b
    *address_a = *address_c;
    *address_c = *address_b;
    *address_b = swap3_a;
    // * void function so no return
}

int main()
{
    // * initialize and set three variables
    int a = 0;
    int b = 1;
    int c = 2;
    // * print value of variables to check everything is dones correctly
    printf("the value of a = %d\n", a);
    printf("the value of b = %d\n", b);
    printf("the value of c = %d\n", c);
    // * call function swap3 by sending the address of the original variables
    swap3(&a, &b, &c);
    // * check that you have properly left the function
    printf("-----You have left the fuction swap3-----\n");
    // * check that the values of the funciton are what you expected
    printf("the new value of a = %d\n", a);
    printf("the new value of b = %d\n", b);
    printf("the new value of c = %d\n", c);
    return 0;
}