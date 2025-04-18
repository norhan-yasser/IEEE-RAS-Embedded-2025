//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/316134612

#include <stdio.h>

int main() {
    char S[1000005];
    int inWord = 0, wordCount = 0;


    fgets(S, sizeof(S), stdin);


    for (int i = 0; S[i] != '\0'; i++) {
        if ((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')) {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        } else {
            inWord = 0;
        }
    }

    printf("%d\n", wordCount);
    return 0;
}
