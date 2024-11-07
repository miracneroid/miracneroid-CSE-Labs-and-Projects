#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 3

sem_t wrt; // Semaphore for writers
sem_t mutex; // Mutex to ensure mutual exclusion
int readcount = 0; // Count of readers currently reading

void* reader(void* arg) {
    int id = *(int*)arg;
    printf("Reader %d is trying to read...\n", id);

    sem_wait(&mutex); // Acquire mutex
    readcount++;
    if (readcount == 1) {
        sem_wait(&wrt); // If this is the first reader, acquire write semaphore
    }
    sem_post(&mutex); // Release mutex

    printf("Reader %d is reading...\n", id);
    // Read shared data here...

    sem_wait(&mutex); // Acquire mutex
    readcount--;
    if (readcount == 0) {
        sem_post(&wrt); // If this is the last reader, release write semaphore
    }
    sem_post(&mutex); // Release mutex

    printf("Reader %d has finished reading.\n", id);
    pthread_exit(NULL);
}

void* writer(void* arg) {
    int id = *(int*)arg;
    printf("Writer %d is trying to write...\n", id);

    sem_wait(&wrt); // Acquire write semaphore

    printf("Writer %d is writing...\n", id);
    // Write shared data here...

    sem_post(&wrt); // Release write semaphore

    printf("Writer %d has finished writing.\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
    int reader_ids[NUM_READERS], writer_ids[NUM_WRITERS];

    sem_unlink("/wrt"); // Remove previous semaphores if they exist
    sem_unlink("/mutex");

    sem_open("/wrt", O_CREAT, 0644, 1); // Initialize write semaphore
    sem_open("/mutex", O_CREAT, 0644, 1); // Initialize mutex

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for all reader and writer threads to finish
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_unlink("/wrt"); // Remove semaphores after use
    sem_unlink("/mutex");

    return 0;
}