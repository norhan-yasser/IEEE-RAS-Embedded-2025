//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/313054153

#include <stdio.h>

long long N;

int ReachValue(long long num) {
    if (num > N) {
        return 0;
    }
    if (num == N) {
        return 1;
    }
    return ReachValue(num * 10) || ReachValue(num * 20);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%lld", &N);

        if (ReachValue(1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
