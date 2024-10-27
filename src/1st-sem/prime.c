#include<stdio.h>
int main()
{
    int num,i=2,rem;
    char prime='y';
    printf("enter a number");
    scanf("%d",&num);
    int a=num/2;
    while(i<=a)
    {
        rem=num%i;
        if(rem==0)
        {
            prime='n';
            break;
        }
        i++;
    }
    if(prime=='y')
    {
        printf("the number is prime ");
    }
    else
    {
        printf("the number is not prime");
    }
    getch();
    return 0;
}