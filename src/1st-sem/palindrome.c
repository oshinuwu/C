#include<stdio.h>
int main()
{
    int n,rev,r=0,s;
    printf("enter a number");
    scanf("%d",&n);
    int y=n;
    do{
        s=n%10;
        r=r*10+s;
        n=n/10;
    }while(n!=0);
    
    if(y==r){
        printf("it is a palindrome\n");
    }
    else{
        printf("it is not a palindrome\n");
    }
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:2-c");
    getch();
    return 0;
}