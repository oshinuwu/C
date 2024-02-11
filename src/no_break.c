#include<stdio.h>
int main()
{
    char num;
    printf("enter either 1,2 or 3\n");
    scanf("%c",&num);
    switch(num)
    {
         case'1':
        printf("ONE!\n");
        case'2':
        printf("TWO!\n");
        case'3':
        printf("THREE!\n");
        default:
        printf("invalid");
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:7");
    getch();
    return 0;
}