#include <stdio.h>

int gcd(int a, int b)
{

    // Base case: if b is 0, the GCD is a

    if (b == 0)
    {

        return a;
    }
    else
    {

        // Recursive case: gcd(b, a % b)

        return gcd(b, a % b);
    }
}

int main()
{

    int a, b;

    printf("Enter two numbers:\n");

    scanf("%d %d", &a, &b);

    int GCD = gcd(a, b);

    printf("\t\tGCD = %d", GCD);

    printf("\nName:Oshin Pant  Roll No: 23  Lab:15");
    getch();

    return 0;
}