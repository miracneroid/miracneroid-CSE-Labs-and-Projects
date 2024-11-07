#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main() {
    int rc1, rc2;
    pthread_t thread1, thread2;

    if ((rc1 = pthread_create(&thread1, NULL, &functionC, NULL)))
        printf("Thread creation failed: %d\n", rc1);

    if ((rc2 = pthread_create(&thread2, NULL, &functionC, NULL)))
        printf("Thread creation failed: %d\n", rc2);


    /* Wait till threads are complete before main continues. Unless we */
    /* wait we run the risk of executing an exit which will terminate */
    /* the process and all threads before the threads have completed. */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}

void *functionC() {
    pthread_mutex_lock(&mutex1);
    counter++;
    printf("Counter value: %d\n", counter);
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL); // Return NULL as the thread's return value
}

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func1();
void *func2();
int shared = 1; // Shared variable
pthread_mutex_t l; // Mutex lock

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