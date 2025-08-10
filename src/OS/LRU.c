#include <stdio.h>
int main()
{
    int frames, pages, i, j, k, page_faults = 0, flag;
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
    int recently_used[frames];
    for (i = 0; i < frames; i++)
    {
        frame_arr[i] = -1;
        recently_used[i] = -1;
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
                recently_used[j] = i;
                break;
            }
        }
        if (flag == 0)
        {
            int lru_index = 0, min = recently_used[0];
            int empty_frame = -1;
            for (j = 0; j < frames; j++)
            {
                if (frame_arr[j] == -1)
                {
                    empty_frame = j;
                    break;
                }
            }
            if (empty_frame != -1)
            {
                frame_arr[empty_frame] = page_string[i];
                recently_used[empty_frame] = i;
            }
            else
            {
                for (j = 1; j < frames; j++)
                {
                    if (recently_used[j] < min)
                    {
                        min = recently_used[j];
                        lru_index = j;
                    }
                }
                frame_arr[lru_index] = page_string[i];
                recently_used[lru_index] = i;
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
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:7-c\n Sec:A");
    getchar();
    getchar();
    return 0;
}
