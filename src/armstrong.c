#include<stdio.h>
#include<math.h>
int main()
{
    
    int num,sum=0,s,i=0,y,p=0,d;
    printf("enter a number");
    scanf("%d",&num);
    y=num;
    d=num;
    while(num!=0)
    {
        num=num/10;
        i++;
    }
    while(y!=0)
    {
        s=y%10;
        int r=pow(s,i);
        p=p+r;
        y=y/10;
    }
    printf("%d\t%d\t",p,d);
    if(p==d)
    {
        printf("it is an armstrong number");
    }
    else{
        printf("it is not an armstrong number");
    }
    getch();
    return 0;
}