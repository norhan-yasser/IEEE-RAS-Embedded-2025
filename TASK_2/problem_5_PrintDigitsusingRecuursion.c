//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/313047109

#include <stdio.h>


void printDigits(int num) {
    if (num < 10) {
        printf("%d ", num);
        return;
    }
    printDigits(num / 10);
    printf("%d ", num % 10);
}

int main() {
    int T, N;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        printDigits(N);
        printf("\n");
    }

    return 0;
}
