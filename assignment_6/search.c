#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

int search(char *text, char *keyword, int *count){
    assert(text != NULL);
    assert(keyword != NULL);
    assert(count != NULL);
    *count = 0;
    int keyword_length = strlen(keyword);
    int text_length = strlen(text);

    for(int i = 0; i < text_length; i++){
        if(keyword[0] == text[i]){
            for(int j = 0; j < keyword_length; j++){
                printf("chars: %c, %c\n", keyword[j], text[i+j]);
                if(keyword[j] != text[i+j]) break;
                if(j+1 == keyword_length){
                    ++*count;
                    i += j;
                } 
            }
        }
    }
    return 0;
}

int main () {
int count; 

char text[] = "In a hole in the ground there lived a hobbit. Not a nasty, dirty, wet hole, filled with the ends of worms and an oozy smell, nor yet a dry, bare, sandy hole with nothing in it to sit down on or to eat: it was a hobbit-hole, and that means comfort.";

assert(search(text,"hole",&count) == 0); assert(count == 4); //the word "hole" appears 4 times

assert(search(text,"hobbit",&count) == 0); assert(count == 2); //the word "hobbit" occurs 2 times

assert(search(text,"hobbit ",&count) == 0); assert(count == 0); //note the difference from the previous case: there is a space at the end of the word. There is no occurrence of the word hobbit followed by a space. 

assert(search(text," ",&count) == 0); assert(count == 51); //there are 51 spaces

assert(search(text,"a",&count) == 0); assert(count == 15);

assert(search(text,"at",&count) == 0); assert(count == 2); 

assert(search(text, "In", &count) == 0); assert(count == 1);

assert(search(text, "comfort.", &count) == 0); assert(count == 1);

assert(search(text, "dragon", &count) == 0); assert(count == 0);

assert(search(text, "hobbit.", &count) == 0); assert(count == 1);

assert(search(text, "Hole", &count) == 0); assert(count == 0);

assert(search(text, "in the", &count) == 0); assert(count == 1);

char text_two[] = "aaaaaa";
printf("%d\n", count);
assert(search(text_two, "aa", &count) == 0); assert(count == 3);

char text_three[] = "hello";
assert(search(text_three, "hello", &count) == 0); assert(count == 1);

char text_four[] = "cat";
assert(search(text_four, "catalog", &count) == 0); assert(count == 0);

printf("all tests completed successfully!");

}