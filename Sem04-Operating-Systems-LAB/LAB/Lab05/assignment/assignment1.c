#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to perform merge sort
void merge(int arr[], int l, int m, int r) {
    // Merge two subarrays arr[l..m] and arr[m+1..r]
    // ...

}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    // Quick sort implementation
    // ...
}

int main() {
    int n;

    // Input size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Forking a child process
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process sorting using Quick Sort:\n");
        quickSort(arr, 0, n - 1);
        printf("Sorted array in child process: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Parent process
        // Wait for the child process to complete
        wait(NULL);

        printf("Parent process sorting using Merge Sort:\n");
        mergeSort(arr, 0, n - 1);

        printf("Sorted array in parent process: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
