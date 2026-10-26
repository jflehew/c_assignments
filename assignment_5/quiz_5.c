#include <stdio.h>

int main(void) {
  int i = 2;
  int a[] = {0,1,2,3,4};
  int n = sizeof(a) / sizeof(a[0]);
  for (i = 0; i < n; i++) {
    (*(a+i))++;
    printf(" %d", a[i]);
  }
  printf("\n");
  return 0;
}