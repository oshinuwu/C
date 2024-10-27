#include <stdio.h>

int Implication(int p, int q)

{

    if (p == 1 && q == 0)

        return 0;

    else
    {

        return 1;
    }
}

int main()
{

    int p, q;

    printf("Implication Truth Table\n");

    printf("\np\tq\tp->q\n");

    for (p = 0; p <= 1; p++)
    {

        for (q = 0; q <= 1; q++)
        {

            printf("%d\t%d\t%d\n", p, q, Implication(p, q));
        }
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:4");
    getch();

    return 0;
}