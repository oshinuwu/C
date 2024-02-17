#include<stdio.h>
int main()
{
    int i;
    char j;
    for(i=4;i>=0;i--)
    {
        for(j='E';j>='E'-i;j--)
        {
            printf("%c",j);
        }
        printf("\n");
    }
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-g(iv)");
    getch();
    return 0;
}