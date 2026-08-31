#include<stdio.h>
int main(){
    char c;
    printf("Welcome to ECEN 1310! Have you learned or experimented with C programming before? (y/n):");
    scanf("%c",&c);
    if (c == 'y'){
        printf("That's awesome! But there is always so much more to learn!\n");
    }
    else if (c == 'n'){
        printf("No worries! This course will introduce you to the wonderful world of C and by the end of the course you will be a pro programmer!\n");
    }
    else{
        printf("Error! You must type in either y or n.\n");
    }
    return 0;
}