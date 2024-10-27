#include <stdio.h>

int main()
{

    int i, j, k, flag, p, n1, n2, set1[10], set2[10], set3[10];

    printf("enter size of set 1\n");

    scanf("%d", &n1);

    printf("enter element of set 1 \n");

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

    printf("\n intersection is \n");

    k = 0;

    for (i = 0; i < n2; i++) // Iterate over set2
    {
        flag = 0;

        for (j = 0; j < n1; j++) // Iterate over set1
        {
            if (set2[i] == set1[j])
            {
                flag = 1;
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
    printf("\nName:Oshin Pant Roll No:23 Lab No:7");
    getch();

    return 0;
}