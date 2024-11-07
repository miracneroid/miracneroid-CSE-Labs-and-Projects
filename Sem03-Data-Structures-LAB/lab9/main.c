#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct HeapNode {
    int data;
};

struct MinHeap {
    struct HeapNode* array[MAX_HEAP_SIZE];
    int size;
};

struct HeapNode* createHeapNode(int data) {
    struct HeapNode* newNode = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    newNode->data = data;
    return newNode;
}

void swapNodes(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left]->data < heap->array[smallest]->data)
        smallest = left;

    if (right < heap->size && heap->array[right]->data < heap->array[smallest]->data)
        smallest = right;

    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        minHeapify(heap, smallest);
    }
}

void insertNode(struct MinHeap* heap, int data) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert more nodes.\n");
        return;
    }

    struct HeapNode* newNode = createHeapNode(data);
    heap->array[heap->size] = newNode;
    int i = heap->size;
    heap->size++;

    while (i > 0 && heap->array[(i - 1) / 2]->data > heap->array[i]->data) {
        swapNodes(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Node inserted successfully.\n");
}

void displayHeap(struct MinHeap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]->data);
    }
    printf("\n");
}

void deleteMin(struct MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }

    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    minHeapify(heap, 0);

    printf("Minimum element deleted.\n");
}

int main() {
    struct MinHeap heap;
    heap.size = 0;

    int choice, data;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert Node\n");
        printf("2. Display Heap\n");
        printf("3. Delete Minimum\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertNode(&heap, data);
                break;
            case 2:
                displayHeap(&heap);
                break;
            case 3:
                deleteMin(&heap);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


