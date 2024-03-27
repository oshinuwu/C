#include<stdio.h>
# include<conio.h>
# define M 3
# define N 3
int main (){
	int matrix[M][N],trans[N][M],i,j;
	printf("Enter the elements of the matrix");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&matrix[i][j]);
		}
	}  
	printf("The matrix is:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d\t",matrix[i][j]);
			}
			printf("\n");
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			trans[j][i]=matrix[i][j];
		}
	}
	printf("The transpose of matrix is :\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d\t",trans[i][j]);
		}
	
	printf("\n");}
	printf("Name=Oshin Pant\n Rollno=19\n Lab no=6");
    getch();
	return 0;
}