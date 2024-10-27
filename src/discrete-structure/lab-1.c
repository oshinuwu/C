#include <stdio.h>

int AND(int p, int q)

{

    if (p == 1 && q == 1)

        return 1;

    else
    {

        return 0;
    }
}

int main()
{

    int p, q;

    printf("**  AND Truth Table  ** ");

    printf("\np \tq \tp^q \n");

    for (p = 0; p <= 1; p++)
    {

        for (q = 0; q <= 1; q++)
        {

            printf("%d\t %d\t %d\n", p, q, AND(p, q));
        }
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:1");
    getch();
    return 0;
}