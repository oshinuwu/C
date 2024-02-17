#include<stdio.h>
int main()
{
    int i,j,k,count;
    for(i=50;i<=100;i++){
        for(j=50;j<=100;j++){
            for(k=50;k<=100;k++){
                int a=i*i+j*j;
                int b=k*k;
                if(a==b && i){
                    printf("%d,%d,%d\n",i,j,k);
                    count=count+1;
                }
            }
        }
    }printf("no of terms is %d",count);
    getch();
    return 0;
}