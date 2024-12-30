#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void PUSH()
{
    int x;
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\n Enter the number");
        scanf("%d", &x);
        top += 1;
        stack[top] = x;
    }
}
void POP()
{
    int x;
    if (top == - 1)
    {
        printf("\nStack Underflow");
    }
    else
    {
        x = stack[top];
        top -= 1;
        printf("\n The popped item is %d", x);
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\n Stack is empty.");
    }
    else
    {
        printf("\n Contents of stack are:");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    printf("1.PUSH\t 2.POP\t 3.Display\t 4.Exit\n");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}