#include<stdio.h>
int main()
{
    int a1,a2,a3;
    printf("enter age of Barsha Bina and Ajay\n");
    scanf("%d%d%d",&a1,&a2,&a3);
    if(a1<a2)
    {
        if(a1<a3)
        {
        printf("Barsha is the youngest\n");
        }
        else if(a3<a1)
        {
            printf("Ajay is the youngest\n");
        }
        
    }
    else if(a2<a1)
    {
        if(a2<a3)
        {
        printf("Bina is the youngest\n");
        }
         else if(a3<a2)
        {
        printf("Ajay is the youngest\n");
        }
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:2");
    getch();
    return 0;
}