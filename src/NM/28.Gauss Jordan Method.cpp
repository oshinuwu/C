/*Write a C program for matrix inversion using Gauss Jordan method
Algorithm:
Start
Read dimension of Matrix say n
Read coefficient matrix row-wise
Augment the coefficient matrix by identity matrix
Perform elimination operation as below
For k=1 to n
Pivot = a[k][k]
For p =1 to 2n
a[k][p] = a[k][p]/pivot
end for
for i=1 to n
term = a[i][k]
if(i!=k)
multiply row k by “term” and subtract it from row i
End for
End for
Display inverse matrix which is second half of augmented matrix
Stop

C program for matrix Inversion by using Gauss Jordan Method*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,i,k,j,p,q;
	float pivot, term, a[10][10];
	printf("Enter dimension of System of equations\n");
	scanf("%d",&n);
	printf("Enter coefficient matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=n;j<2*n;j++)
		{
			if(i==j-n)
			a[i][j]=1;
			else
			a[i][j]=0;
		}
	}
	for(k=0;k<n;k++)
	{
		pivot = a[k][k];
		for(p=0;p<2*n;p++)
		a[k][p]=a[k][p]/pivot;
		for(i=0;i<n;i++)
		{
			term = a[i][k];
			if(k!=i)
			for(j=0;j<2*n;j++)
			{
				a[i][j]=a[i][j]-a[k][j]*term;
			}
		}
	}
	printf("Matrix Inverse\n");
	for(i=0;i<n;i++)
	{
		for(j=n;j<2*n;j++)
		{
			printf("%f ",a[i][j]);
		}
		printf("\n");
	}
	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 28");
	return 0;
	
}


/*Output:
Enter dimension of System of equations
3
Enter coefficient matrix
2 1 1
3 2 3
1 4 9
Matrix Inverse
-3.000000 2.500000 -0.500000
12.000000 -8.500000 1.500000
-5.000000 3.500000 -0.500000*/

