#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5 // Buffer size

int buffer[N];
int in = 0, out = 0;
int COUNT;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void consume_item(int item, int i) {
    printf("Consumed [%d]: %d\n", i + 1, item);
}

void insert_item(int item) {
    buffer[in] = item;
    in = (in + 1) % N;
}

int remove_item() {
    int item = buffer[out];
    out = (out + 1) % N;
    return item;
}

void* producer(void* arg) {
    int* items = (int*)arg;
    for (int i = 0; i < COUNT; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        insert_item(items[i]);
        printf("Produced [%d]: %d\n", i + 1, items[i]);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < COUNT; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = remove_item();

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        consume_item(item, i);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    printf("Enter number of items to produce and consume: ");
    scanf("%d", &COUNT);

    int* items = (int*)malloc(COUNT * sizeof(int));
    if (!items) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d items:\n", COUNT);
    for (int i = 0; i < COUNT; i++) {
        scanf("%d", &items[i]);
    }

    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, items);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    free(items);

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:4-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}
