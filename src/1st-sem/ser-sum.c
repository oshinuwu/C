#include<stdio.h>
int main()
{
    int i,j,fact=1;
    float sum=0;
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=i;j++)
        {
            fact=fact*j;
        }
        sum=sum+(i/fact);
        printf("%d/%d+",i,fact);
        fact=1;
    } printf("\n");
    printf("the sum is %f",sum);
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-b");
    getch();
    return 0;
}