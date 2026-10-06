#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int minmax(int test_array[], int length, int * min, int * max){
    assert(test_array != NULL);
    assert(length > 0);
    assert(min != NULL);
    assert(max != NULL);
    *min = test_array[0];
    *max = test_array[0];
    for(int i = 1; i < length; i++){
        if(test_array[i] < *min){
            *min = test_array[i];
        }
        if(test_array[i] > *max){
            *max = test_array[i];
        }
    }
    return 0;
}

int main(){
    int min = 0;
    int max = 0;

    int test_zero[] = {0, 1, 2, 3, 4, 5, 6};
    minmax(test_zero, sizeof(test_zero) / sizeof(test_zero[0]), &min, &max);
    assert(min == 0 && max == 6);

    int test_one[] = {5};
    minmax(test_one, sizeof(test_one) / sizeof(test_one[0]), &min, &max);
    assert(min == 5 && max == 5);

    int test_two[] = {6, 5, 4, 3, 2, 1, 0};
    minmax(test_two, sizeof(test_two) / sizeof(test_two[0]), &min, &max);
    assert(min == 0 && max == 6);

    int test_three[] = {-1, -2, -3, -4, -5};
    minmax(test_three, sizeof(test_three) / sizeof(test_three[0]), &min, &max);
    assert(min == -5 && max == -1);

    int test_four[] = {-10, 0, 10};
    minmax(test_four, sizeof(test_four) / sizeof(test_four[0]), &min, &max);
    assert(min == -10 && max == 10);

    int test_five[] = {7, 7, 7, 7, 7};
    minmax(test_five, sizeof(test_five) / sizeof(test_five[0]), &min, &max);
    assert(min == 7 && max == 7);

    int test_six[] = {100, 50, 200, 25, 300};
    minmax(test_six, sizeof(test_six) / sizeof(test_six[0]), &min, &max);
    assert(min == 25 && max == 300);

    int test_seven[] = {-100, 50, -25, 75, 0};
    minmax(test_seven, sizeof(test_seven) / sizeof(test_seven[0]), &min, &max);
    assert(min == -100 && max == 75);

    int test_eight[] = {3, 1, 4, 1, 5, 9, 2, 6};
    minmax(test_eight, sizeof(test_eight) / sizeof(test_eight[0]), &min, &max);
    assert(min == 1 && max == 9);

    int test_nine[] = {42, -7, 18, 999, -250, 0};
    minmax(test_nine, sizeof(test_nine) / sizeof(test_nine[0]), &min, &max);
    assert(min == -250 && max == 999);
}