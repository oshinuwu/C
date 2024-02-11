#include<stdio.h>
int main()
{
    printf("for implicit conversion\n");
    int x=5;
    char y='a';
    x=x+y; //converts y=a to ASCII
    float z=x+1.0;
    printf("x=%d,z=%f\n",x,z);
    printf("for explicit conversion\n");
    double a=1.2;
    int sum=(int) a +1;
    printf("the sum is %d\n",sum);
    printf("name:oshin pant\n roll no:19\n lab no:3");
    getchar();
    return 0;
}