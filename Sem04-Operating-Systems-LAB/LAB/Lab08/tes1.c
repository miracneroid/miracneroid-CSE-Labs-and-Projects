#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0; // Global shared variable

void *func1() {
    int x;
    x = shared; // Thread one reads value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);
    x++; // Thread one increments its value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // Thread one is preempted by thread2
    shared = x; // Thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    pthread_exit(NULL); // Return NULL as the thread's return value
}

void *func2() {
    int y;
    y = shared; // Thread two reads value of shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--; // Thread two decrements its value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1); // Thread two is preempted by thread1
    shared = y; // Thread two updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    pthread_exit(NULL); // Return NULL as the thread's return value
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);
    // Prints the last updated value of shared variable

    return 0;
}