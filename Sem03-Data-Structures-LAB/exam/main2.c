#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

// Structure for the heap
struct Heap {
    int arr[MAX_HEAP_SIZE];
    int size;
};

// Function to create an empty heap
struct Heap* createHeap() {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->size = 0;
    return heap;
}

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index i
void heapify(struct Heap* heap, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    // If largest is not root, swap and recursively heapify the affected sub-tree
    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

// Function to insert a new element into the heap
void insertElement(struct Heap* heap, int value) {
    if (heap->size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    heap->arr[heap->size] = value;
    int index = heap->size;
    heap->size++;

    // Fix the heap property if it is violated
    while (index > 0 && heap->arr[index] > heap->arr[(index - 1) / 2]) {
        swap(&heap->arr[index], &heap->arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to delete the root (maximum) element from the heap
int deleteRoot(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty. Cannot delete root.\n");
        return -1; // Returning a sentinel value to indicate an error
    }

    // Store the root element to return later
    int root = heap->arr[0];

    // Replace the root with the last element in the heap
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the root to maintain the heap property
    heapify(heap, 0);

    return root;
}

// Function to print the elements of the heap
void printHeap(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for the heap
void freeHeap(struct Heap* heap) {
    free(heap);
}

int main() {
    struct Heap* heap = createHeap();

    insertElement(heap, 10);
    insertElement(heap, 20);
    insertElement(heap, 15);
    insertElement(heap, 40);
    insertElement(heap, 50);
    insertElement(heap, 100);

    printf("Heap after insertion: ");
    printHeap(heap);

    int root = deleteRoot(heap);
    if (root != -1) {
        printf("Root deleted: %d\n", root);
    }

    printf("Heap after deletion: ");
    printHeap(heap);

    // Free the memory allocated for the heap
    freeHeap(heap);

    return 0;
}
