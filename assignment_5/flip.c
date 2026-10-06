#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int print_and_test_arrays(int input_array[], int output_array[], int length);

int flip(int input_array[], int output_array[], int length){
    assert(length <= 100);
    assert(input_array != NULL);
    assert(output_array != NULL);
    for(int i = length - 1, j = 0; i >= 0; i--, j++){
        output_array[j] = input_array[i];
    }
    // printf("i'm about to test my array\n");
    assert(print_and_test_arrays(input_array, output_array, length) == 0);
    return 0;
};

int print_and_test_arrays(int input_array[], int output_array[], int length){
    assert(input_array != NULL);
    assert(output_array != NULL);
    assert(length <= 100);
    printf("I am testing my array's\n");
    for(int i = length - 1, j = 0; i >= 0; i--, j++){
        // printf("I am in the for loop testing my arrays\n");
        assert(input_array[i] == output_array [j]);
    }
    for(int i = 0; i < length; i++){
        printf("%d ", input_array[i]);
    }
    printf("\n");
    for(int i = 0; i < length; i++){
        printf("%d ", output_array[i]);
    }
    printf("\n");
    return 0;
}

int main(){
    int flip_array[100];
    int length = 0;

    int test_zero[] = {0, 1, 2, 3, 4, 5, 6};
    length = sizeof(test_zero) / sizeof(test_zero[0]);
    assert(flip(test_zero, flip_array, length) == 0);

    int test_one[] = {1};
    length = sizeof(test_one) / sizeof(test_one[0]);
    assert(flip(test_one, flip_array, length) == 0);

    int test_two[] = {1, 2};
    length = sizeof(test_two) / sizeof(test_two[0]);
    assert(flip(test_two, flip_array, length) == 0);

    int test_three[] = {5, 4, 3, 2, 1};
    length = sizeof(test_three) / sizeof(test_three[0]);
    assert(flip(test_three, flip_array, length) == 0);

    int test_four[] = {-1, -2, -3, -4};
    length = sizeof(test_four) / sizeof(test_four[0]);
    assert(flip(test_four, flip_array, length) == 0);

    int test_five[] = {10, 0, 20, 0, 30};
    length = sizeof(test_five) / sizeof(test_five[0]);
    assert(flip(test_five, flip_array, length) == 0);

    int test_six[] = {7, 7, 7, 7, 7};
    length = sizeof(test_six) / sizeof(test_six[0]);
    assert(flip(test_six, flip_array, length) == 0);

    int test_seven[] = {100, 200, 300, 400, 500, 600};
    length = sizeof(test_seven) / sizeof(test_seven[0]);
    assert(flip(test_seven, flip_array, length) == 0);

    int test_eight[] = {-10, 20, -30, 40, -50, 60};
    length = sizeof(test_eight) / sizeof(test_eight[0]);
    assert(flip(test_eight, flip_array, length) == 0);

    int test_nine[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    length = sizeof(test_nine) / sizeof(test_nine[0]);
    assert(flip(test_nine, flip_array, length) == 0);

    return 0;
}