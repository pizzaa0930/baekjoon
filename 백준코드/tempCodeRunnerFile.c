#include <stdio.h>
 int main(void) {
 int a[5] = { 1,3,5,7,9 };
 int* ptr = (int*)(&a + 1);
 printf("%d %d", *(a + 1), *(ptr- 1));
 return 0;
 }