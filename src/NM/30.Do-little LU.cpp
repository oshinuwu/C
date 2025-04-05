/*Write a C program for matrix factorization by using Do-little LU decomposition
Algorithm for LU matrix factorization using Doolittle LU Decomposition
Start
Read dimension of matrix say n
Read elements of matrix row-wise
Assign values to first row of U matrix as below
For j=1 to n
U[1][j]=a[1][j]
End for
Assign values to first row of L matrix as below
For i=1 to n
L[i][i]=1
End for
Compute and assign values to first column of L matrix as below
for j=2 to n
l[i][1] = a[i][1]/[u[1][1]
End for
Compute and assign values to 2nd to nth rows of L and U as below 
For j=2 to n
For i=2 to j
U[i][j] = a[i][j]-k=1i-1(lik*ukj)
End for
For i=j+1 to n
L[i][j] = 1uj[j]{a[i]j]- k=1i-1(lik*ukj)}
End for
End for
Display L and U Matrices
Stop

C program for matrix factorization using Do Little LU Decomposition*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
   int n, i,j,k;
   float sum, a[10][10],b[10],x[10],z[10],u[10][10],l[10][10];
   
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
   
   printf("Enter RHS vector\n");
   for(i=0;i<n;i++)
   {
   	  scanf("%f",&b[i]);
   }
   
   printf("Computing elements of L and U matrix...\n");
   for(j=0;j<n;j++)
   {
   	u[0][j]=a[0][j];
   }
   
   for(i=0;i<n;i++)
   l[i][i]=1;
   
   for(i=1;i<n;i++)
   l[i][0]=a[i][0]/u[0][0];
   
   for(j=1;j<n;j++)
   {
   	  for(i=1;i<=j;i++)
   	  {
   	  	for(k=0;k<=i-1;k++)
   	  	{
   	  	  sum = sum+(l[i][k]*u[k][j]);	
		}
		u[i][j]= a[i][j]-sum;
		sum=0;
	  }
	  for(i=j+1;i<n;i++)
	  {
	  	for(k=0;k<=j-1;k++)
	  	{
	  		sum = sum+(l[i][k]*u[k][j]);
		}
		l[i][j] = (a[i][j]-sum)/u[j][j];
		sum = 0; 
	  }
   }
   
   printf("Solving for Z using Forward Substitution..\n");
   getch();
   z[0]=b[0];
   for(i=1;i<n;i++)
   {
   	 for(j=0;j<i;j++)
   	 sum = sum+(l[i][j]*z[j]);
   	 z[i] = b[i]-sum;
   	 sum = 0;
   }
   
   printf("Solving for X using Backward Substitution...\n");
   getch();
   x[n-1]=z[n-1]/u[n-1][n-1];
   for(i=n-2;i>=0;i--)
   {
   	 for(j=i+1;j<n;j++)
   	 sum = sum+(u[i][j]*x[j]);
   	 x[i] = (z[i]-sum)/u[i][i];
   	 sum = 0;
   }
   
   printf("Solution:\n");
   for(i=0;i<n;i++)
   {
   	   printf("x%d = %f\t",i+1,x[i]);
   }
   
   printf("\nName:Oshin Pant\nRollno:23\nLab no: 30");
   fflush(stdin);
   getchar();
   getchar();
   return 0;
}

