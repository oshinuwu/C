#include <stdio.h>

int main()
{

    int i, j, k, flag, p, n1, n2, set1[10], set2[10], set3[20];

    printf("enter size of set 1\n");

    scanf("%d", &n1);

    printf("enter elements of set 1 \n");

    for (i = 0; i < n1; i++)
    {

        scanf("%d", &set1[i]);
    }

    printf("enter size of set 2\n");

    scanf("%d", &n2);

    printf("enter element of set 2 \n");

    for (i = 0; i < n2; i++)
    {

        scanf("%d", &set2[i]);
    }

    printf("\n union is \n");

    k = 0;

    for (i = 0; i < n1; i++)
    {

        set3[k] = set1[i];

        k++;
    }

    for (i = 0; i < n2; i++)
    {

        flag = 1;

        for (j = 0; j < n1; j++)
        {

            if (set2[i] == set1[j])
            { // Corrected condition

                flag = 0;

                break;
            }
        }

        if (flag == 1)
        {

            set3[k] = set2[i];

            k++;
        }
    }

    p = k;

    for (k = 0; k < p; k++)
    {

        printf("%d\t", set3[k]);
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:6");
    getch();

    return 0;
}