#include <stdio.h>
int main()
{
    int n, nn, times = 0;

    printf("Number of elements of set 1 : ");
    scanf("%d", &n);
    printf("Number of elements of set 2 : ");
    scanf("%d", &nn);

    int set1[n], set2[nn];

    printf("\n\nEnter the elements of set 1 :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set1[i]);
    }

    printf("\n\nEnter the elements of set 2 :\n");
    for (int i = 0; i < nn; i++)
    {
        scanf("%d", &set2[i]);
    }

    printf("\n\nCartesian products :\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nn; j++)
        {
            times++;
            printf("(%d,%d)", set1[i], set2[j]);
        }
    }
    printf("\nThere are %d cartesian products here.", times);
    printf("\n\nName : Oshin Pant  Roll no. : 23  Lab 23");
    getch();
    return 0;
    
}