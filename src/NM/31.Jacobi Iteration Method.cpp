/*Write a C program to solve system of equations using Jacobi iteration method
Algorithm for Jacobi Iteration Method
Start
Read dimension of system of equations say n
Read coefficients of matrix row-wise
Read elements of RHS vector
Read accuracy limit say E
Read initial guess
For i=1 to n
Old_x[i] = 0
End for
Compute new set of approximate root as below
For i=1 to n
Sum = b[i]
For j=1 to n
If(i!=j)
Sum = sum-a[i][j] *old_x[j]
End for
New_x[i] = sum/a[i][i]
E[i] =  abs(new_x[i]-old_x[i])/new_x[i]
End for
Compute error with specified precision
For i=1 to n
If(E[i]>E
For j=1 to n
Old_x[j] = new_x[j];
End for
Got to step 7
End for
Display results in new_x vector
Stop

C program for Jacobi method*/
#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function */
#define f1(x, y, z) ((9 - 2*y - z) / 10) 
#define f2(x, y, z) ((7 - 2*x - 3*z) / 10) 
#define f3(x, y, z) ((8 - 3*x - 4*y) / 10)
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1; 
 printf("Enter tolerable error:\n");
 scanf("%f", &e);
 printf("\nCount\tx\ty\tz\n");
 do
 {  
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);  
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);
  count++;  
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);
 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);
 printf("\nName:Oshin Pant\nRollno:23\nLab no: 31");
 fflush(stdin);
 getchar();
 getchar();
 return 0;
}

