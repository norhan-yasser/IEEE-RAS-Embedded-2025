#include <stdio.h>

int main() {
    int arr[10];
    int *p = arr;
    int n = 10;
    int temp;

    printf("Enter 10 array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", (p + i));
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(p + i) > *(p + j)) {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    printf("Array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d", *(p + i));
        if (i != n - 1) printf(", ");
    }
    printf(",\n");

    printf("Array in descending order: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", *(p + i));
        if (i != 0) printf(", ");
    }
    printf(",\n");

    return 0;
}
