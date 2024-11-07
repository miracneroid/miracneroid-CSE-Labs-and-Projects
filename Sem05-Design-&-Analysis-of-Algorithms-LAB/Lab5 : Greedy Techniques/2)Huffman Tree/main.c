#include <stdio.h>
#include <stdlib.h>

struct SYMBOL {
    char alphabet;
    int frequency;
};

struct Node {
    char alphabet;
    int frequency;
    struct Node *left, *right;
};

struct Node* createNode(char alphabet, int frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->alphabet = alphabet;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct MinHeap {
    int size;
    int capacity;
    struct Node** array;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

void swapNode(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeap* createAndBuildMinHeap(struct SYMBOL symbols[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(symbols[i].alphabet, symbols[i].frequency);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct Node* buildHuffmanTree(struct SYMBOL symbols[], int size) {
    struct Node *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(symbols, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        if (root->alphabet != '$') {  
            printf("%c ", root->alphabet);
        }
        inOrderTraversal(root->right);
    }
}

int main() {
    int n;

    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);  
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* root = buildHuffmanTree(symbols, n);
    
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
