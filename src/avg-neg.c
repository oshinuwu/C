#include<stdio.h>
int main()
{
    int i=0,num,j=0;
    do{
        printf("enter a number");
        scanf("%d",&num);
        i=i+num;
        j++;
    }while(num>=0);
    printf("the sum is %d\n",i);
    int a=i/j;
    printf("the average is %d\n",a);
   
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:2-e");
      getch();
    return 0;
}