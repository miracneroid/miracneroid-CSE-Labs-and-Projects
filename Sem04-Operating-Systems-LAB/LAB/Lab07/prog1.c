#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 2

pthread_t tid[NUM_THREADS];

void* doSomeThing(void *arg) {
    unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id, tid[0]))
        printf("\nFirst thread processing\n");
    else
        printf("\nSecond thread processing\n");

    for(i = 0; i < (0xFFFFFFFF); i++); // Intentional busy-wait loop for demonstration

    return NULL;
}

int main() {
    int i, err;

    for(i = 0; i < NUM_THREADS; i++) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\nCan't create thread :[%s]", strerror(err));
        else
            printf("\nThread %d created successfully\n", i);
    }

    sleep(5); // Added sleep for 5 seconds to allow threads to finish execution

    return 0;
}
