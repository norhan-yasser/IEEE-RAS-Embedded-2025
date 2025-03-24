#include <stdio.h>

 //https://codeforces.com/group/MWSDmqGsZm/contest/219158/submission/312229004

int main() {
    long long A, B, C, D;

    scanf("%lld %lld %lld %lld", &A, &B, &C, &D);


    long long result = (A % 100) * (B % 100) * (C % 100)*(D % 100)% 100;


    printf("%02lld\n", result);
    return 0;
}
