/*
Write a program to swap nodes in the following patterns such that fist nodes swapped to last, second node swapped to last second....and so on
*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void swapNodesInPattern(struct Node** head) {
    struct Node* current = *head;
    struct Node* last = NULL;

    while (current != NULL) {
        if (current->next == last) {
            break;
        }

        struct Node* temp = current;
        current = current->next;

        temp->next = last;
        last = temp;
    }

    *head = last;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Original Linked List:\n");
    printLinkedList(head);

    swapNodesInPattern(&head);

    printf("Linked List with Nodes Swapped:\n");
    printLinkedList(head);

    return 0;
}
