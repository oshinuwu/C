//WAP to simulate the solution of dining philosopher's problem using semaphore. 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int* state;
sem_t mutex;
sem_t* S;
int N; // Number of philosophers
int EAT_COUNT; // Number of times each philosopher eats

#define THINKING 0
#define HUNGRY 1
#define EATING 2

#define LEFT(i) ((i + N - 1) % N)
#define RIGHT(i) ((i + 1) % N)

void test(int i) {
    if (state[i] == HUNGRY &&
        state[LEFT(i)] != EATING &&
        state[RIGHT(i)] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d\n", i + 1, LEFT(i) + 1, RIGHT(i) + 1);
        printf("Philosopher %d is EATING\n", i + 1);
        sem_post(&S[i]);
    }
}

void take_forks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is HUNGRY\n", i + 1);
    test(i);
    sem_post(&mutex);
    sem_wait(&S[i]);
}

void put_forks(int i) {
    sem_wait(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d puts down forks %d and %d\n", i + 1, LEFT(i) + 1, RIGHT(i) + 1);
    printf("Philosopher %d is THINKING\n", i + 1);
    test(LEFT(i));
    test(RIGHT(i));
    sem_post(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    for (int eat_times = 0; eat_times < EAT_COUNT; eat_times++) {
        sleep(1); // Thinking
        take_forks(i);
        sleep(2); // Eating
        put_forks(i);
    }
    printf("Philosopher %d has finished eating %d times.\n", i + 1, EAT_COUNT);
    return NULL;
}

int main() {
    printf("Enter number of philosophers: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("At least 2 philosophers are needed.\n");
        return 1;
    }

    printf("Enter number of times each philosopher should eat: ");
    scanf("%d", &EAT_COUNT);

    pthread_t* thread_id = malloc(N * sizeof(pthread_t));
    int* phil = malloc(N * sizeof(int));
    state = malloc(N * sizeof(int));
    S = malloc(N * sizeof(sem_t));

    sem_init(&mutex, 0, 1);
    for (int i = 0; i < N; i++) {
        sem_init(&S[i], 0, 0);
        state[i] = THINKING;
        phil[i] = i;
        printf("Philosopher %d is THINKING\n", i + 1);
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < N; i++) {
        sem_destroy(&S[i]);
    }
    sem_destroy(&mutex);
    free(thread_id);
    free(phil);
    free(state);
    free(S);

    printf("All philosophers have finished eating.\n");

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:4-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}
