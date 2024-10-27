#include<stdio.h>
#define GUESS 8
int main()
{
    int n;
    printf("guess a number between 1-10\n");
    scanf("%d",&n);
    (n==GUESS)?printf("your guess is correct\n"):printf("your guess is incorrect\n");
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:8");
    getch();
    return 0;
}