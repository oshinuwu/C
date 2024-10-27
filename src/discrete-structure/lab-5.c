#include <stdio.h>

int Biconditional(int p, int q)

{

    if (p == q)

        return 1;

    else
    {

        return 0;
    }
}

int main()
{

    int p, q;

    printf("Biconditional Truth Table\n");

    printf("\np\tq\tp<->q\n");

    for (p = 0; p <= 1; p++)
    {

        for (q = 0; q <= 1; q++)
        {

            printf("%d\t%d\t%d\n", p, q, Biconditional(p, q));
        }
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:5");
    getch();

    return 0;
} 