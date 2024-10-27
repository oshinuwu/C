// chinese:

#include <stdio.h>

// Function to find the modular inverse of a with respect to m using the Extended Euclidean Algorithm

int inv(int a, int m)
{

    int m0 = m, t, q;

    int x0 = 0, x1 = 1;

    if (m == 1)

        return 0;

    while (a > 1)
    {

        q = a / m;

        t = m;

        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    if (x1 < 0)

        x1 += m0;

    return x1;
}
// Function to find the smallest x such that:

// x % num[i] = rem[i] for all i

int findMinX(int div[], int rem[], int k)
{

    int prod = 1;

    for (int i = 0; i < k; i++)

        prod *= div[i];

    int result = 0;

    for (int i = 0; i < k; i++)
    {

        int p = prod / div[i];

        result += rem[i] * inv(p, div[i]) * p;
    }
    return result % prod;
}

int main(void)
{
    int i;

    int div[] = {5, 6, 7};
    int len = sizeof(div) / sizeof(div[0]);
    int rem[len];

    printf("\nEnter remainders:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &rem[i]);
    }

    printf("The smallest number such that if we divide by %d,%d and %d,\nwe get %d,%d and %d as remainders repectively is  %d\n", div[0], div[1], div[2], rem[0], rem[1], rem[2], findMinX(div, rem, len));

    printf("\nName:Oshin Pant  Roll No: 23  Lab:17");
    fflush(stdin);
    getchar();

    return 0;
}