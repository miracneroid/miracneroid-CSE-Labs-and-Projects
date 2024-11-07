#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 30
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 5

int buffer[BUFFER_SIZE];
int buffer_index = 0;
int items_produced = 0;
int items_consumed = 0;

sem_t *empty_slots, *filled_slots, *mutex;

void insert_item(int item) {
    buffer[buffer_index] = item;
    buffer_index = (buffer_index + 1) % BUFFER_SIZE;
}

int remove_item() {
    int item = buffer[buffer_index];
    buffer_index = (buffer_index + 1) % BUFFER_SIZE;
    return item;
}

void* producer(void* arg) {
    int id = *(int*)arg;
    int item;

    while (1) {
        item = rand() % 100; // Produce a random data item
        sem_wait(empty_slots); // Acquire an empty slot
        sem_wait(mutex); // Acquire the mutex

        if (buffer_index == BUFFER_SIZE) {
            printf("Producer %d: Buffer is full, cannot produce item %d\n", id, item);
        } else {
            insert_item(item);
            printf("Producer %d: Produced item %d\n", id, item);
            items_produced++;
        }

        sem_post(mutex); // Release the mutex
        sem_post(filled_slots); // Signal a filled slot
        sleep(1); // Simulate some delay
    }
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    int item;

    while (1) {
        sem_wait(filled_slots); // Acquire a filled slot
        sem_wait(mutex); // Acquire the mutex

        if (buffer_index == 0) {
            printf("Consumer %d: Buffer is empty, cannot consume\n", id);
        } else {
            item = remove_item();
            printf("Consumer %d: Consumed item %d\n", id, item);
            items_consumed++;
        }

        sem_post(mutex); // Release the mutex
        sem_post(empty_slots); // Signal an empty slot
        sleep(1); // Simulate some delay
    }
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int producer_ids[NUM_PRODUCERS], consumer_ids[NUM_CONSUMERS];

    sem_unlink("/empty_slots"); // Remove previous semaphores if they exist
    sem_unlink("/filled_slots");
    sem_unlink("/mutex");

    empty_slots = sem_open("/empty_slots", O_CREAT, 0644, BUFFER_SIZE); // Initialize empty slots semaphore
    filled_slots = sem_open("/filled_slots", O_CREAT, 0644, 0); // Initialize filled slots semaphore
    mutex = sem_open("/mutex", O_CREAT, 0644, 1); // Initialize mutex

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producer_ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumer_ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    // Wait for some time to observe the program execution
    sleep(30);

    // Print the final statistics
    printf("\nTotal items produced: %d\n", items_produced);
    printf("Total items consumed: %d\n", items_consumed);

    // Clean up
    sem_unlink("/empty_slots");
    sem_unlink("/filled_slots");
    sem_unlink("/mutex");

    return 0;
}