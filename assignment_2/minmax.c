#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//minmax function taking in 3 integers and the address to be modified for min and max
int minmax(int a, int b, int c, int *min, int *max){
    //if either of the values of the pointers is null return -1
    if(min == NULL || max == NULL){
        return -1;
    }
    //set both values of min and max to a
    *min = a;
    *max = a;
    //test to see if anything is bigger or less then a
    //if bigger or less based on criteria reset min and max
    if(b < *min){
        *min = b;
    }
    if(b > *max){
        *max = b;
    }
    if(c < *min){
        *min = c;
    }
    if(c > *max){
        *max = c;
    }
    //return 0 to state that the function completed successfully
    return 0;
}

int main(){
    int min,max,x; //declare our variables. x is for holding the return value
    
    //Below are multiple test cases, including scenarios in which some inputs are equal or are negative numbers. You can add more. 

    //Test case 1: all positive numbers and all different 
    x = minmax(1,3,2,&min,&max);
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==1 && max==3); //we expect min to be 1 and max to be 3
    
    //Test case 2: all different numbers and one of them negative
    x = minmax(5,2,-10,&min,&max); 
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==-10 && max==5); //we expect min to be -10 and max to be 5
    
    //Test case 3: all different numbers and all three negative
    x = minmax(-5,-21,-78,&min,&max); 
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==-78 && max==-5); //we expect min to be -78 and max to be -5
    
    //Test case 4: Two numbers are equal and negative, third one is zero
    x = minmax(-5,-5,0,&min,&max); 
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==-5 && max==0); //we expect min to be -5 and max to be 0
    
    //Test case 5: All three numbers are equal
    x = minmax(4,4,4,&min,&max); 
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==4 && max==4); //we expect min to be 4 and max to be also 4
    
    //Test case 6: all three are zero
    x = minmax(0,0,0,&min,&max); 
    printf("min = %d\nmax = %d\n", min, max);
    assert(x==0); //we expect our function to return 0, since inputs are in the correct form 
    assert(min==0 && max==0); //we expect min to be 0 and max to be 0

    //Test case 7: instead of passing address of min, we pass in a NULL pointer
    x = minmax(1,2,3,NULL,&max); 
    assert(x==-1); //we expect our function to return -1, since input is malformed

    //Test case 8: instead of passing address of max, we pass in a NULL pointer
    x = minmax(1,2,3,&min,NULL); 
    assert(x==-1); //we expect our function to return -1, since input is malformed 

    printf("All tests passed successfully!\n");
    return 0; 
}