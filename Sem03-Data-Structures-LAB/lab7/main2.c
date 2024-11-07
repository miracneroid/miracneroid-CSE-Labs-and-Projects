/*
implement a stack using two queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};


void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

void enqueue(struct Queue *queue, int item) {
    if (queue->rear >= MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = item;
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

struct Stack {
    struct Queue queue1;
    struct Queue queue2;
};

void initStack(struct Stack *stack) {
    initQueue(&stack->queue1);
    initQueue(&stack->queue2);
}

void push(struct Stack *stack, int item) {
    enqueue(&stack->queue1, item);
}

int pop(struct Stack *stack) {
    if (isEmpty(&stack->queue1) && isEmpty(&stack->queue2)) {
        printf("Stack is empty\n");
        return -1; 
    }

    if (isEmpty(&stack->queue2)) {
        while (!isEmpty(&stack->queue1)) {
            enqueue(&stack->queue2, dequeue(&stack->queue1));
        }
    }

    int item = dequeue(&stack->queue2);
    return item;
}

void displayStack(struct Stack *stack) {
    printf("Stack Contents: ");
    while (!isEmpty(&stack->queue1) || !isEmpty(&stack->queue2)) {
        if (!isEmpty(&stack->queue2)) {
            int item = dequeue(&stack->queue2);
            printf("%d ", item);
            enqueue(&stack->queue1, item);
        } else {
            int item = dequeue(&stack->queue1);
            printf("%d ", item);
            enqueue(&stack->queue2, item);
        }
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    displayStack(&stack);

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    push(&stack, 4);
    displayStack(&stack);
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    return 0;
}
