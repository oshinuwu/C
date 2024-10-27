#include<stdio.h>
int main()
{
    int s,c;
    printf("enter selling price and cost price");
    scanf("%d%d",&s,&c);
    if(s>c)
    {
        int p=s-c;
        printf("the profit is %d\n",p);
    }
    else if(c>s)
    {
        int l=c-s;
        printf("the loss is %d\n",l);
    }
    else
    {
        printf("there is neither profit nor loss\n");
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:1");
    getch();
    return 0;
}