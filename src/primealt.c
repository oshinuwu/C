#include<stdio.h>

int main() {
    int num = 0, rem = 0,sum=0,s,i=0,y,p=0,d;
    char prime='y';
    printf("Enter a number:\n");
    scanf("%d",&num);
    y=num;
    d=num;
     switch (num) {
    case 0:
        printf("ZERO");
        break;
    case 1:
        printf("ONE-");
        prime = 'n';
        break;
    case 2:
        prime = 'y';
        break;
    default:
        if(num % 2 == 0) {
            prime = 'n';
            break;
        } 
        else {
            int i = 3;
            int a = num / 2;

            while(i <= a) {
                rem = num % i;
                if(rem == 0) {
                    prime ='n';
                    break;
                }
                i+=2;
            }
        }
        break;
    }
    printf("%d",num);
    if(prime=='y') {
        printf("\033[0;32mPrime\033[0m");
    }
    else {
        printf("\033[0;31mNOT Prime\033[0m");
    }

    while(num!=0)
    {
        num=num/10;
        i++;
    }
    while(y!=0)
    {
        s=y%10;
        int r=pow(s,i);
        p=p+r;
        y=y/10;
    }
    if(p==d)
    {
        printf("it is an armstrong number");
    }
    else{
        printf("it is not an armstrong number");
    }
    getch();
    return 0;
}