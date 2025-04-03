#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int key = 3;
    int i;

    for (i = 0; i < 7; i++)
    {
        if (arr[i] == key)
        {
            printf("\nElement found in index %d ", i);
            break;
        }
        printf("\nElement not found in index %d", i);
    }
    printf("\nName:Oshin Pant Roll No:23 Lab No:6");
    fflush(stdin);
	getchar();
    getchar();
    return 0;
}
