/*
1.3 Aim of the program: Write a program to read „n‟ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array.

*Sort the array in ascending order.
*Display the array

a) Find out the total number of duplicate elements.
b) Find out the most repeating element in the array.

Input:
Enter how many numbers you want to read from file: 15
Output:
The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
Total number of duplicate values = 4
The most repeating element in the array = 10
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    int size, i, total_duplicates = 0, max_count = 0, most_repeating = 0;
    int *array;

    // Open the file in read mode
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the size of the array
    fscanf(file, "%d", &size);

    // Allocate memory for the array
    array = (int*)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read the numbers into the array
    printf("Data read from the file:\n");
    for (i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
        printf("%d ", array[i]);
    }
    printf("\n");

    // Close the file
    fclose(file);

    // Sort the array
    qsort(array, size, sizeof(int), compare);

    // Display the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Count duplicates and find the most repeating element
    int current_count = 1;
    for (i = 1; i < size; i++) {
        if (array[i] == array[i - 1]) {
            current_count++;
            if (current_count == 2) {
                total_duplicates++;
            }
            if (current_count > max_count) {
                max_count = current_count;
                most_repeating = array[i];
            }
        } else {
            current_count = 1;
        }
    }

    // Print the results
    printf("Total number of duplicate values = %d\n", total_duplicates);
    printf("The most repeating element in the array = %d\n", most_repeating);

    // Free allocated memory
    free(array);

    return 0;
}
