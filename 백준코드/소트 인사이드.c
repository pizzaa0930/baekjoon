#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a);
}

int main() {
    char number[11];
    scanf("%s", number); 
    
    int len = strlen(number);
    qsort(number, len, sizeof(char), compare);

    printf("%s\n", number);
    return 0;
}