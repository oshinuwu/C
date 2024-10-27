#include <stdio.h>

int factorial(int n)
{

    // Base case: 0! = 1

    if (n == 0)
    {

        return 1;
    }

    // Recursive case: n! = n * (n-1)!

    else
    {

        return n * factorial(n - 1);
    }
}

int main()
{

    int n;

    printf("Enter a number: ");

    scanf("%d", &n);

    if (n < 0)
    {

        printf("Error: Factorial is not defined for negative numbers.\n");
    }
    else
    {

        int result = factorial(n);

        printf("Factorial = %d\n", result);
    }
    printf("\nName:Oshin Pant  Roll No: 23  Lab:13");
    getch();
    return 0;
}