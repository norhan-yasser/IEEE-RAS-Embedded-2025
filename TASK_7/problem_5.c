#include <stdio.h>

// Define enum with ASCII values of operators
typedef enum {
    ADD  = '+',  // 43
    SUB  = '-',  // 45
    MUL  = '*',  // 42
    DIV  = '/',  // 47
    AND  = '&',  // 38 (bitwise AND)
    OR   = '|',  // 124 (bitwise OR)
    NOT  = '!'   // 33 (logical NOT)
} Operation;

int main() {
    int operand1, operand2;
    char op_char;

    printf("Enter first operand: ");
    scanf("%d", &operand1);

    printf("Enter second operand: ");
    scanf("%d", &operand2);

    printf("Enter operation (+, -, *, /, &, |, !): ");
    scanf(" %c", &op_char);

    switch ((Operation)op_char) {
        case ADD:
            printf("Result: %d\n", operand1 + operand2);
            break;
        case SUB:
            printf("Result: %d\n", operand1 - operand2);
            break;
        case MUL:
            printf("Result: %d\n", operand1 * operand2);
            break;
        case DIV:
            if (operand2 != 0)
                printf("Result: %d\n", operand1 / operand2);
            else
                printf("Error: Division by zero\n");
            break;
        case AND:
            printf("Result: %d\n", operand1 & operand2);
            break;
        case OR:
            printf("Result: %d\n", operand1 | operand2);
            break;
        case NOT:
            printf("Result: !%d = %d and !%d = %d\n", operand1, !operand1, operand2, !operand2);
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}
