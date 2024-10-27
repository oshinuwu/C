#include<stdio.h>
int main()
{
    int i,j,k,count;
    for(i=50;i<=100;i++){
        for(j=50;j<=100;j++){
            for(k=50;k<=100;k++){
                int a=i*i+j*j;
                int b=k*k;
                if(a==b && j<i){
                    printf("%d,%d,%d\n",i,j,k);
                    count=count+1;
                }
            }
        }
    }printf("no of terms is %d",count);
     printf("\n");
     printf("Name:Oshin Pant\n Roll no:19\n Lab no:6-d");
    getch();
    return 0;
}