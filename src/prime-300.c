#include<stdio.h>
int main()
{
    int i=2,rem,j;
   
    for(j=2;j<300;j++){
        char prime='y';
        i = 2;
        
        while(i <= j/2) {
            rem=j%i;
            if(rem==0) {
                prime='n';
                break;
            }
            i++;
        }
        if(prime=='y') {
            printf("%d\t",j);
        }
    } 
    getch();  
    return 0;
}