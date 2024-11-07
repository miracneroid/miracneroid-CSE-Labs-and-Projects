#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to check if the linked list contains a loop
int hasLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a loop, the fast pointer will eventually catch up with the slow pointer
        if (slow == fast) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    struct Node* head = NULL;

    // Create a linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);

    // Create a loop in the linked list for testing
    head->next->next->next->next = head->next;

    // Check if the linked list has a loop
    if (hasLoop(head)) {
        printf("The linked list has a loop.\n");
    } else {
        printf("The linked list does not have a loop.\n");
    }

    // Display the linked list (for visualization purposes)
    printf("Linked List: ");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
