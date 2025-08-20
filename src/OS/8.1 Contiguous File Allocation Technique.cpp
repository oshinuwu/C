#include <stdio.h>
int main()
{

    int files[50], index[50], i, j, start, length, k, c, count = 0;
    int n;
    for (i = 0; i < 50; i++)
        files[i] = 0;

    printf("Enter how many files to be allocated: ");
    scanf("%d", &n);

    for (k = 0; k < n; k++)
    {
        printf("\nEnter the starting block and length of file %d: ", k + 1);
        scanf("%d %d", &start, &length);
        for (j = start; j < (start + length); j++)
        {
            if (files[j] == 0)
                count++;
        }

        if (length == count)
        {
            for (j = start; j < (start + length); j++)
            {
                if (files[j] == 0)
                {
                    files[j] = 1;
                    printf("Block %d allocated.\n", j);
                }
            }
        }
        else
        {
            printf("File %d cannot be allocated due to insufficient space.\n", k + 1);
        }
        count = 0;
    }

    printf("\nAllocation status:\n");

    for (i = 0; i < 50; i++)
        printf("%d ", files[i]);

    fflush(stdin);
    printf("\nName:Oshin Pant\n Roll no:23\n Lab no:8-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}