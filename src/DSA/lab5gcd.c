#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    int n1, n2;
    printf("Enter 2 numbers : ");
    scanf("%d%d", &n1, &n2);
    printf("GCD of %d and %d is %d", n1, n2, gcd(n1, n2));

    printf("\nName:Oshin Pant Roll No:23 Lab No:5");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}
