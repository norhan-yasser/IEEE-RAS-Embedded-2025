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

int main() {
    push(10);
    push(20);
    push(30);

    int poppedValue = pop();
    printf("Popped value: %d\n", poppedValue);

    return 0;
}
