#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int getLength() {
    if (head == NULL) return 0;
    int count = 1;
    struct Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    int length = getLength();
    if (position < 1 || position > length + 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insertAtPosition(10, 1);
    insertAtPosition(20, 2);
    insertAtPosition(30, 3);
    insertAtPosition(25, 3);
    insertAtPosition(5, 1);

    display();

    return 0;
}
