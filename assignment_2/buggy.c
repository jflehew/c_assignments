// The following code is a buggy implementation
// of a program for swapping two integers.

// Using gcc, work to eliminate
// all compilation errors and warnings in this code,
// then verify it runs correctly.  Your solution to
// this problem will be the corrected buggy.c file.
//To receive full credit, your submitted file should compile
//with no errors or warnings.

#include <assert.h>
#include <stdlib.h>

int swap(int* x, int* y) {
	assert(!(x == NULL));
	assert(!(y == NULL));
	int t = *x;
	int s = *y;
	*x = s;
	*y = t;
	return 0;
}

int main(){
	int a = 0,b = 1;
	swap(&a,&b);
	assert(a == 1);
	assert(b == 0);
	return 0;
}
    


