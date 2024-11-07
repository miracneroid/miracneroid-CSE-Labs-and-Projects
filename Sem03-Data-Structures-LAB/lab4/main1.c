#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1; // Initialize the top of the stack

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        stack[++top] = value;
        printf("%d pushed to the stack.\n", value);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        return stack[top--];
    }
}

int count() {
    return top + 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1) Push\n2) Pop\n3) Count\n4) Display\n5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Number of elements in the stack: %d\n", count());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

