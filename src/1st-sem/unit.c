#include<stdio.h>
int main()
{
    int u;
    float p;
    printf("enter the unit");
    scanf("%d",&u);
    if(u>=0 && u<=50)
    {
        p=u*3.5;
    }
    else if(u>50 && u<=150)
    {
         p=50*3.5+((u-50)*4);
    }
    else if(u>150 && u<=250)
    {
        p=50*3.5+100*4+((u-150)*5.2);
    }
    else if(u>250)
    {
        p=50*3.5+100*4+100*5.2+((u-250)*6.5);
    }
    printf("the bill is %f\n",p);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:5");
    getch();
    return 0;
}