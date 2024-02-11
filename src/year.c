#include<stdio.h>
#include<conio.h>
int main()
{
    int y;
    printf("enter a year");
    scanf("%d",&y);
    int a=y%100;
    if(a==0)
    {
        int b=y%400;
        if(b==0)
        {
            printf("it is a leap year\n");
        }
        else
        {
            printf("it is not a leap year\n");   
        }
    }
    else
    {
        int b=y%4;
        if(b==0)
        {
            printf("it is a leap year\n");
        }
        else
        {
            printf("it is not a leap year\n");
        }
    }
    printf("Name:OShin Pant\n Roll no:19\n Lab no:4");
    getch();
    return 0;
}