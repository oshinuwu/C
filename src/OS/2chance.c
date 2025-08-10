#include <stdio.h>
int main()
{
    int frames, pages, i, j, page_faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    int page_string[pages];
    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++)
    {
        scanf("%d", &page_string[i]);
    }
    int frame_arr[frames];
    int ref_bit[frames];
    for (i = 0; i < frames; i++)
    {
        frame_arr[i] = -1;
        ref_bit[i] = 0;
    }
    int pointer = 0;
    printf("\nPage Replacement Process:\n");
    for (i = 0; i < pages; i++)
    {
        int flag = 0;
        for (j = 0; j < frames; j++)
        {
            if (frame_arr[j] == page_string[i])
            {
                flag = 1;
                ref_bit[j] = 1;
                break;
            }
        }
        if (flag == 0)
        {
            while (1)
            {
                if (ref_bit[pointer] == 0)
                {
                    frame_arr[pointer] = page_string[i];
                    ref_bit[pointer] = 1;
                    pointer = (pointer + 1) % frames;
                    break;
                }
                else
                {
                    ref_bit[pointer] = 0;
                    pointer = (pointer + 1) % frames;
                }
            }
            page_faults++;
        }

        printf("After inserting page %d: ", page_string[i]);
        for (j = 0; j < frames; j++)
        {
            if (frame_arr[j] == -1)
                printf("- ");
            else
                printf("%d ", frame_arr[j]);
        }
        if (flag == 0)
            printf(" --> Page Fault\n");
        else
            printf(" --> No Page Fault\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    float fault_rate = ((float)page_faults / pages) * 100;
    printf("Page Fault Rate: %.2f%%\n", fault_rate);
    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:7-d\n Sec:A");
    getchar();
    getchar();
    return 0;
}
