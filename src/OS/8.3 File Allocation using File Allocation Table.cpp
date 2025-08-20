#include <stdio.h>

int main()
{

    int fat[50], files[50], i, j, n, start, length, prev;
    for (i = 0; i < 50; i++)
    {

        fat[i] = -1; // -1 indicates end of file or free block
        files[i] = 0; // 0 indicates block is free
    }

    printf("Enter number of files to be allocated: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d %d", &start, &length);

        if (files[start] == 1)
        {
            printf("Starting block %d is already allocated. File cannot be allocated.\n", start);
            continue;
        }

        files[start] = 1;
        prev = start;
        int allocated = 1;

        for (j = 1; j < length; j++)
        {
            int found = 0;
            for (int k = 0; k < 50; k++)
            {
                if (files[k] == 0)
                {
                    files[k] = 1;
                    fat[prev] = k;
                    prev = k;
                    found = 1;

                    break;
                }
            }

            if (!found)
            {
                printf("Insufficient free blocks to allocate file %d completely.\n", i + 1);
                allocated = 0;
                break;
            }
        }

        fat[prev] = -1; // Mark end of file
        if (allocated)
        {

            printf("File %d allocated successfully.\n", i + 1);
        }
    }

    printf("\nFile Allocation Table (FAT):\n");
    printf("Block\tNext Block\n");

    for (i = 0; i < 50; i++)
    {
        if (files[i] == 1)
        {
            printf("%d\t", i);
            if (fat[i] == -1)
                printf("End\n");

            else
                printf("%d\n", fat[i]);
        }
    }

    fflush(stdin);
    printf("\nName:Oshin Pant\n Roll no:23\n Lab no:8-c\n Sec:A");
    getchar();
    getchar();

    return 0;
}
