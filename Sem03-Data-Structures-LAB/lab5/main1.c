/*
Implement a single linked list and perform the following operations.
1)insertion at beginning
2)insertion at some position
3)insertion at last
4)deletion at beginning
5)deletion at some position
6)deletion at last
7)count the no of nodes
8)set the list
9)display the list using recurssion and without recurssion
10)display in reverse order using recurssion
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the head of the linked list
struct Node* head = NULL;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node* current = head;
    int count = 1;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to insert a node at the end of the linked list
void insertAtLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node at the beginning of the linked list
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    if (position == 1) {
        head = head->next;
        free(current);
        return;
    }

    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
    } else {
        prev->next = current->next;
        free(current);
    }
}

// Function to delete the last node of the linked list
void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Function to count the number of nodes in the linked list
int countNodes() {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to set the list by deleting all nodes
void setList() {
    while (head != NULL) {
        deleteAtBeginning();
    }
}

// Function to display the list using recursion
void displayRecursive(struct Node* current) {
    if (current == NULL) {
        printf("\n");
        return;
    }

    printf("%d -> ", current->data);
    displayRecursive(current->next);
}

// Function to display the list without recursion
void displayWithoutRecursion() {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to display the list in reverse order using recursion
void displayReverseRecursive(struct Node* current) {
    if (current == NULL) {
        return;
    }

    displayReverseRecursive(current->next);
    printf("%d -> ", current->data);
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Insertion at beginning\n");
        printf("2) Insertion at some position\n");
        printf("3) Insertion at last\n");
        printf("4) Deletion at beginning\n");
        printf("5) Deletion at some position\n");
        printf("6) Deletion at last\n");
        printf("7) Count the number of nodes\n");
        printf("8) Set the list\n");
        printf("9) Display the list using recursion\n");
        printf("10) Display the list without recursion\n");
        printf("11) Display in reverse order using recursion\n");
        printf("12) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 6:
                deleteAtLast();
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 8:
                setList();
                printf("List is set to empty.\n");
                break;
            case 9:
                printf("List (recursive): ");
                displayRecursive(head);
                break;
            case 10:
                printf("List (non-recursive): ");
                displayWithoutRecursion();
                break;
            case 11:
                printf("List in reverse order (recursive): ");
                displayReverseRecursive(head);
                printf("\n");
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

