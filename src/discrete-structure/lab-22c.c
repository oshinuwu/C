// prove that A <->B (double implication).

#include <stdio.h>

int Dimplication(int a, int b)

{

    if (a == b)

        return 1;

    else

        return 0;
}

int main()

{

    int a, b;

    printf("A\tB\tA <->B \n\n");

    for (a = 0; a <= 1; a++)

    {

        for (b = 0; b <= 1; b++)

        {

            printf("%d\t%d\t%d\n", a, b, Dimplication(a, b));
        }
    }

    printf("\nName : Oshin Pant  Roll no. : 23  Lab 22.c\n\n\n");
    getch();
    return 0;
}