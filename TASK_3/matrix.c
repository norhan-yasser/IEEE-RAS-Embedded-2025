//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316128740

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[N][N];
    int MainD = 0, SecD = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        MainD += a[i][i];
    }

    for (int i = 0; i < N; i++) {
        SecD += a[i][N - 1 - i];
    }

     printf("%d\n", abs(MainD - SecD));

    return 0;
}
