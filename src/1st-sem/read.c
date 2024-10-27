#include<stdio.h>
#include<conio.h>
int main()
{
    char ch;
    int n;
    float f;
    long double l;
    printf("enter a character\n");
    scanf("%c",&ch);
    printf("enter an integer\n");
    scanf("%d",&n);
    printf("enter a float\n");
    scanf("%f",&f);
    printf("enter a long double\n");
    scanf("%Lf",&l);
    printf("character is %c\n integer is %d\n float is %f long double is %Lf\n",ch,n,f,l);
    printf("Name:Oshin Pant\n ROll no:19\n Lab no:7");
    getch();
    return 0;

}
