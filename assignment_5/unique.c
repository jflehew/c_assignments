#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int unique(int test_array[], int length, int * unique_integers){
    assert(length > 0);
    assert(length < 100);
    assert(unique_integers != NULL);
    assert(test_array != NULL);
    *unique_integers = 0;
    for(int i = 0; i < length; i++){
        int int_exists = 0;
        for(int j = 0; j < i; j++){
            if(test_array[i] == test_array[j]){
                int_exists = 1;
                break;
            }

        }
        if(!int_exists){
            (*unique_integers)++;
        }
    }
    return 0;
}

int main( ){
    int unique_integers;

    int test_zero[] = {1,2,4,2,1,-1};
    unique(test_zero, sizeof(test_zero) / sizeof(test_zero[0]), &unique_integers);
    assert(unique_integers == 4);

    int test_one[] = {1};
    unique(test_one, sizeof(test_one) / sizeof(test_one[0]), &unique_integers);
    assert(unique_integers == 1);

    int test_two[] = {1, 2, 3, 4, 5};
    unique(test_two, sizeof(test_two) / sizeof(test_two[0]), &unique_integers);
    assert(unique_integers == 5);

    int test_three[] = {7, 7, 7, 7, 7};
    unique(test_three, sizeof(test_three) / sizeof(test_three[0]), &unique_integers);
    assert(unique_integers == 1);

    int test_four[] = {-1, -2, -3, -1, -2};
    unique(test_four, sizeof(test_four) / sizeof(test_four[0]), &unique_integers);
    assert(unique_integers == 3);

    int test_five[] = {0, 0, 0, 1, 2, 3};
    unique(test_five, sizeof(test_five) / sizeof(test_five[0]), &unique_integers);
    assert(unique_integers == 4);

    int test_six[] = {1, 2, 1, 2, 1, 2};
    unique(test_six, sizeof(test_six) / sizeof(test_six[0]), &unique_integers);
    assert(unique_integers == 2);

    int test_seven[] = {10, -10, 10, -10, 0};
    unique(test_seven, sizeof(test_seven) / sizeof(test_seven[0]), &unique_integers);
    assert(unique_integers == 3);

    int test_eight[] = {5, 4, 3, 2, 1, 5, 4, 3, 2, 1};
    unique(test_eight, sizeof(test_eight) / sizeof(test_eight[0]), &unique_integers);
    assert(unique_integers == 5);

    int test_nine[] = {100, 200, 300, 100, 400, 200, 500};
    unique(test_nine, sizeof(test_nine) / sizeof(test_nine[0]), &unique_integers);
    assert(unique_integers == 5);

    return 0; 
}