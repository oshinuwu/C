#include<stdio.h>
#include<conio.h>

int main(){
	int r1,r2,c1,c2;
	printf("Enter the rows and column of first matrix");
	scanf("%d%d",&r1,&c1);
	printf("Enter the rows and column of second matrix");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2){
		printf("cannot multiplied"); 
		}
		else{
			printf("Enter the elements of 1st matrix:\n");
			int m[r1][c1],i,j;
			for(i=0;i<r1;i++){
				for(j=0;j<c1;j++){
					scanf("%d",&m[i][j]);
				}
			}
		printf("The 1st matrix entered:\n ");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%2d",m[i][j]);
			}
			printf("\n");
		}
		printf("Enter the elements of 2nd matrix:\n");
		int n[r2][c2];
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				scanf("%d",&n[i][j]);
			}
		}
		
		printf("The 2nd matrix is:");
		
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				printf("%2d",n[i][j]);
			}
			printf("\n");
		}
		int p [r1][c2];
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				p[i][j]=0;
				for(int k=0;k<c1;k++){
			
				p[i][j]+=m[i][j]*n[i][j];}
			}
		}
		printf("The product of matrix 1 :\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c1;j++){
				printf("%2d", m[i][j]);
			}
			printf("\n");
		}
		printf("The product of matrix 2 :\n");
		for(i=0;i<r2;i++){
			for(j=0;j<c2;j++){
				printf("%2d",n[i][j]);
			}
			printf("\n");
		}
		printf("The product of 1st and 2nd matrix is:\n");
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				printf("%3d",p[i][j]);
			}
			printf("\n");
		}}
		printf("\nName=Oshin Pant\n Rollno=19\n Lab no=7");
        getch();
		return 0;
}