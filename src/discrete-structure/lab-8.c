#include <stdio.h>

int main()
{

    int i, j, k, flag, p, n1, n2, universal[10], set1[10], set2[10], complement[10];

    printf("Enter the size of the universal set\n");

    scanf("%d", &n2);

    printf("Enter the elements of the universal set\n");

    for (i = 0; i < n2; i++)
    {

        scanf("%d", &universal[i]);
    }

    printf("Enter the size of set 1\n");

    scanf("%d", &n1);

    printf("Enter the elements of set 1\n");

    for (i = 0; i < n1; i++)
    {

        scanf("%d", &set1[i]);
    }

    printf("\nThe complement is \n");

    k = 0;

    for (i = 0; i < n2; i++)
    {

        flag = 1;

        for (j = 0; j < n1; j++)
        {

            if (universal[i] == set1[j])
            {

                flag = 0;

                break;
            }
        }

        if (flag == 1)
        {

            complement[k] = universal[i];

            k++;
        }
    }

    p = k;

    for (k = 0; k < p; k++)
    {

        printf("%d\t", complement[k]);
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:8");
    getch();

    return 0;
}