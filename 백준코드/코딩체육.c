#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int count = n / 4;

    for (int i = 0; i < count; i++) {
        printf("long ");
    }

    printf("int\n");

    return 0;
}