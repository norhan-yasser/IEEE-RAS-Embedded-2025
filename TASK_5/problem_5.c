#include <stdio.h>

int getOddNumbers(int *input, int n, int *output);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int oddArr[10];
    int *p1 = arr;
    int *p2 = oddArr;
    int totalOdds;

    totalOdds = getOddNumbers(p1, 7, p2);

    printf("Odd numbers are: ");
    for (int i = 0; i < totalOdds; i++) {
        printf("%d ", *(p2 + i));
    }
    printf("\nTotal odd numbers: %d\n", totalOdds);

    return 0;
}

int getOddNumbers(int *input, int n, int *output) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(input + i) % 2 != 0) {
            *(output + count) = *(input + i);
            count++;
        }
    }
    return count;
}
