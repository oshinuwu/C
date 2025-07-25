#include<stdio.h>
void transfer(int n, char from, char to, char aux){
   if(n==1){
      printf("\nMove disk %d from peg %c to peg %c",n,from,to);
   }
   else{
      transfer(n-1,from,aux,to);
      printf("\nMove disk %d from peg %c to peg %c",n,from,to);
      transfer(n-1, aux, to, from);
   }
}
int main(){
   int n;
   printf("Enter no. of disks : ");
   scanf("%d",&n);
   transfer(n, 'A','B','C');
   
   printf("\nName:Oshin Pant Roll No:23 Lab No:9");
   fflush(stdin);
  getchar();
   getchar();
   return 0;
}
