/*WAP to implement fuzzy set operation*/

#include <stdio.h>

#include <stdlib.h>

float min(float a, float b)

{

    if (a < b)

        return a;

    else

        return b;
}

float max(float a, float b)

{

    if (a > b)

        return a;

    else

        return b;
}

int main()
{

    float fa, fb, fi, fu, fac;

    float x = 1.0;

    printf("Enter the value of first set(value ranges from [0,1]): ");

    scanf("%f", &fa);

    printf("Enter the value of second set(value ranges from [0,1]): ");

    scanf("%f", &fb);

    fi = min(fa, fb);

    fu = max(fa, fb);

    fac = x - fa;

    printf("intersection= %0.1f\n", fi);

    printf("union= %0.1f\n", fu);

    printf("complement of first set=%0.1f\n", fac);

    printf("\nName:Oshin Pant Roll No:23 Lab No:9");
    getch();

    return 0;
}
