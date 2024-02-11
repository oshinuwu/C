#include<stdio.h>
int main()
{
    float a,b;
    printf("enter any two floats\n");
    scanf("%f%f",&a,&b);
    float x1=--a;
    float y1=b--;
    printf("the pre-decrement result is %f\n",x1);
    printf("the post-decrement result is %f\n",y1);
    printf("the value of b is %f\n",b);
    printf("Name:oshin pant\n Roll no:19\n Lab no:6");
    getch();
    return 0;
}