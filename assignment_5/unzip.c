#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int unzip (
    int *unzip_array, 
    int *array_a, 
    int *array_b, 
    int unzip_length){
        assert(unzip_length != 0);
        assert(unzip_array != NULL);
        assert(array_a != NULL);
        assert(array_b != NULL);
        int j = 0;
        for(int i = 0; i < unzip_length; i += 2){
            array_a[j] = unzip_array[i];
            if(i + 1 < unzip_length){
                array_b[j] = unzip_array[i+1];
            }
            j++;
        }
        return 0;
}

void print_arrays(
    int *unzip_array, 
    int *array_a, 
    int *array_b, 
    int unzip_length, 
    int array_a_length, 
    int array_b_length){
        assert(unzip_length != 0);
        assert(unzip_array != NULL);
        assert(array_a != NULL);
        assert(array_b != NULL);
        printf("\nthe array you are unzipping is:\n");
        for(int i = 0; i < unzip_length; i++){
            printf("%d ", unzip_array[i]);
        }
        printf("\n");
        printf("Array A:\n");
        for(int i = 0; i < array_a_length; i++){
            printf("%d ", array_a[i]);
        }
        printf("\n");
        printf("Array B:\n");
        for(int i = 0; i < array_b_length; i++){
            printf("%d ", array_b[i]);
        }
        printf("\n");
}

int main (){

    int unzip_test_zero[] = {1,2,3,4,5,6};
    int unzip_test_zero_length = sizeof(unzip_test_zero) / sizeof(unzip_test_zero[0]);
    int array_a_length = (unzip_test_zero_length + 1) / 2;
    int array_b_length = unzip_test_zero_length / 2;
    int test_array_a_zero[array_a_length];
    int test_array_b_zero[array_b_length];
    printf("-----first test-----\n");
    unzip(
        unzip_test_zero, 
        test_array_a_zero, 
        test_array_b_zero,
        sizeof(unzip_test_zero) / sizeof(unzip_test_zero[0])
    );
    print_arrays(unzip_test_zero, 
        test_array_a_zero, 
        test_array_b_zero, 
        sizeof(unzip_test_zero) / sizeof(unzip_test_zero[0]), 
        sizeof(test_array_a_zero) / sizeof(test_array_a_zero[0]), 
        sizeof(test_array_b_zero) / sizeof(test_array_b_zero[0]));
    printf("\n-----end of first test-----\n");

    int unzip_test_one[] = {10,20,30,40};
    int unzip_test_one_length = sizeof(unzip_test_one) / sizeof(unzip_test_one[0]);
    int array_a_one_length = (unzip_test_one_length + 1) / 2;
    int array_b_one_length = unzip_test_one_length / 2;
    int test_array_a_one[array_a_one_length];
    int test_array_b_one[array_b_one_length];
    printf("-----second test-----\n");
    unzip(
        unzip_test_one,
        test_array_a_one,
        test_array_b_one,
        unzip_test_one_length
    );
    print_arrays(
        unzip_test_one,
        test_array_a_one,
        test_array_b_one,
        unzip_test_one_length,
        array_a_one_length,
        array_b_one_length
    );
    printf("\n-----end of second test-----\n");

    int unzip_test_two[] = {5,10,15,20,25};
    int unzip_test_two_length = sizeof(unzip_test_two) / sizeof(unzip_test_two[0]);
    int array_a_two_length = (unzip_test_two_length + 1) / 2;
    int array_b_two_length = unzip_test_two_length / 2;
    int test_array_a_two[array_a_two_length];
    int test_array_b_two[array_b_two_length];
    printf("-----third test-----\n");
    unzip(
        unzip_test_two,
        test_array_a_two,
        test_array_b_two,
        unzip_test_two_length
    );
    print_arrays(
        unzip_test_two,
        test_array_a_two,
        test_array_b_two,
        unzip_test_two_length,
        array_a_two_length,
        array_b_two_length
    );
    printf("\n-----end of third test-----\n");

    int unzip_test_three[] = {-1,-2,-3,-4,-5,-6};
    int unzip_test_three_length = sizeof(unzip_test_three) / sizeof(unzip_test_three[0]);
    int array_a_three_length = (unzip_test_three_length + 1) / 2;
    int array_b_three_length = unzip_test_three_length / 2;
    int test_array_a_three[array_a_three_length];
    int test_array_b_three[array_b_three_length];
    printf("-----fourth test-----\n");
    unzip(
        unzip_test_three,
        test_array_a_three,
        test_array_b_three,
        unzip_test_three_length
    );
    print_arrays(
        unzip_test_three,
        test_array_a_three,
        test_array_b_three,
        unzip_test_three_length,
        array_a_three_length,
        array_b_three_length
    );
    printf("\n-----end of fourth test-----\n");

    int unzip_test_four[] = {7};
    int unzip_test_four_length = sizeof(unzip_test_four) / sizeof(unzip_test_four[0]);
    int array_a_four_length = (unzip_test_four_length + 1) / 2;
    int array_b_four_length = unzip_test_four_length / 2;
    int test_array_a_four[array_a_four_length];
    int test_array_b_four[array_b_four_length];
    printf("-----fifth test-----\n");
    unzip(
        unzip_test_four,
        test_array_a_four,
        test_array_b_four,
        unzip_test_four_length
    );
    print_arrays(
        unzip_test_four,
        test_array_a_four,
        test_array_b_four,
        unzip_test_four_length,
        array_a_four_length,
        array_b_four_length
    );
    printf("\n-----end of fifth test-----\n");

    int unzip_test_five[] = {100,200};
    int unzip_test_five_length = sizeof(unzip_test_five) / sizeof(unzip_test_five[0]);
    int array_a_five_length = (unzip_test_five_length + 1) / 2;
    int array_b_five_length = unzip_test_five_length / 2;
    int test_array_a_five[array_a_five_length];
    int test_array_b_five[array_b_five_length];
    printf("-----sixth test-----\n");
    unzip(
        unzip_test_five,
        test_array_a_five,
        test_array_b_five,
        unzip_test_five_length
    );
    print_arrays(
        unzip_test_five,
        test_array_a_five,
        test_array_b_five,
        unzip_test_five_length,
        array_a_five_length,
        array_b_five_length
    );
    printf("\n-----end of sixth test-----\n");

    int unzip_test_six[] = {0,1,0,1,0,1,0};
    int unzip_test_six_length = sizeof(unzip_test_six) / sizeof(unzip_test_six[0]);
    int array_a_six_length = (unzip_test_six_length + 1) / 2;
    int array_b_six_length = unzip_test_six_length / 2;
    int test_array_a_six[array_a_six_length];
    int test_array_b_six[array_b_six_length];
    printf("-----seventh test-----\n");
    unzip(
        unzip_test_six,
        test_array_a_six,
        test_array_b_six,
        unzip_test_six_length
    );
    print_arrays(
        unzip_test_six,
        test_array_a_six,
        test_array_b_six,
        unzip_test_six_length,
        array_a_six_length,
        array_b_six_length
    );
    printf("\n-----end of seventh test-----\n");

    int unzip_test_seven[] = {3,3,3,3,3,3,3,3};
    int unzip_test_seven_length = sizeof(unzip_test_seven) / sizeof(unzip_test_seven[0]);
    int array_a_seven_length = (unzip_test_seven_length + 1) / 2;
    int array_b_seven_length = unzip_test_seven_length / 2;
    int test_array_a_seven[array_a_seven_length];
    int test_array_b_seven[array_b_seven_length];
    printf("-----eighth test-----\n");
    unzip(
        unzip_test_seven,
        test_array_a_seven,
        test_array_b_seven,
        unzip_test_seven_length
    );
    print_arrays(
        unzip_test_seven,
        test_array_a_seven,
        test_array_b_seven,
        unzip_test_seven_length,
        array_a_seven_length,
        array_b_seven_length
    );
    printf("\n-----end of eighth test-----\n");

    int unzip_test_eight[] = {-10,20,-30,40,-50};
    int unzip_test_eight_length = sizeof(unzip_test_eight) / sizeof(unzip_test_eight[0]);
    int array_a_eight_length = (unzip_test_eight_length + 1) / 2;
    int array_b_eight_length = unzip_test_eight_length / 2;
    int test_array_a_eight[array_a_eight_length];
    int test_array_b_eight[array_b_eight_length];
    printf("-----ninth test-----\n");
    unzip(
        unzip_test_eight,
        test_array_a_eight,
        test_array_b_eight,
        unzip_test_eight_length
    );
    print_arrays(
        unzip_test_eight,
        test_array_a_eight,
        test_array_b_eight,
        unzip_test_eight_length,
        array_a_eight_length,
        array_b_eight_length
    );
    printf("\n-----end of ninth test-----\n");

    int unzip_test_nine[] = {11,22,33,44,55,66,77,88,99};
    int unzip_test_nine_length = sizeof(unzip_test_nine) / sizeof(unzip_test_nine[0]);
    int array_a_nine_length = (unzip_test_nine_length + 1) / 2;
    int array_b_nine_length = unzip_test_nine_length / 2;
    int test_array_a_nine[array_a_nine_length];
    int test_array_b_nine[array_b_nine_length];
    printf("-----tenth test-----\n");
    unzip(
        unzip_test_nine,
        test_array_a_nine,
        test_array_b_nine,
        unzip_test_nine_length
    );
    print_arrays(
        unzip_test_nine,
        test_array_a_nine,
        test_array_b_nine,
        unzip_test_nine_length,
        array_a_nine_length,
        array_b_nine_length
    );
    printf("\n-----end of tenth test-----\n");
}