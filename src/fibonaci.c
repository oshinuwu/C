#include<stdio.h>
int main()
{
    int i=0,n,a=0,b=1,c;
    printf("enter the value of n\n");
    scanf("%d",&n);
    printf("%d\t%d\t",a,b);
    while(i<n-2)
    {
        c=a+b;
        printf("%d\t",c);
        a=b;
        b=c;
        i++;
    }printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:1-b");
    getch();
    return 0;
}