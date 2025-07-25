//WAP to simulate the solution of producer consumer problem using message passing technique. 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5 // Buffer size

typedef struct {
    int data;
    int valid;
} message;

message buffer[N];
int in = 0, out = 0;
int PRODUCE_COUNT = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void build_message(message* m, int item) {
    m->data = item;
    m->valid = 1;
}

int extract_item(message* m) {
    return m->data;
}

int produce_item(int count) {
    return count + 1;
}

void consume_item(int item) {
    printf("Consumed: %d\n", item);
}

void send_msg_to_buffer(message* m) {
    pthread_mutex_lock(&mutex);
    while (((in + 1) % N) == out) {
        pthread_cond_wait(&not_full, &mutex); // Buffer full
    }
    buffer[in] = *m;
    in = (in + 1) % N;
    pthread_cond_signal(&not_empty);
    pthread_mutex_unlock(&mutex);
}

void receive_msg_from_buffer(message* m) {
    pthread_mutex_lock(&mutex);
    while (in == out) {
        pthread_cond_wait(&not_empty, &mutex); // Buffer empty
    }
    *m = buffer[out];
    out = (out + 1) % N;
    pthread_cond_signal(&not_full);
    pthread_mutex_unlock(&mutex);
}

void* producer(void* arg) {
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        int item = produce_item(i);
        message m;
        build_message(&m, item);
        printf("Produced: %d\n", item);
        send_msg_to_buffer(&m);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < PRODUCE_COUNT; i++) {
        message m;
        receive_msg_from_buffer(&m);
        int item = extract_item(&m);
        consume_item(item);
        sleep(2);
    }
    return NULL;
}

int main() {
    printf("Enter number of items to produce and consume: ");
    scanf("%d", &PRODUCE_COUNT);

    if (PRODUCE_COUNT <= 0) {
        printf("Invalid count. Exiting.\n");
        return 1;
    }

    pthread_t prod, cons;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    printf("All items produced and consumed successfully.\n");
    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:4-c\n Sec:A");
    getchar();
    getchar();
    return 0;
}
