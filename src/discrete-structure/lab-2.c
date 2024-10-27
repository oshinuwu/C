#include <stdio.h>

int OR(int p, int q)

{

    if (p == 0 && q == 0)

        return 0;

    else
    {

        return 1;
    }
}

int main()
{

    int p, q;

    printf("**  OR Truth Table  ** ");

    printf("\np\tq\tpvq\n");

    for (p = 0; p <= 1; p++)
    {

        for (q = 0; q <= 1; q++)
        {

            printf("%d\t%d\t%d\n", p, q, OR(p, q));
        }
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:2");
    getch();

    return 0;
}