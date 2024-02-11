#include<stdio.h>
#include<conio.h>
int main()
{
    char x;
    printf("enter a character\n");
    scanf("%c",&x);
    if(x>=65 && x<=90)
    {
        printf("the given character is capital letter\n");
    }
   
    else if(x>=97 && x<=122)
    {
        printf("the given character is small letter\n");
    }
     else if(x>=48 && x<=57)
    {
        printf("the given character is a digit\n");
    }
     else if((x>=0 && x<=47)||(x>=58 && x<=64)||(x>=91 && x<=96)||(x>=123 && x<=127))
    {
        printf("the given character is special symbol\n");
    }
    else
    {
        printf("invalid\n");
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:3");
    getch();
    return 0;
}