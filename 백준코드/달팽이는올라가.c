#include <stdio.h>

int main() {
    long long A, B, V;
    scanf("%lld %lld %lld", &A, &B, &V);

    long long day = (V - B) / (A - B);
    if ((V - B) % (A - B) != 0) {
        day++;
    }

    printf("%lld\n", day);
    return 0;
}






