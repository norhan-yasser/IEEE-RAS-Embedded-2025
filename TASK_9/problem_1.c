#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printListAndLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    printf("Train (Linked List): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        length++;
    }
    printf("NULL\n");
    printf("Length of the train: %d\n", length);
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printListAndLength(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
