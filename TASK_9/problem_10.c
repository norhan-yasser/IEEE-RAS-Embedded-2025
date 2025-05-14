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

int isEmpty() {
    return front == -1 || front > rear;
}

int isFull() {
    return rear >= SIZE - 1;
}

char getFront() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

char getRear() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[rear];
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue('A');
    enqueue('B');
    enqueue('C');

    printf("Front value: %c\n", getFront());
    printf("Rear value: %c\n", getRear());

    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is the queue full? %s\n", isFull() ? "Yes" : "No");

    dequeue();
    dequeue();

    printf("After two dequeues:\n");
    printf("Front value: %c\n", getFront());
    printf("Rear value: %c\n", getRear());
    printf("Is the queue empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is the queue full? %s\n", isFull() ? "Yes" : "No");

    return 0;
}
