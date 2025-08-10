#include <stdio.h>
int main()
{
    int frames, pages, i, j, k, page_faults = 0, flag, index = 0;
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
    for (i = 0; i < frames; i++)
    {
        frame_arr[i] = -1;
    }
    printf("\nPage Replacement Process:\n");
    for (i = 0; i < pages; i++)
    {
        flag = 0;
        for (j = 0; j < frames; j++)
        {
            if (frame_arr[j] == page_string[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            frame_arr[index] = page_string[i];
            index = (index + 1) % frames;
            page_faults++;
        }
        printf("After inserting page %d: ", page_string[i]);
        for (k = 0; k < frames; k++)
        {
            if (frame_arr[k] == -1)
                printf("- ");
            else
                printf("%d ", frame_arr[k]);
        }
        if (flag == 0)
            printf(" --> Page Fault");
        else
            printf(" --> No Page Fault");
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);
    float fault_rate = ((float)page_faults / pages) * 100;
    printf("Page Fault Rate: %.2f%%\n", fault_rate);
    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:7-a\n Sec:A");
    getchar();
    getchar();
}
