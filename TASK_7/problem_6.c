#include <stdio.h>


union Data {
    int a;
    float b;
    char c;
};

int main() {
    union Data d;

    //Assign a value to a
    d.a = 97;
    printf("After assigning d.a = 97:\n");
    printf("d.a = %d\n", d.a);
    printf("d.b = %f\n", d.b);
    printf("d.c = %c\n\n", d.c);

    // Assign a value to b
    d.b = 3.14;
    printf("After assigning d.b = 3.14:\n");
    printf("d.a = %d\n", d.a);
    printf("d.b = %f\n", d.b);
    printf("d.c = %c\n\n", d.c);

    // Assign a value to c
    d.c = 'Z';
    printf("After assigning d.c = 'Z':\n");
    printf("d.a = %d\n", d.a);
    printf("d.b = %f\n", d.b);
    printf("d.c = %c\n", d.c);

    return 0;
}
