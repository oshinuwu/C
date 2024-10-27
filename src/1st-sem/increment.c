#include<stdio.h>
int main()
{
    int a,b;
    printf("enter any two integers\n");
    scanf("%d%d",&a,&b);
    int x=++a;
    int y=b++;
    printf("the pre-increment result is %d\n",x);
    printf("the post-increment result is %d\n",y);
    printf("the value of b is %d\n",b);
    printf("Name:oshin pant\n Roll no:19\n Lab no:5");
    getch();
    return 0;
}