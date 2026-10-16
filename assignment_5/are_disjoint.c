#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int are_disjoint(int *array_x, int *array_y, int length_x, int length_y ){
    for (int i = 0; i < length_x; i++){
        for(int j = 0; j < length_y; j++){
            if (array_x[i] == array_y[j]){
                return 0;
            }
        }
    }
    return 1;
}

int main () {

    int test_zero_x[] = {1, 2, 3};
    int test_zero_y[] = {4, 5, 6};
    assert(are_disjoint(
        test_zero_x, 
        test_zero_y, 
        sizeof(test_zero_x) / sizeof(test_zero_x[0]),
        sizeof(test_zero_y) / sizeof(test_zero_y[0])
    ) == 1);

    int test_one_x[] = {1, 2, 3};
    int test_one_y[] = {1, 4, 5};
    assert(are_disjoint(
        test_one_x,
        test_one_y,
        sizeof(test_one_x) / sizeof(test_one_x[0]),
        sizeof(test_one_y) / sizeof(test_one_y[0])
    ) == 0);

    int test_two_x[] = {10, 20, 30};
    int test_two_y[] = {5, 20, 40};
    assert(are_disjoint(
        test_two_x,
        test_two_y,
        sizeof(test_two_x) / sizeof(test_two_x[0]),
        sizeof(test_two_y) / sizeof(test_two_y[0])
    ) == 0);

    int test_three_x[] = {7, 8, 9};
    int test_three_y[] = {10, 11, 9};
    assert(are_disjoint(
        test_three_x,
        test_three_y,
        sizeof(test_three_x) / sizeof(test_three_x[0]),
        sizeof(test_three_y) / sizeof(test_three_y[0])
    ) == 0);

    int test_four_x[] = {-1, -2, -3};
    int test_four_y[] = {-4, -5, -6};
    assert(are_disjoint(
        test_four_x,
        test_four_y,
        sizeof(test_four_x) / sizeof(test_four_x[0]),
        sizeof(test_four_y) / sizeof(test_four_y[0])
    ) == 1);

    int test_five_x[] = {-10, -20, -30};
    int test_five_y[] = {5, -30, 15};
    assert(are_disjoint(
        test_five_x,
        test_five_y,
        sizeof(test_five_x) / sizeof(test_five_x[0]),
        sizeof(test_five_y) / sizeof(test_five_y[0])
    ) == 0);

    int test_six_x[] = {1};
    int test_six_y[] = {2, 3, 4, 5, 6};
    assert(are_disjoint(
        test_six_x,
        test_six_y,
        sizeof(test_six_x) / sizeof(test_six_x[0]),
        sizeof(test_six_y) / sizeof(test_six_y[0])
    ) == 1);

    int test_seven_x[] = {100, 200, 300, 400};
    int test_seven_y[] = {400};
    assert(are_disjoint(
        test_seven_x,
        test_seven_y,
        sizeof(test_seven_x) / sizeof(test_seven_x[0]),
        sizeof(test_seven_y) / sizeof(test_seven_y[0])
    ) == 0);

    int test_eight_x[] = {1, 1, 1, 1};
    int test_eight_y[] = {2, 2, 2};
    assert(are_disjoint(
        test_eight_x,
        test_eight_y,
        sizeof(test_eight_x) / sizeof(test_eight_x[0]),
        sizeof(test_eight_y) / sizeof(test_eight_y[0])
    ) == 1);

    int test_nine_x[] = {-2, -1, 0};
    int test_nine_y[] = {0, 1, 2};
    assert(are_disjoint(
        test_nine_x,
        test_nine_y,
        sizeof(test_nine_x) / sizeof(test_nine_x[0]),
        sizeof(test_nine_y) / sizeof(test_nine_y[0])
    ) == 0);

    printf("All Test Cases have passed!\n");
}