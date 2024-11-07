/*
1.2 Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i].
Input Array: 3 4 5 1 2
Output Array: 3 7 12 13 15
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int size, i;
    int *array, *prefixSum;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fscanf(file, "%d", &size);

    array = (int*)malloc(size * sizeof(int));
    prefixSum = (int*)malloc(size * sizeof(int));
    if (array == NULL || prefixSum == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    printf("Data read from the file:\n");
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
        printf("%d ", array[i]);
    }
    printf("\n");

    fclose(file);

    prefixSum[0] = array[0];
    for (i = 1; i < size; i++) {
        prefixSum[i] = prefixSum[i - 1] + array[i];
    }

    printf("Prefix Sum Array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    free(array);
    free(prefixSum);

    return 0;
}
