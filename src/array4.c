#include<stdio.h>
#include<conio.h>

int main (){
    int m,n;
	 printf("enter no of rows n columns");
    scanf("%d%d",&m,&n);
    int a[m][n],sum[m][n],difference[m][n],i,j;
	int b[m][n];
	printf("Enter the elements of the matrix:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("the matrix you entered is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		} printf("\n");
	}
		printf("Enter the element of second matrix:\t");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				scanf("%d",&b[i][j]);
			}
		}
		printf("the matrix you entered is:\n");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				printf("%d\t",b[i][j]);
			} printf("\n");
		}
		for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sum[i][j]=a[i][j]+b[i][j];
			
		}
	}
	printf("the sum  of a and b is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%3d",sum[i][j]);
		}printf("\n");
		}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			difference[i][j]=a[i][j]-b[i][j];
		}
	}
	printf("\nthe difference is:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%3d",difference[i][j]);
		}
		printf("\n");
	}
	printf("\nName=Oshin Pant\n Rollno=19\n Lab no=4");
    getch();
	return 0;
}