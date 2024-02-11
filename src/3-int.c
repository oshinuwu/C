#include<stdio.h>
int main()
{
    int s=0,i=2;
    do{
        s=s+i;
        printf("%d\t",i);
        i=i+3;
    }while(i<100);
    printf("the sum is %d",s);
    getch();
    return 0;
}