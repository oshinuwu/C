#include <stdio.h>  //Implementation of queue
#include <stdlib.h> // For exit() function

#define max 5

int queue[max];
int front = 0;
int rear = -1;

void enqueue()
{
    int u;
    if (rear == max - 1)
    {
        printf("\n    Overflow\n");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &u);
        rear += 1;       // Move rear to the next position
        queue[rear] = u; // Insert the element at the rear position
    }
}

void dequeue()
{
    int v;
    if (front > rear)
    { // Queue is empty
        printf("\nUnderflow\n");
    }
    else
    {
        v = queue[front];
        front += 1; // Move front to the next position
        printf("\nDeleted item = %d\n", v);
    }
}

void display()
{
    int i;
    if (front > rear)
    { // Queue is empty
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue is: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]); // Printing each element in the queue
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
            exit(0); // Exit the program
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

     return 0;
}
