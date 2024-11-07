#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 100

int a[ARRAY_SIZE];
int largest = 0, second_largest = 0;

void *findLargestAndSecondLargest(void *args) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (a[i] > largest) {
            second_largest = largest;
            largest = a[i];
        } else if (a[i] > second_largest && a[i] != largest) {
            second_largest = a[i];
        }
    }
    return NULL;
}

int main() {
    pthread_t tid;

    printf("Enter %d elements of the array:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &a[i]);
    }

    pthread_create(&tid, NULL, findLargestAndSecondLargest, NULL);
    findLargestAndSecondLargest(NULL); // Parent thread also computes the values
    pthread_join(tid, NULL);

    printf("The second largest element in the array is: %d\n", second_largest);

    return 0;
}
