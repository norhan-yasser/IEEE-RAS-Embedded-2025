#include <stdio.h>

int main() {
    int num1, num2;
    int *ptr1, *ptr2;


    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    ptr1 = &num1;
    ptr2 = &num2;


    printf("\nSum = %d\n", *ptr1 + *ptr2);
    printf("Difference = %d\n", *ptr1 - *ptr2);
    printf("Product = %d\n", (*ptr1) * (*ptr2));


    return 0;
}
