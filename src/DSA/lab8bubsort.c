#include <stdio.h>
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < (n - 1); i++)
    {
        for (j = 0; j < (n - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[50], n, i;
    printf("Enter the value of n:");
    scanf("%d", &n);
    printf("\nEnter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nBefore sorting:\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    bubble_sort(a, n);
    printf("\nAfter sorting:\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:8");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}