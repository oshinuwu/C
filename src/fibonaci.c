#include<stdio.h>
int main()
{
    int i=0,n,a=0,b=1,c;
    printf("enter the value of n");
    scanf("%d",&n);
    printf("%d\t%d\t",a,b);
    while(i<n-2)
    {
        c=a+b;
        printf("%d\t",c);
        a=b;
        b=c;
        i++;
    }
    getch();
    return 0;
}