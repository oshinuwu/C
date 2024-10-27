#include <stdio.h>

int NOT(int p)

{

    if (p == 0)

        return 1;

    else
    {

        return 0;
    }
}

int main()
{

    int p;

    printf("* NOT Truth Table*");

    printf("\np\t~p\n");

    for (p = 0; p <= 1; p++)
    {

        printf("%d\t%d\n", p, NOT(p));
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:3");
    getch();

    return 0;
}