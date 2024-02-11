#include<stdio.h>
int main()
{
    int a=20,b=45,c=30;
    printf("example of relational operator\n");
    printf("is a=b?\n");
    int res= a==b;
    printf("%d\n",res);
    printf("is b>c?\n");
    int r=b>c;
    printf("%d\n",r);
    printf("example of logical operator\n");
    int res1=(a==b)&&(b<c);
    int res2=(b!=a)||(c<=b);
    printf("logical and result is %d and logical or result is %d\n",res1,res2);
    printf("example of bitwise logical operator\n");
    printf("bitwise or between a and b is %d\n",a|b);
    printf("bitwise and between a and b is %d\n",a&b);
    printf("example of shift operator \n");
    printf("%d shifted 1 bit position to left is %d\n",a,a<<1);
    printf("example of complement\n");
    printf("one's complement of c is %d\n",~c);
    printf("example of size of operator is\n");
    printf("the size of a is %d\n",sizeof(a));
    printf("example of comma operator is\n");
    int x=(a,a+2);
    printf("result is %d\n",x);
    printf("name:oshin pant\n roll no:19\n lab no:4\n");
    getch();
    return 0;
}