/*
read ab array a[100]
create two seperate threads, one under paretn and anotehr under child 
fubd 2nd largest of the arry by parent thread 
fubd 2nd largest of the array by child thread 
combine the results and display
*/

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

#define ARRAY_SIZE 100

int a[ARRAY_SIZE];

struct ThreadArgs {
    int start_index;
    int end_index;
    int second_largest;
};

void *findSecondLargest(void *args) {
    struct ThreadArgs *thread_args = (struct ThreadArgs *)args;
    int start_index = thread_args->start_index;
    int end_index = thread_args->end_index;
    int second_largest = thread_args->second_largest;

    for (int i = start_index; i < end_index; i++) {
        if (a[i] > second_largest && a[i] != thread_args->second_largest) {
            second_largest = a[i];
        }
    }

    thread_args->second_largest = second_largest;
    return NULL;
}

int main() {
    pthread_t parent_tid, child_tid;
    int second_largest_parent = 0, second_largest_child = 0;

    printf("Enter %d elements of the array:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &a[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        struct ThreadArgs args = {ARRAY_SIZE / 2, ARRAY_SIZE, 0};
        pthread_create(&child_tid, NULL, findSecondLargest, (void *)&args);
        pthread_join(child_tid, NULL);
        second_largest_child = args.second_largest;
    } else if (pid > 0) {
        struct ThreadArgs args = {0, ARRAY_SIZE / 2, 0};
        pthread_create(&parent_tid, NULL, findSecondLargest, (void *)&args);
        pthread_join(parent_tid, NULL);
        second_largest_parent = args.second_largest;
    } else {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    int second_largest = (second_largest_parent > second_largest_child) ? second_largest_parent : second_largest_child;

    printf("The second largest element in the array is: %d\n", second_largest);

    return 0;
}

