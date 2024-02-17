#include<stdio.h>
int main()
{
    int s=0,i=2;
    do{
        s=s+i;
        printf("%d\t",i);
        i=i+3;
    }while(i<100);
    printf("the sum is %d\n",s);
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:2-a");
    getch();
    return 0;
}