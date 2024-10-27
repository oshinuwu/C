// prove:(p->q)^(q->r)->(p->r) is tautology.

#include <stdio.h>

int AND(int a, int b)

{

    if (a == 1 && b == 1)

        return 1;

    else

        return 0;
}

int Implication(int a, int b)

{

    if (a == 1 && b == 0)

        return 0;

    else

        return 1;
}

int main()

{

    int a, b, c;

    printf("P\t q\tr\t(p->q)^(q->r)->(p->r) \n\n");

    for (a = 0; a <= 1; a++)

    {

        for (b = 0; b <= 1; b++)

        {

            for (c = 0; c <= 1; c++)
            {

                printf("%d\t%d\t%d\t%d\n", a, b, c, Implication(AND(Implication(a, b), Implication(b, c)), Implication(a, c)));
            }
        }
    }

    printf("\nName : Oshin Pant  Roll no. : 23  Lab 22.a\n\n\n");
    getch();
    return 0;
}