#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

    typedef struct {
        char word[33];
        int word_freq;
    }Word; 

int test_runtime_args(int argc, char * argv[], int * max_string_length){
    assert(max_string_length != NULL);
    assert(argv != NULL);
    // handles logic to ensure runtime arguments are correct
    if (argc > 1){
        //test's that the first argument is one of the accepted arguments
        if(strcmp(argv[1], "-h") != 0 && strcmp(argv[1], "-s") != 0){
            printf("Valid runtime arguments ar '-h' or '-s' (int)\n");
            return -1;
        }
        //itterates over argv for any runtime arguments
        for (int i = 1; i < argc; i++){
            //if runtime argument is -h prints the programs info.
            if(strcmp(argv[i], "-h") == 0){
                printf("Enter -h for help, Oh! I see you've already done this!\n"
                        "Enter -s (int) to specify a maximum string length\n"
                        "String length must be between 1 and 32 characters long\n"
                        "Enter as many strings as you would like!\n"
                        "The function will return the frequency of those strings\n"
                        "Enjoy!\n"
                );
            }
            //if runtime argument is -s and is followed by an integer determines if it is a valid integer
            else if(strcmp(argv[i], "-s") == 0){
                if(i+1 >= argc){
                    printf("-s must be followed by an integer\n");
                    return -1;
                }
                if(sscanf(argv[i+1], "%d", max_string_length) != 1){
                    printf("-s must be followed by an integer\n");
                    return -1;
                };
                if(*max_string_length < 1 || *max_string_length > 32){
                    printf("You must enter a string length between 1 and 32 characters long\n");
                    return -1;
                }
                i++;
            }
            else{
                printf("Valid runtime arguments are '-h' or '-s' (int)\n");
                return -1;
            }
        }
    }
    return 0;
}

int allocate_stdin(char ***word_array, int * capacity, int * word_count, int * max_string_length){
    assert(word_array != NULL);
    assert(*word_array != NULL);
    assert(capacity != NULL);
    assert(word_count != NULL);
    int i = 0;
    char scanf_format[16];
    snprintf(scanf_format, sizeof(scanf_format), "%%%ds", *max_string_length);

    while(1){
        if(i == *capacity){
            int temp_capacity = *capacity * 2;
            char **temp = realloc(*word_array, temp_capacity * sizeof(**word_array));
            if(temp == NULL){
                printf("Memory allocation failed\n");
                return -1;
            }
            *word_array = temp;
            *capacity = temp_capacity;
        }
        (*word_array)[i] = malloc((*max_string_length + 1) * sizeof(char));
        if((*word_array)[i] == NULL){
            printf("Memory allocation failed\n");
            return -1;
        }
        if(scanf(scanf_format, (*word_array)[i]) != 1){
            free((*word_array)[i]);
            break;
        }
        i++;
    }
    // printf("%s\n", (*word_array)[1]);
    *word_count = i;
    return 0;
}

int test_if_word_doesnt_exisits(char *current_word, Word *words, char words_current_size){
    for(int i = 0; i < words_current_size; i++){
        // printf("\n%s, %s\n", current_word, words[i].word);
        if(strcmp(current_word, words[i].word) == 0){
            words[i].word_freq++;
            return -1;
        }
    }
    return 0;
};

void create_word_matrix(Word *words,char **word_array, int word_count, int *total_words){ 
    int unique_words = 0;
    for(int i = 0; i < word_count; i++){
        if(test_if_word_doesnt_exisits(word_array[i], words, unique_words) == 0){
            strcpy(words[unique_words].word, word_array[i]);
            words[unique_words].word_freq = 1;
            unique_words++;
        }
    }
    printf("%d\n", unique_words);
    *total_words = unique_words;
}

void print_word_matrix(Word *words, int words_size){
    for(int i = 0; i < words_size; i++){
        printf( "%d. || "
                "Word: %s || "
                "Frequency: %d\n",
                i, 
                words[i].word,
                words[i].word_freq
                );
    }
}


int main(int argc, char *argv[]){
        int max_string_length = 32;
    if (test_runtime_args(argc, argv, &max_string_length) == -1){
        return -1;
    }

    int capacity = 100; 
    char **word_array = malloc(capacity * sizeof(*word_array));
    int word_count = 0;
    if(word_array == NULL){
        printf("memory allocation failed\n");
        return -1;
    }
    if (allocate_stdin(&word_array, &capacity, &word_count, &max_string_length) == -1){
        free(word_array);
        return -1;
    }else{
        char **temp = realloc(word_array, word_count * sizeof(*word_array));
        if(temp == NULL){
            printf("Memory allocation failed\n");
            return -1;
        }
        word_array = temp;
    }
    // printf("word count: %d\n", word_count);
    Word *words = malloc(word_count * sizeof(*words));
    // printf("word count: %lld\n", word_count * sizeof(*words));
    if (words == NULL){
        printf("memory allocation failed");
        return -1;
    }
    int total_words = 0;
    create_word_matrix(words, word_array, word_count, &total_words);
    printf("total words: %d\n", total_words);
    print_word_matrix(words, total_words);

    for(int i = 0; i < word_count; i++){
        free(word_array[i]);
    }
    free(word_array);
    free(words);
    return 0;
}

