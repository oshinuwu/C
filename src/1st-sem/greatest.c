#include<stdio.h>
int main()
{
   int a,b,c;
   printf("enter any three numbers\n");
   scanf("%d%d%d",&a,&b,&c);
   (a>b)?(a>c)?printf("a is greatest\n"):printf("c is greatest\n"):(b>c)?printf("b is greatest\n"):printf("c is greatest\n");
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:10");
    getch();
    return 0;
}