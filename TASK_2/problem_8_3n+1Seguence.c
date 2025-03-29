//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/313050528

#include <stdio.h>


int sequenceLength(int n) {
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        return 1 + sequenceLength(n / 2);
    } else {
        return 1 + sequenceLength(3 * n + 1);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", sequenceLength(N));
    return 0;
}
