#include <stdio.h>
#include <string.h>

int main() {
    char word[101];
    int is_palindrome = 1;
    scanf("%s", word);

    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            is_palindrome = 0; 
            break;
        }
    }

    printf("%d\n", is_palindrome);
    return 0;
}