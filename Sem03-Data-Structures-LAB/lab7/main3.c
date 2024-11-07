/*
Write a program to delete odd number from an array of integers
*/

#include <stdio.h>

int main() {
    int originalArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(originalArray) / sizeof(originalArray[0]);
    
    int evenArray[n];
    int evenCount = 0;

    for (int i = 0; i < n; i++) {
        if (originalArray[i] % 2 == 0) {
            evenArray[evenCount] = originalArray[i];
            evenCount++;
        }
    }

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    printf("Array with Odd Numbers Deleted: ");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenArray[i]);
    }
    printf("\n");

    return 0;
}

