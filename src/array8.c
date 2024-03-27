#include<stdio.h>
#include<conio.h>
#define m 3
#define n 3
int main(){
  int a[m][n],b[m][n],i,j,flag=0;
  printf("Enter the elements of 1st matrix");
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		scanf("%d",&a[i][j]);
	  }
  }
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		printf("%d\t",a[i][j]);
	  }
	  printf("\n");
  }
  
  printf("Enter the elements of second matrix");
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		scanf("%d",&b[i][j]);
	  }
	  
  }
   for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		printf("%d\t",b[i][j]);
  	}
  	printf("\n");
  }
  
  for(i=0;i<m;i++){
  	for(j=0;j<n;j++){
  		if( a[i][j]!=b[i][j]){
  			flag=1;
		  }}}
		  if(flag==0)
		  printf(" equal matrix");
		  else{
		  	printf("not equal matrix");
		  }
		  printf("\nName=Oshin Pant\n Rollno=19\n Lab no=8");
          getch();
		  return 0;
  	
}