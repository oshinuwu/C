#include <stdio.h>
int fact(int n)
{
    int result;
    if (n == 0)
    {
        result = 1;
    }
    else
    {
        result = n * fact(n - 1);
    }
    return result;
}
int main()
{
    int x;
    printf("\nEnter a number: ");
    scanf("%d", &x);
    printf("\nThe factorial is %d", fact(x));

    getch();
    return 0;
}