#include<stdio.h>
int main()
{
    int i,j,k;
    for(i=50;i<=100;i++){
        for(j=50;j<=100;j++){
            for(k=50;k<=100;k++){
                int a=i*i+j*j;
                int b=k*k;
                if(a==b){
                    printf("%d,%d,%d\n",i,j,k);
                }
            }
        }
    }
    getch();
    return 0;
}