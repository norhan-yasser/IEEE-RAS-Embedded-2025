#include <stdio.h>

void printEvenDigits(char *str);

int main() {

    char str[] = "012345678";

    printf("Even digits in the string: ");
    printEvenDigits(str);

    return 0;
}

void printEvenDigits(char *str) {
    while (*str != '\0') {
        if ((*str >= '0' && *str <= '9') && ((*str - '0') % 2 == 0)) {
            printf("%c", *str);
        }
        str++;
    }
    printf("\n");
}
