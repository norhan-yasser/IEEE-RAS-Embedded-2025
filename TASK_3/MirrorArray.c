//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316129457

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int a[N][M];


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
