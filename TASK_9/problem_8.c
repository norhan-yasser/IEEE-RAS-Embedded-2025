#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top >= SIZE - 1) return;
    stack[++top] = value;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

void swapTopElements() {
    if (top < 1) {
        printf("Not enough elements to swap\n");
        return;
    }
    int temp = stack[top];
    stack[top] = stack[top - 1];
    stack[top - 1] = temp;
}

void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Before swap:\n");
    printStack();

    swapTopElements();

    printf("After swap:\n");
    printStack();

    return 0;
}
