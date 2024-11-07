/*
1.1 Aim of the program: Write a program to find out the second smallest and second largest
element stored in an array of n integers. Read the data from a file store it in an array and then perform operation.
Input: Size of the array is „n‟ and read „n‟ number of elements from a disc file.
Output: Second smallest, Second largest
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    int size, i;
    int *array;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fscanf(file, "%d", &size);

    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);

    qsort(array, size, sizeof(int), compare);

    int second_smallest = array[1];
    int second_largest = array[size - 2];

    printf("Second smallest number: %d\n", second_smallest);
    printf("Second largest number: %d\n", second_largest);

    free(array);

    return 0;
}
