#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

char queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(char value) {
    if (rear >= SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

char dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front++];
}

int main() {
    enqueue('A');
    enqueue('B');
    enqueue('C');

    char dequeuedValue = dequeue();
    printf("Dequeued value: %c\n", dequeuedValue);

    return 0;
}
