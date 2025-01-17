#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = MAX - 1, rear = MAX - 1;

int isFull()
{
    if ((rear + 1) % MAX == front)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == rear)
    {
        return 1;
    }
    return 0;
}

void enqueue()
{
    int value;
    if (isFull())
    {
        printf("\nQueue is Full.\n");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &value);
        rear = (rear + 1) % MAX; // Move rear to the next position
        queue[rear] = value;     // Store the value at the new rear
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is empty.\n");
    } else {
        front = (front + 1) % MAX;  // Move front to the next position
        int value = queue[front];   // Get the deleted value
        printf("\nDeleted value is %d\n", value);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        int i = front + 1; // Start from the element after front
        printf("\nQueue elements: ");
        while (i != (rear + 1) % MAX)
        { // Loop until we reach rear
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            getch();
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
