#include <stdio.h>

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int A[100][100];
    int B[100][100];
    int C[100][100];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i][j] = A[i][j] + B[i][j]; 
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", C[i][j]); 
            if (j < M - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
