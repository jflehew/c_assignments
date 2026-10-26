
#include <stdio.h>

// void printSize(char * p) {
//   printf("%zu\n", sizeof(p));
// }

int main(void) {
//   char * d = NULL;
//   printSize(d);
//   return 0;

   char str[] = "complement";
 char * p = str;
 p[sizeof(str)-6] = 'i';
 int n = sizeof(str);
 printf("%d\n", n);
printf("That's quite a %s!\n", str);

return 0;
}