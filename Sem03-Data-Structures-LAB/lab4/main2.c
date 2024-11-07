#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
    } else {
        s->items[++s->top] = c;
    }
}

// Pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character as an error value
    } else {
        return s->items[s->top--];
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input
    input[strcspn(input, "\n")] = '\0';

    struct Stack stack;
    initialize(&stack);

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(input); i++) {
        push(&stack, input[i]);
    }

    printf("Reversed string: ");
    
    // Pop characters from the stack to construct the reversed string
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    
    printf("\n");

    return 0;
}
