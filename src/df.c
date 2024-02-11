#include<stdio.h>
int main()
{
    int n1,n2;
    float f1,f2;
    printf("enter any two integers\n");
    scanf("%d%d",&n1,&n2);
    int s1=n1+n2;
    int p1=n1*n2;
    printf("the sum is %d and product is %d for the integers\n",s1,p1);
    printf("enter any two floats\n");
    scanf("%f%f",&f1,&f2);
    float s2=f1+f2;
    float p2=f1*f2;
    printf("the sum is %f and product is %f for the floats\n",s2,p2);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:6");
    getch();
    return 0;
}