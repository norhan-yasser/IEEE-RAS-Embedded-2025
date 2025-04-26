#include <stdio.h>


float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    int choice;
    float num1, num2, result;
    float (*operation)(float, float);



    printf("Simple Calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }


    printf("Enter two numbers: ");
    scanf("%f", &num1);
    scanf("%f", &num2);

    result = operation(num1, num2);
    printf("Result: %.2f\n", result);

    return 0;
}

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}
