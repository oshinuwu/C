#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create and initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue operation (insert at the rear)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) { // Queue is empty
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode; // Add the new node at the rear
    q->rear = newNode;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation (remove from the front)
int dequeue(struct Queue* q) {
    if (q->front == NULL) { // Queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    
    // If front becomes NULL, set rear to NULL too (queue is empty)
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

// Function to display the queue elements
void displayQueue(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();

    // Perform some operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q); // Display queue

    printf("Dequeued: %d\n", dequeue(q)); // Dequeue an element
    displayQueue(q);

    enqueue(q, 40);
    displayQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    dequeue(q); // Trying to dequeue from an empty queue

    return 0;
}

