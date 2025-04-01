/*Write a C program for solving system of equations using basic Gauss Jordan method
Algorithm for Gauss Jordan Elimination
Start
Normalize the first equation by dividing it by its pivot element
Eliminate x1 term from all the other equations
Now, normalize the second equation by dividing it by its pivot element
Eliminate x2 from all the equations, above and below the normalized pivotal equation
Repeat this process until xn is eliminated from all but the last equation
The resultant b vector is the solution vector
Stop

C program for Gauss Jordan Method*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int n,i,k,j,p,q;
    float pivot, term, a[10][10];
    printf("Enter dimension of system of equations\n");
    scanf("%d",&n);
    printf("Enter coefficient augmented matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(k=0;k<n;k++)
    {
        pivot = a[k][k];
        for(p=0;p<n+1;p++)
         a[k][p]=a[k][p]/pivot;
         for(i=0;i<n;i++)
         {
             term = a[i][k];
             if(k!=i)
             {
                 for(j=0;j<n+1;j++)
                 {
                     a[i][j] = a[i][j]-a[k][j]*term;
                 }

             }
         }
    }
    printf("Solution Vector\n");
    for(i=0;i<n;i++)
    {

        printf("x%d = %f\n",i+1,a[i][3]);
    }
  	printf("\nName:Jenisha Pandit\nRollno:61\nLab no 29");
    return 0;
}
/*Output:
Enter dimension of system of equations
3
Enter coefficient augmented matrix
2 4 -6 -8
1 3 1 10
2 -4 -2 -12
Solution Vector
x1 = 1.000000
x2 = 2.000000
x3 = 3.000000*/

