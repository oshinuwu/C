#include<stdio.h>
int main()
{
    int n,i=1;
    printf("enter the value of n");
    scanf("%d",&n);
    while(i<=n)
    {
        int r=2*i-1;
        int a=pow(r,3);
        printf("%d\t",a);
        i++;

    }
    getch();
    return 0;
}