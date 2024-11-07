#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>  // Include the <string.h> header for strlen

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Key not found
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

        // Convert the sorted array to a string
        char sortedArrayStr[256];
        sprintf(sortedArrayStr, "%d", arr[0]);
        for (int i = 1; i < n; i++) {
            sprintf(sortedArrayStr + strlen(sortedArrayStr), " %d", arr[i]);
        }

        // Execute the binary search program in the child process
        char *args[] = {"binary_search_program", sortedArrayStr, NULL};
        execve("./binary_search_program", args, NULL);

        // If execve fails
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        // Wait for the child process to complete
        wait(NULL);

        printf("Parent process sorted the array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
