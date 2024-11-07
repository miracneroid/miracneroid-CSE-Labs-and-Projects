/*
3.1 Aim of the program: Write a menu driven program to sort list of array elements using Merge
Sort technique and calculate the execution time only to sort the elements. Count the number of
comparisons.
Note#
● To calculate execution time, assume that single program is under execution in the CPU.
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40.....,
Store the result in “outMergeAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60....,
Store the result in “outMergeDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 ...,
Store the result in “outMergeRand.dat”

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

// Merge function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to read array from a file
int readArray(const char *fileName, int arr[]) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF) {
        i++;
    }
    fclose(file);
    return i;
}

// Function to write array to a file
void writeArray(const char *fileName, int arr[], int size) {
    FILE *file = fopen(fileName, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

// Function to display array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char *inputFile, *outputFile;
    int arr[500];
    int size;

    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputFile = "inAsce.dat";
                outputFile = "outMergeAsce.dat";
                break;
            case 2:
                inputFile = "inDesc.dat";
                outputFile = "outMergeDesc.dat";
                break;
            case 3:
                inputFile = "inRand.dat";
                outputFile = "outMergeRand.dat";
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option!\n");
                continue;
        }

        size = readArray(inputFile, arr);
        printf("Before Sorting: ");
        displayArray(arr, size);

        comparisons = 0;
        clock_t start = clock();
        mergeSort(arr, 0, size - 1);
        clock_t end = clock();
        double executionTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1e9; // nanoseconds

        writeArray(outputFile, arr, size);
        printf("After Sorting: ");
        displayArray(arr, size);

        printf("Number of Comparisons: %d\n", comparisons);
        printf("Execution Time: %lf nanoseconds\n", executionTime);
    }

    return 0;
}
