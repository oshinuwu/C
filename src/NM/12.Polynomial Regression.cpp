/*
1.	Start
2.	Read number of points say n
3.	Read the order of polynomial say m
4.	Read given data points say x[i] and fx[i]
5.	Calculate required summations as below
for i=1 to 2m
    for j=0 to n-1
        sx[i] = sx[i]+pow(x[i],i);
    End for
for i=0 to m
    for j=0 to n-1
        sxy [i] =  y[j]*pow(x[i],i);
        End for
End for
6.	Construct RHS matrix of order (m+1)×(m+1)
7.	Construct LHS matrix of order (m+1)×1
8.	Solve for coefficients a0,a1,a2,..am using gauss elimination method
9.	Display the equation y =  a0+a1x+a2x2+….+amxm
10.	Stop
11.	*/
// Write a C program to implement polynomial regression
#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, k, m, n;
    float a[20][20], b[20], z[20], x[20], fx[20];
    float sum, pivot, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter degree of polynomial: ");
    scanf("%d", &m);

    printf("Enter data points (x, y):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &fx[i]);
    }

    // Constructing normal equation coefficients
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= m; j++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += pow(x[k], i + j);
            }
            a[i][j] = sum;
        }

        sum = 0;
        for (k = 0; k < n; k++)
        {
            sum += fx[k] * pow(x[k], i);
        }
        b[i] = sum;
    }

    // Gaussian elimination
    for (k = 0; k <= m; k++)
    {
        pivot = a[k][k];
        if (fabs(pivot) < 1e-6)
        {
            printf("Method failed due to zero pivot.\n");
            return -1;
        }

        for (i = k + 1; i <= m; i++)
        {
            term = a[i][k] / pivot;
            for (j = 0; j <= m; j++)
            {
                a[i][j] -= a[k][j] * term;
            }
            b[i] -= b[k] * term;
        }
    }

    // Back-substitution
    z[m] = b[m] / a[m][m];
    for (i = m - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j <= m; j++)
        {
            sum += a[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / a[i][i];
    }

    // Displaying the polynomial
    printf("\nThe polynomial of regression is:\n");
    printf("y = %.3f", z[0]);
    for (i = 1; i <= m; i++)
    {
        printf(" + %.3fx^%d", z[i], i);
    }
    printf("\n");

    // Lab details
    printf("\nName:Oshin Pant\nRollno:23\nLab no: 12");
    fflush(stdin);
	getchar();
	getchar();

    return 0;
}
