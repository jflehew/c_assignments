#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int vowel_free(char *string_input, char *string_output){
    // assert(string_output == "\0");
    assert(string_input != NULL);
    assert(string_output != NULL);
    int i = 0;
    int j = 0;
    while(string_input[i] != 0){
        if(
            string_input[i] != 'A' &&
            string_input[i] != 'E' &&
            string_input[i] != 'I' &&
            string_input[i] != 'O' &&
            string_input[i] != 'U' &&
            string_input[i] != 'a' &&
            string_input[i] != 'e' &&
            string_input[i] != 'i' &&
            string_input[i] != 'o' &&
            string_input[i] != 'u'
        ){
            string_output[j] = string_input[i];
            j++;
        }
        i++;
    }
    string_output[j] = '\0';
    return 0;
}

void verify_output(char * input_test, char * output_test){
    assert(input_test != NULL);
    assert(output_test != NULL);
    for(int i = 0; input_test[i] != 0; i++){
        assert(strcmp(input_test, output_test) == 0);
    }
}

int main(){
    char string_output[100];
    int return_check;

    // Test 1
    char *string_input_1 = "Hello my name is John How do you do?";
    char *string_expected_1 = "Hll my nm s Jhn Hw d y d?";

    printf("----- Test 1 -----\n");
    return_check = vowel_free(string_input_1, string_output);
    verify_output(string_expected_1, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_1, string_output);


    // Test 2 - lowercase vowels
    char *string_input_2 = "the quick brown fox";
    char *string_expected_2 = "th qck brwn fx";

    printf("----- Test 2 -----\n");
    return_check = vowel_free(string_input_2, string_output);
    verify_output(string_expected_2, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_2, string_output);


    // Test 3 - uppercase vowels
    char *string_input_3 = "THE QUICK BROWN FOX";
    char *string_expected_3 = "TH QCK BRWN FX";

    printf("----- Test 3 -----\n");
    return_check = vowel_free(string_input_3, string_output);
    verify_output(string_expected_3, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_3, string_output);


    // Test 4 - only vowels
    char *string_input_4 = "aeiouAEIOU";
    char *string_expected_4 = "";

    printf("----- Test 4 -----\n");
    return_check = vowel_free(string_input_4, string_output);
    verify_output(string_expected_4, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_4, string_output);


    // Test 5 - no vowels
    char *string_input_5 = "rhythms";
    char *string_expected_5 = "rhythms";

    printf("----- Test 5 -----\n");
    return_check = vowel_free(string_input_5, string_output);
    verify_output(string_expected_5, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_5, string_output);


    // Test 6 - numbers and symbols
    char *string_input_6 = "C programming 101!";
    char *string_expected_6 = "C prgrmmng 101!";

    printf("----- Test 6 -----\n");
    return_check = vowel_free(string_input_6, string_output);
    verify_output(string_expected_6, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_6, string_output);


    // Test 7 - single consonant
    char *string_input_7 = "x";
    char *string_expected_7 = "x";

    printf("----- Test 7 -----\n");
    return_check = vowel_free(string_input_7, string_output);
    verify_output(string_expected_7, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_7, string_output);


    // Test 8 - single vowel
    char *string_input_8 = "A";
    char *string_expected_8 = "";

    printf("----- Test 8 -----\n");
    return_check = vowel_free(string_input_8, string_output);
    verify_output(string_expected_8, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_8, string_output);


    // Test 9 - repeated vowels and consonants
    char *string_input_9 = "bookkeeper";
    char *string_expected_9 = "bkkpr";

    printf("----- Test 9 -----\n");
    return_check = vowel_free(string_input_9, string_output);
    verify_output(string_expected_9, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_9, string_output);


    // Test 10 - empty string
    char *string_input_10 = "";
    char *string_expected_10 = "";

    printf("----- Test 10 -----\n");
    return_check = vowel_free(string_input_10, string_output);
    verify_output(string_expected_10, string_output);
    assert(return_check == 0);
    printf("Input String:\n%s\nOutput String:\n%s\n\n",
        string_input_10, string_output);
    return 0;
}