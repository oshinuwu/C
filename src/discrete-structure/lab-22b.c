// prove that (AVB)^((~A)^(~B)) is contradiction.

#include <stdio.h>

int AND(int a, int b)

{

    if (a == 1 && b == 1)

        return 1;

    else

        return 0;
}

int OR(int a, int b)

{

    if (a == 1 || b == 1)

        return 1;

    else

        return 0;
}

int Not(int a)

{

    if (a == 1)

        return 0;

    else

        return 1;
}

int main()

{

    int a, b;

    printf("A\tB\t(AVB)^((~A)^(~B))\n");

    for (a = 0; a <= 1; a++)

    {

        for (b = 0; b <= 1; b++)

        {

            printf("%d\t%d\t%d\n", a, b, AND(OR(a, b), AND(Not(a), Not(b))));
        }
    }

    printf("\nName : Oshin Pant  Roll no. : 23  Lab 22.b\n\n\n");
    getch();
    return 0;
}