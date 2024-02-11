#include<stdio.h>
int main()
{
    long int num,i=1,q,r,rev=0;
    printf("enter a number");
    scanf("%ld",&num);
    while(q!=0){
    q=num/2;
     r=num%2;
    num=q;
     rev=rev+r*i;
    i=i*10;
    }
    printf("%ld",rev);
    getch();
    return 0;

}