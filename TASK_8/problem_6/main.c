#include <stdio.h>
#include "math.h"

int main() {
    Pair p;

    printf("Enter two integers: ");
    scanf("%d %d", &p.a, &p.b);

    printf("\nUsing standard parameter functions:\n");
    printf("Addition: %d\n", add(p.a, p.b));
    printf("Subtraction: %d\n", subtract(p.a, p.b));
    printf("Multiplication: %d\n", multiply(p.a, p.b));
    printf("Division: %.2f\n", divide(p.a, p.b));
    printf("Exponentiation: %d\n", power(p.a, p.b));

    printf("\nUsing struct-based functions:\n");
    printf("Addition: %d\n", add_pair(p));
    printf("Subtraction: %d\n", subtract_pair(p));
    printf("Multiplication: %d\n", multiply_pair(p));
    printf("Division: %.2f\n", divide_pair(p));
    printf("Exponentiation: %d\n", power_pair(p));

    return 0;
}
