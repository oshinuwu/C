#include<stdio.h>
int main (){
	int m[3][3],c,d,e,i,j;
	int row_sum[3]={0};
	int colum_sum[3]={0};
	printf("Enter the elements of the matrix");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&m[i][j]);
		} 
	}
 	for(i=0;i<3;i++){
 	for(j=0;j<3;j++){
 		if(i<j){
 			c+=m[i][j];
		 }
	 }
 }
 printf("The sum of upper triangular matrix is %d", c);
 
 for(i=0;i<3;i++){
 	for(j=0;j<3;j++){
 		if(i>j){
 			d =d  +m[i][j];} 
		 }
	 }
 printf("\nThe sum of lower triangular matrix is %d", d);
  
  for(i=0;i<3;i++){
  	for(j=0;j<3;j++){
  		if(i==j){
  			e=e+m[i][j]*m[i][j];
		  }
  		
	  }
  }
  printf("\n The sum of square of elements of diagonal matrix is %d",e);
   
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   		row_sum[i]+=m[i][j];
	   }
   }
   printf("\n Sum of Row 1 is %d,Row 2 is %d, Row 3 is %d ",row_sum[0],row_sum[1],row_sum[2]);
   
   for(i=0;i<3;i++){
   	for(j=0;j<3;j++){
   		colum_sum[j]+=m[i][j];
	   }
   }
   printf("\n sum of column 1 is %d, Column 2 is %d, Column 3 is %d", colum_sum[0],colum_sum[1],colum_sum[2]);
   printf("\nName=Oshin Pant\n Rollno=19\n Lab no=5");
   getch();
 return 0;
}