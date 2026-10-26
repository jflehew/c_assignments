#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int encrypt(char *message, char key, char *encrypted){
    assert(message != NULL);
    assert(encrypted != NULL);
    int key_number = tolower(key) - 'a';
    int key_overflow = 0;
    int length = strlen(message);
    for(int i = 0; i < length; i++){
        if ((message[i] < 'A' || message [i] > 'Z') && (message[i] < 'a' || message[i] > 'z')){
            encrypted[i] = message[i];
        }
        else{
            if(message[i] >= 'A' && message[i] <='Z'){
                if(message[i] + key_number > 'Z'){
                    key_overflow = key_number - ('Z' - message[i]) - 1;
                    encrypted[i] = 'A' + key_overflow;
                }else{
                    encrypted[i] = message[i] + key_number;
                }
            }else{
                if(message[i] + key_number > 'z'){
                    key_overflow = key_number - ('z' - message[i]) - 1;
                    encrypted[i] = 'a' + key_overflow;
                }else{
                    encrypted[i] = message[i] + key_number;
                }
            }
        }
    }
    encrypted[length] = '\0';
    return 0;
}

int decrypt(char *encrypted, char key, char *decrypted){
    assert(encrypted != NULL);
    assert(decrypted != NULL);
    int key_number = tolower(key) - 'a';
    // printf("%d\n", key_number);
    int key_overflow = 0;
    int length = strlen(encrypted);
    for(int i = 0; i < length; i++){
        // printf("%c", encrypted[i]);
        if ((encrypted[i] < 'A' || encrypted [i] > 'Z') && (encrypted[i] < 'a' || encrypted[i] > 'z')){
            decrypted[i] = encrypted[i];
        }
        else{
            if(encrypted[i] >= 'A' && encrypted[i] <= 'Z'){
                if(encrypted[i] - key_number < 'A'){
                    key_overflow = 'A' - (encrypted[i] - key_number) - 1;
                    // printf("encrypted[i] - key_number: %d\n", encrypted[i] - key_number);
                    // printf("encrypted[i]: %d, %c\n", encrypted[i], encrypted[i]);
                    // printf("key overflow: %d\n", key_overflow);
                    decrypted[i] = 'Z' - key_overflow;
                }else{
                    decrypted[i] = encrypted[i] - key_number;
                }
            }else{
                if(encrypted[i] - key_number < 'a'){
                    key_overflow = 'a' - (encrypted[i] - key_number) - 1;
                    decrypted[i] = 'z' - key_overflow;
                }else{
                    decrypted[i] = encrypted[i] - key_number;
                }
            }
        }
    }
    decrypted[length] = '\0';
    return 0;
}

int main () {
    char encrypted[100];
    char decrypted[100];

    // Test 1 - original test
    char message_1[] = "Jon Snow is the true heir to the Iron Throne";
    char key_1 = 'h';
    assert(encrypt(message_1, key_1, encrypted) == 0);
    assert(decrypt(encrypted, key_1, decrypted) == 0);
    assert(strcmp(message_1, decrypted) == 0);


    // Test 2 - simple lowercase
    char message_2[] = "hello";
    char key_2 = 'b';
    assert(encrypt(message_2, key_2, encrypted) == 0);
    assert(decrypt(encrypted, key_2, decrypted) == 0);
    assert(strcmp(message_2, decrypted) == 0);


    // Test 3 - uppercase
    char message_3[] = "HELLO";
    char key_3 = 'b';
    assert(encrypt(message_3, key_3, encrypted) == 0);
    assert(decrypt(encrypted, key_3, decrypted) == 0);
    assert(strcmp(message_3, decrypted) == 0);


    // Test 4 - lowercase wraparound
    char message_4[] = "xyz";
    char key_4 = 'b';
    assert(encrypt(message_4, key_4, encrypted) == 0);
    assert(decrypt(encrypted, key_4, decrypted) == 0);
    assert(strcmp(message_4, decrypted) == 0);


    // Test 5 - uppercase wraparound
    char message_5[] = "XYZ";
    char key_5 = 'b';
    assert(encrypt(message_5, key_5, encrypted) == 0);
    assert(decrypt(encrypted, key_5, decrypted) == 0);
    assert(strcmp(message_5, decrypted) == 0);


    // Test 6 - punctuation and numbers unchanged
    char message_6[] = "Hello, World! 123";
    char key_6 = 'd';
    assert(encrypt(message_6, key_6, encrypted) == 0);
    assert(decrypt(encrypted, key_6, decrypted) == 0);
    assert(strcmp(message_6, decrypted) == 0);


    // Test 7 - zero shift
    char message_7[] = "Nothing Should Change!";
    char key_7 = 'a';
    assert(encrypt(message_7, key_7, encrypted) == 0);
    assert(decrypt(encrypted, key_7, decrypted) == 0);
    assert(strcmp(message_7, decrypted) == 0);


    // Test 8 - large shift
    char message_8[] = "abcXYZ";
    char key_8 = 'z';
    assert(encrypt(message_8, key_8, encrypted) == 0);
    assert(decrypt(encrypted, key_8, decrypted) == 0);
    assert(strcmp(message_8, decrypted) == 0);


    // Test 9 - only non-letter characters
    char message_9[] = "1234 !@#$";
    char key_9 = 'm';
    assert(encrypt(message_9, key_9, encrypted) == 0);
    assert(decrypt(encrypted, key_9, decrypted) == 0);
    assert(strcmp(message_9, decrypted) == 0);


    // Test 10 - mixed uppercase and lowercase with wraparound
    char message_10[] = "Zoo zebra";
    char key_10 = 'c';
    assert(encrypt(message_10, key_10, encrypted) == 0);
    assert(decrypt(encrypted, key_10, decrypted) == 0);
    assert(strcmp(message_10, decrypted) == 0);

    printf("All tests passed!\n");
    return 0;
}
