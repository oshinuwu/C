#include <stdio.h>
int power(int a, int n)
{

    // Base case: a^0 = 1

    if (n == 0)
    {

        return 1;
    }

    // Recursive case: a^n = a * a^(n-1)

    else
    {

        return a * power(a, n - 1);
    }
}

int main()
{

    int a, n;

    printf("Enter base : ");

    scanf("%d", &a);

    printf("Enter exponent : ");

    scanf("%d", &n);

    int result = power(a, n);

    printf("\t\t = %d\n", result);

    printf("\nName:Oshin Pant  Roll No: 23  Lab:14");
    getch();

    return 0;
}