#include<stdio.h>
int main()
{
    int num,i,y,r,fact=1,s=0;
    printf("enter a number");
    scanf("%d",&num);
    y=num;
    while(num!=0)
    {
         r=num%10;
        for(i=1;i<=r;i++)
        {
            fact=fact*i;
            
        }
        printf("%d\t%d\t",fact,r);
         printf("\n");
        s=s+fact;
        fact=1;
        num=num/10;
    }
    printf("%d\t%d\t",s,y);
    printf("\n");
    if(s==y)
    {
        printf("it is a strong number");
    }
    else{
        printf("it is not a strong number");
    }
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-f");
    getch();
    return 0;
}