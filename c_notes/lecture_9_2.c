#include <stdio.h>
int main(){
    /**
     * ! Algorithm: a step-by-step procedure for solving a problem or performing a task.
     * ! graphs: general purpose tool for visualizing data structures and algorithms.
     * ! struct: a user-defined data type in C that allows grouping of variables of different types under a single name.
     * ! Pointer: a variable that stores the memory address of another variable.
     * ? in computers counting starts from 0, so the first element of an array is at index 0.
     * ! Array: a collection of elements of the same type stored in contiguous memory locations, accessible by an index.
     * ? 8 bits = 1 byte, which can contain the values (0 to 255) or 00000000 to 11111111 in binary.
     * ? 1 byte = 8 bits, which can represent 256 different values (from 0 to 255).
     * * 16 bits = 2 bytes, which can represent 65,536 different values (from 0 to 65,535).
     * * 32 bits = 4 bytes, which can represent 4,294,967,296 different values (from 0 to 4,294,967,295).
     * * 64 bits = 8 bytes, which can represent 18,446,744,073,709,551,616 different values (from 0 to 18,446,744,073,709,551,615).
     * * 64 bits is windows 64
     * * / = divide 
     * * * = multiply
     * * + = add
     * * - = subtract
     * ! segmentation fault: a specific kind of error caused by accessing memory that “does not belong to you.” It's a mechanism that prevents you from corrupting the memory and introducing hard-to-debug memory bugs.
     * 
     * */
    int x, y, z, w;
    // x = 2;
    y = 5;
    z = 10; 
    w = 3;
    int *p = &x; // pointer p is assigned the address of variable x
    int **q = &p; // pointer q is assigned the address of pointer p
    x = y + z - 3 * w; // x is assigned the value of y + z - 3 * w
    printf("the value of x is %d\n", x); // prints the value of variable x
    printf("the loaction of x is %p\n", (void*)&x); // prints the memory address of variable x
    *p = 20; // dereferencing pointer p to assign the value 20 to variable x
    printf("the value of x is %d\n", x); // prints the value of variable x
    **q = 30; // dereferencing pointer q to assign the value 30 to variable x
    printf("the value of x is %d\n", x); // prints the value of variable x
    printf("the loaction of x is %p\n", (void*)&x); // prints the memory address of variable x
    *p = *p + 10; // dereferencing pointer p to add 10 to the value of variable x
    printf("the value of x is %d\n", x); // prints the value of variable x

}