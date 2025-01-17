#include <stdio.h>
void merge_sort(int a[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, h);
        merge(a, l, m, h);
    }
}
void merge(int a[], int l, int m, int h)
{
    int temp[50];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];

        else
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= h)
        temp[k++] = a[j++];

    for (i = l; i <= h; i++)
    {
        a[i] = temp[i];
    }
}

int main()
{
    int a[50], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge_sort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
   
    getch();
    return 0;
}