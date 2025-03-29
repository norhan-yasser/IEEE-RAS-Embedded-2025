
//https://codeforces.com/group/MWSDmqGsZm/contest/223205/submission/313041481

#include <stdio.h>
#include <stdbool.h>


bool isOdd(int num);
bool isBinaryPalindrome(int num);

int main() {
    int N;
    scanf("%d", &N);

    if (isOdd(N) && isBinaryPalindrome(N)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}


bool isOdd(int num) {
    return num % 2 != 0;
}


bool isBinaryPalindrome(int num) {
    int binary[32], index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num /= 2;
    }

    for (int i = 0; i < index / 2; i++) {
        if (binary[i] != binary[index - i - 1]) {
            return false;
        }
    }
    return true;
}
