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
    printf("the product is %d\n",r);
    printf("Name:Oshin Pant\n Roll no:19 Lab no:2-b");
    getch();
    return 0;
}