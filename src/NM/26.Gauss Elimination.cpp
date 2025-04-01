//Write a C program for solving system of equations using basic Gauss elimination method
/*Algorithm for Gauss Elimination with Partial Pivoting
Start
Read Dimension of System of equations say n
Read coefficient matrix row-wise
Read RHS vector
Perform forward elimination as below
For k=1 to n-1
	Find largest of a[p][k] for p=k, k+1, ….n
	Swap row k and row p in coefficient matrix
	Swap row k and p in RHS vector
	Pivot  = a[k][k]
For i=k+1 to n
Term  = (a[i][k]/pivot)
Multiply row k of B matrix by “term” and subtract it from row i
Multiply row k of B matrix by “term” and subtract it from row i
End for
End for
Perform back substitution as below
X[n] = b[n]/a[n][n]
For i=n-1 to 1
Sum = 0
For  j=i+1 to n
Sum sum+ a[i][j]*x[j]
End for
X[i] = (b[i]-sum)/a[i][i]
End for
Display the solution vector
Stop*/


//C program for Naïve Gauss Elimination Method

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int n,i,k,j,p,q;
	float pivot, term, sum=0, a[10][10],b[10],x[10];
	printf("Enter the dimension of the system of equations\n");
    scanf("%d",&n);
	printf("Enter the elements of coefficient matrix row wise\n");
	for(i=0;i<n;i++)
	{
	   for(j=0;j<n;j++)
	   {
	   	scanf("%f",&a[i][j]);
		}	
	}	
	printf("Enter RHS vector\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&b[i]);
	}
	for(k=0;k<=n-2;k++)
	{
		 pivot = a[k][k];
		 if(fabs(pivot)<0.0001)
		 printf("Method failed");
		 else 
		 for(i=k+1;i<n;i++)
		 {
		 	 term = a[i][k]/pivot;
		 	 for(j=0;j<n;j++)
		 	 {
		 	   a[i][j] = a[i][j]-a[k][j]*term;	
			}
			b[i] = b[i]-b[k]*term;
		 }
	}
	x[n-1]=b[n-1]/a[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		sum = 0;
		for(j=i+1;j<=n-1;j++)
		{
			sum = sum+a[i][j]*x[j];
		}
		x[i] = (b[i]-sum)/a[i][i];
	}
	printf("Solution\n");
	for(i=0;i<n;i++)
	{
		printf("x%d = %f\t",i+1,x[i]);
	}
	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 26");
	return 0;
}
/*Output:
Enter the dimension of the system of equations
3
Enter the elements of coefficient matrix row wise
2 1 1
3 2 3
1 4 9
Enter RHS vector
10 18 16
Solution
x1 = 7.000000   x2 = -9.000000  x3 = 5.000000*/

