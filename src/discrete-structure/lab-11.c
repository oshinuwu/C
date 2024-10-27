#include <stdio.h>

#include <math.h>

int main()
{

    float val;

    float fval, cval;

    printf("enter a float value : \n");

    scanf("%f", &val);

    fval = floor(val);

    cval = ceil(val);

    printf("floor value =%f \n ceiling value =%f ", fval, cval);

    printf("\nName:Oshin Pant Roll No:23 Lab No:11");	 
    getch();

    return 0;
}