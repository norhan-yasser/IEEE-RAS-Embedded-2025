#include <stdio.h>

int main() {

    int a = 10;
    char c = 'A';
    float f = 3.14;

    int *ptrInt = &a;
    char *ptrChar = &c;
    float *ptrFloat = &f;

    printf("Using variables:\n");
    printf("int: %d\n", a);
    printf("char: %c\n", c);
    printf("float: %.2f\n", f);

    //(dereferencing)
    printf("\nUsing pointers (dereferencing):\n");
    printf("int: %d\n", *ptrInt);
    printf("char: %c\n", *ptrChar);
    printf("float: %.2f\n", *ptrFloat);

    // Print addresses stored in the pointers
    printf("\nAddresses stored in pointers:\n");
    printf("int address: %p\n", ptrInt);
    printf("char address: %p\n", ptrChar);
    printf("float address: %p\n", ptrFloat);

    printf("\nAddresses of variables:\n");
    printf("int address: %p\n", &a);
    printf("char address: %p\n", &c);
    printf("float address: %p\n", &f);

    return 0;
}
