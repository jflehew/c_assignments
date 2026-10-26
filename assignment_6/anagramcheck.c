#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int anagram_check(char * string_one, char * string_two){
    assert(string_one != NULL);
    assert(string_two != NULL);
    char string_one_test[100];
    char string_two_test[100];
    
    strcpy(string_one_test, string_one);
    strcpy(string_two_test, string_two);

    int max_length = 0;

    if(strlen(string_one) >= strlen(string_two)){
        max_length = strlen(string_one);
    }
    else{
        max_length = strlen(string_two);
    }

    int string_one_char_count = 0;
    int string_two_char_count = 0;

    if (strlen(string_one) > strlen(string_two)){
        // printf("I made it into if!\n");
        for(int i = 0; i < max_length; i++){
            // printf("I made it!\n");
            if (string_one[i] == ' ') continue;
            string_one_char_count++;
            for(long long unsigned int j = 0; j < strlen(string_two); j++){
                if (string_two_test[j] == ' ') continue;
                if(string_two_test[j] == string_one[i] || string_two_test[j] == (string_one[i] + 32) || string_two_test[j] == (string_one[i] - 32)){
                    string_two_char_count++;
                    string_two_test[j] = ' ';
                    break;
                }
            }
        }
    }

    else{
        // printf("I made it int else!\n");
        for(int i = 0; i < max_length; i++){
            if (string_two[i] == ' ') continue;
            string_two_char_count++;
            for(long long  unsigned int j = 0; j < strlen(string_one); j++){
                // printf("how many times do i go around?\nfirst loop: %d\nsecond loop: %d\n", i, j);
                if (string_one_test[j] == ' ') continue;
                // printf("the char here is: %c\n", string_one[j]);
                if(string_one_test[j] == string_two[i] || string_one_test[j] == (string_two[i] + 32) || string_one_test[j] == (string_two[i] - 32)){
                    string_one_char_count++;
                    string_one_test[j] = ' ';
                    break;
                }
            }
        }
    }
    // printf("%s\n", string_one_test);
    // printf("char count one: %d, char count two: %d\n", string_one_char_count, string_two_char_count);
    if(string_one_char_count == string_two_char_count){
        printf("%s is an anagram of: %s\n", string_one, string_two);
        return 1;
    }
    else{
        printf("your strings are not anagrams.\n");
        return 0;
    }
    
}

int main (){
int return_check;

    // Test 1 - assignments test
    char *string_test_one = "Tom Marvolo Riddle";
    char *string_test_one_anagram = "I am Lord Voldemort";

    return_check = anagram_check(string_test_one, string_test_one_anagram);
    assert(return_check == 1);


    // Test 2 - simple anagram
    char *string_test_two = "listen";
    char *string_test_two_anagram = "silent";

    return_check = anagram_check(string_test_two, string_test_two_anagram);
    assert(return_check == 1);


    // Test 3 - capitalization differences
    char *string_test_three = "Dormitory";
    char *string_test_three_anagram = "Dirty Room";

    return_check = anagram_check(string_test_three, string_test_three_anagram);
    assert(return_check == 1);


    // Test 4 - lots of spaces
    char *string_test_four = "The Eyes";
    char *string_test_four_anagram = "They See";

    return_check = anagram_check(string_test_four, string_test_four_anagram);
    assert(return_check == 1);


    // Test 5 - repeated letters
    char *string_test_five = "banana";
    char *string_test_five_anagram = "aaabnn";

    return_check = anagram_check(string_test_five, string_test_five_anagram);
    assert(return_check == 1);


    // Test 6 - same letters, different capitalization
    char *string_test_six = "Triangle";
    char *string_test_six_anagram = "Integral";

    return_check = anagram_check(string_test_six, string_test_six_anagram);
    assert(return_check == 1);


    // Test 7 - not an anagram
    char *string_test_seven = "hello";
    char *string_test_seven_anagram = "world";

    return_check = anagram_check(string_test_seven, string_test_seven_anagram);
    assert(return_check == 0);


    // Test 8 - almost an anagram but wrong repeated letter count
    char *string_test_eight = "aabbcc";
    char *string_test_eight_anagram = "aabccc";

    return_check = anagram_check(string_test_eight, string_test_eight_anagram);
    assert(return_check == 0);


    // Test 9 - different number of non-space characters
    char *string_test_nine = "school master";
    char *string_test_nine_anagram = "the classroomx";

    return_check = anagram_check(string_test_nine, string_test_nine_anagram);
    assert(return_check == 0);


    // Test 10 - one-character case difference
    char *string_test_ten = "A";
    char *string_test_ten_anagram = "a";

    return_check = anagram_check(string_test_ten, string_test_ten_anagram);
    assert(return_check == 1);


    printf("\nAll tests passed!\n");

    return 0;
}