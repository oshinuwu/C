#include<stdio.h>
int fibonacci(int n){
   int result;
   if(n==0){
      result=0;
   }
   else if(n==1){
      result = 1;
   }
   else{
      result = fibonacci(n-1)+ fibonacci(n-2);
   }
}

int main(){
   int i,n;
   printf("Enter a number : ");
   scanf("%d",&n);
   for(i=0;i<=n;i++){
      printf("%d ",fibonacci(i));
   }
   
   getch();
   return 0;
}
