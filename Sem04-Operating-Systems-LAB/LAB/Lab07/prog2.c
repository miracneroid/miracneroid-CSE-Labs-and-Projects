#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // for getpid

void *func(void *p) {
    printf("Thread ID is ---> %ld\n", (long)pthread_self());
    return NULL;
}

int main() {
    printf("Parent ID is ---> %ld\n", (long)getpid());
    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    pthread_join(tid, NULL);
    printf("No more thread id!\n");
    return 0;
}
