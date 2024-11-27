#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

int main() {
    char str[1000001];
    int count[ALPHABET_SIZE] = {0};

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            count[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            count[ch - 'A']++;
        }
    }

    int maxCount = 0;
    char result = '?';

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            result = 'A' + i;
        } else if (count[i] == maxCount) {
            result = '?';
        }
    }

    printf("%c\n", result);
    return 0;
}
