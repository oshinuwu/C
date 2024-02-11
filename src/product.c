#include<stdio.h>
int main()
{
    int num,s,i,r=1;
    printf("enter the number ");
    scanf("%d",&num);
    do
    {
        s=num%10;
        r=r*s;
        num=num/10;
    } while (num!=0);
    printf("the product is %d",r);
    getch();
    return 0;
}