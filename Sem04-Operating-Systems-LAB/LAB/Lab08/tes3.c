#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func1();
void *func2();
int shared = 1; // Shared variable
pthread_mutex_t l; // Mutex lock

int main() {
    pthread_mutex_init(&l, NULL); // Initializing mutex lock

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared is %d\n", shared);
    // Prints the last updated value of shared variable

    return 0;
}

void *func1() {
    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    // Thread one acquires the lock. Now thread 2 will not be able to
    // acquire the lock until it is unlocked by thread 1
    printf("Thread1 acquired lock\n");
    x = shared; // Thread one reads value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);
    x++; // Thread one increments its value
    printf("Local updation by Thread1: %d\n", x);
    sleep(1); // Thread one is preempted by thread 2
    shared = x; // Thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread1 released the lock\n");
    pthread_exit(NULL); // Return NULL as the thread's return value
}

void *func2() {
    int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&l);
    printf("Thread2 acquired lock\n");
    y = shared; // Thread two reads value of shared variable
    printf("Thread2 reads the value as %d\n", y);
    y--; // Thread two decrements its value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1); // Thread two is preempted by thread 1
    shared = y; // Thread two updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    pthread_mutex_unlock(&l);
    printf("Thread2 released the lock\n");
    pthread_exit(NULL); // Return NULL as the thread's return value
}