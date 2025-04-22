#include <stdio.h>

int stringLength(char *str);

int main() {
    char str[] = "Embedded Systems";

    int len = stringLength(str);
    printf("Length = %d\n", len);

    return 0;
}


int stringLength(char *str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}
