#include<stdio.h>
int main()
{
    int num,s,p,i=0;
    printf("enter a number");
    scanf("%d",&num);
    do{
        s=num%10;
        int r=s*(pow(2,i));
        p=p+r;
        num=num/10;
        i++;
    }while(num!=0);
    printf("%d",p);
    getch();
    return 0;
}