#include <stdio.h>

int gcdExtended(int a, int b, int *s, int *t)

{

    if (a == 0)

    {
        *s = 0;
        *t = 1;
        return b;
    }

    int s1, t1;
    int gcd = gcdExtended(b % a, a, &s1, &t1);

    *s = t1 - (b / a) * s1;
    *t = s1;

    return gcd;
}

int main()
{

    int s, t, x, y;

    printf("Enter two numbers:\n");
    scanf("%d %d", &x, &y);

    int g = gcdExtended(x, y, &s, &t);

    printf("\t\tgcd(%d, %d) =% d , s =%d, t =%d", x, y, g, s, t);

    printf("\nName:Oshin Pant  Roll No: 23  Lab:16");
    getch();
    return 0;
}