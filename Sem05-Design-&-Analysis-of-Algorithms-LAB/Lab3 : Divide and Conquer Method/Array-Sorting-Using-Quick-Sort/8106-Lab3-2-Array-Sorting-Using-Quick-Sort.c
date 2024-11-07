/*
3.2 Aim of the program: Write a menu driven program to sort a list of elements in ascending
order using Quick Sort technique. Each choice for the input data has its own disc file. A separate
output file can be used for sorted elements. After sorting display the content of the output file
along with number of comparisons. Based on the partitioning position for each recursive call,
conclude the input scenario is either best-case partitioning or worst-case partitioning.
Note#
● The worst-case behavior for quicksort occurs when the partitioning routine produces one
subproblem with n-1 elements and one with 0 elements. The best-case behaviour

occurred in most even possible split, PARTITION produces two subproblems, each of
size no more than n/2.
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40.....,
Store the result in “outQuickAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60....,
Store the result in “outQuickDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 ...,
Store the result in “outQuickRand.dat”
Sample Input from file:
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)
Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case
*/

#include <stdio.h>
#include <stdlib.h>

int comparisons = 0;
int worst_case_count = 0;

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Check if partitioning is worst-case
        if (pi == low || pi == high) {
            worst_case_count++;
        }

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputFile = "inAsce.dat";
                outputFile = "outQuickAsce.dat";
                break;
            case 2:
                inputFile = "inDesc.dat";
                outputFile = "outQuickDesc.dat";
                break;
            case 3:
                inputFile = "inRand.dat";
                outputFile = "outQuickRand.dat";
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
        worst_case_count = 0;
        quickSort(arr, 0, size - 1);

        writeArray(outputFile, arr, size);
        printf("After Sorting: ");
        displayArray(arr, size);

        printf("Number of Comparisons: %d\n", comparisons);
        if (worst_case_count > 0) {
            printf("Scenario: Worst-case\n");
        } else {
            printf("Scenario: Best-case\n");
        }
    }

    return 0;
}
