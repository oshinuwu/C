#include <stdio.h>
void ss(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
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
    ss(a, n);
    printf("\nAfter sorting:\t");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nName:Oshin Pant Roll No:23 Lab No:10");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}