#include <stdio.h>

// Function to print a matrix

void printMatrix(int matrix[5][5], int rows, int cols)
{

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {

            printf("%d\t", matrix[i][j]);
        }

        printf("\n");
    }
}

// Function to perform boolean product of two matrices

void booleanProduct(int first[5][5], int second[5][5], int result[5][5], int m, int n, int p, int q)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < q; j++)
        {

            result[i][j] = 0;

            for (int k = 0; k < n; k++)
            {

                result[i][j] = result[i][j] || (first[i][k] && second[k][j]);
            }
        }
    }
}

// Function to perform boolean meet of two matrices

void booleanMeet(int first[5][5], int second[5][5], int result[5][5], int m, int n, int p, int q)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (j < q)
            {

                result[i][j] = first[i][j] && second[i][j];
            }
            else
            {

                result[i][j] = first[i][j];
            }
        }
    }
}

// Function to perform boolean join of two matrices

void booleanJoin(int first[5][5], int second[5][5], int result[5][5], int m, int n, int p, int q)
{

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (j < q)
            {

                result[i][j] = first[i][j] || second[i][j];
            }
            else
            {

                result[i][j] = first[i][j];
            }
        }
    }
}

int main()
{

    int m, n, p, q, i, j, k;

    int first[5][5], second[5][5], result[5][5];

    printf("Enter the number of rows and columns of the first matrix: ");

    scanf("%d %d", &m, &n);

    printf("Enter the elements of the first matrix: \n");

    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
        {

            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");

    scanf("%d %d", &p, &q);

    printf("Enter the elements of the second matrix: \n");

    for (i = 0; i < p; i++)
    {

        for (j = 0; j < q; j++)
        {

            scanf("%d", &second[i][j]);
        }
    }

    printf("First Matrix: \n");

    printMatrix(first, m, n);

    printf("Second Matrix: \n");

    printMatrix(second, p, q);

    // Perform boolean product

    if (n != p)
    {

        printf("Matrices cannot be multiplied. Number of columns in first matrix must be equal to number of rows in second matrix.\n");
    }
    else
    {

        booleanProduct(first, second, result, m, n, p, q);

        printf("Boolean Product: \n");

        printMatrix(result, m, q);
    }

    // Perform boolean meet

    if (m != p)
    {

        printf("Matrices cannot be joined. Number of rows must be the same.\n");
    }
    else
    {

        booleanMeet(first, second, result, m, n, p, q);

        printf("Boolean Meet: \n");

        printMatrix(result, m, n);
    }

    // Perform boolean join

    if (m != p)
    {

        printf("Matrices cannot be joined. Number of rows must be the same.\n");
    }
    else
    {

        booleanJoin(first, second, result, m, n, p, q);

        printf("Boolean Join: \n");

        printMatrix(result, m, n);
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:12");	 
    getch();

    return 0;
}