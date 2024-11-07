/*
implement a queue using two stacks
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1; // Return -1 as an error value
    }
    return stack->data[stack->top--];
}

struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

void initQueue(struct Queue *queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

void enqueue(struct Queue *queue, int item) {
    push(&queue->stack1, item);
}

int dequeue(struct Queue *queue) {
    if (queue->stack1.top == -1 && queue->stack2.top == -1) {
        printf("Queue is empty\n");
        return -1; 
    }

    if (queue->stack2.top == -1) {
        while (queue->stack1.top >= 0) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    return pop(&queue->stack2);
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 4);
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}

