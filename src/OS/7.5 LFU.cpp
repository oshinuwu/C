#include <stdio.h>

int main() {
    int frames, pages, i, j, page_faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page_string[pages];
    printf("Enter the page reference string:\n");
    for (i = 0; i < pages; i++) {
        scanf("%d", &page_string[i]);
    }

    int frame_arr[frames], freq[frames];
    for (i = 0; i < frames; i++) {
        frame_arr[i] = -1;
        freq[i] = 0;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < pages; i++) {
        int flag = 0;
        for (j = 0; j < frames; j++) {
            if (frame_arr[j] == page_string[i]) {
                flag = 1;
                freq[j]++;
                break;
            }
        }

        if (flag == 0) {
            int empty_frame = -1;
            for (j = 0; j < frames; j++) {
                if (frame_arr[j] == -1) {
                    empty_frame = j;
                    break;
                }
            }

            if (empty_frame != -1) {
                frame_arr[empty_frame] = page_string[i];
                freq[empty_frame] = 1;
            } else {
                int lfu_index = 0;
                for (j = 1; j < frames; j++) {
                    if (freq[j] < freq[lfu_index]) {
                        lfu_index = j;
                    }
                }
                frame_arr[lfu_index] = page_string[i];
                freq[lfu_index] = 1;
            }
            page_faults++;
        }

        printf("After inserting page %d: ", page_string[i]);
        for (j = 0; j < frames; j++) {
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
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:7-e\n Sec:A");
    getchar();
    getchar();
    return 0;
}

