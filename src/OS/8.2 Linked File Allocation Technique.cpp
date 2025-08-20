#include <stdio.h>
int main()
{
    int files[50], next[50], i, start, length, j, k, n;

    // Initialize arrays
    for (i = 0; i < 50; i++)
    {
        files[i] = 0;
        next[i] = -1;
    }
    printf("Enter how many files to be allocated: ");
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        printf("\nEnter the starting block and length of file %d: ", k + 1);
        scanf("%d %d", &start, &length);

        j = start;
        int prev = -1;
        while (length > 0)
        {
            if (files[j] == 0)
            {
                files[j] = 1;

                if (prev != -1)
                {
                    next[prev] = j;
                }
                prev = j;

                printf("Block %d allocated.\n", j);
                j = (j + 1) % 50;
                length--;
            }
            else
            {
                printf("Block %d is already allocated, searching next free block...\n", j);
                j = (j + 1) % 50;
            }
        }
    }

    printf("\nLinked Allocation Status:\n");
    for (i = 0; i < 50; i++)
    {
        if (files[i] == 1)
        {
            printf("Block %d -> ", i);
            if (next[i] != -1)
                printf("%d\n", next[i]);
            else
                printf("NULL\n");
        }
    }

    fflush(stdin);
    printf("\nName:Oshin Pant\n Roll no:23\n Lab no:8-b\n Sec:A");
    getchar();
    getchar();

    return 0;
}
