#include<stdio.h>
int main()
{
    int age;
    printf("enter your age\n");
    scanf("%d",&age);
    int i=age<=12 && age>=20;
    (i=1)?printf("you are not a teenager\n"):printf("you are a teenager\n");
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:7");
    getch();
    return 0;
}