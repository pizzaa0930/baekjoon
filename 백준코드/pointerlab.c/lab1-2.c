 #include <stdio.h>
 char* c[] = { "Hello", "KoreaTech", "Computer", "Language" };
 char** cp[] = { c + 3, c + 2, c + 1, c };
 char*** cpp = cp;
 int main(void) {
 printf("%s ", **++cpp);
 printf("%s ", *-- * ++cpp + 3);
 printf("%s ", *cpp[-2] + 3);
 printf("%s ", cpp[-1][-1] + 1);
 return 0;
 }