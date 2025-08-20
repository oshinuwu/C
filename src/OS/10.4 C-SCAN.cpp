#include <stdio.h> 

#include <stdlib.h> 

void cscan(int requests[], int n, int head, int disk_size) { 

    int i, j, total_movement = 0; 

    int left[50], right[50]; 

    int left_count = 0, right_count = 0; 

    for(i = 0; i < n; i++) { 

        if(requests[i] < head) 

            left[left_count++] = requests[i]; 

        else 

            right[right_count++] = requests[i];} 

    for(i = 0; i < left_count-1; i++) { 

        for(j = 0; j < left_count-1-i; j++) { 

            if(left[j] > left[j+1]) { 

                int temp = left[j]; 

                left[j] = left[j+1]; 

                left[j+1] = temp;}}} 

    for(i = 0; i < right_count-1; i++) { 

        for(j = 0; j < right_count-1-i; j++) { 

            if(right[j] > right[j+1]) { 

                int temp = right[j]; 

                right[j] = right[j+1]; 

                right[j+1] = temp;}}} 

    printf("Sequence of head movement: %d", head); 

    for(i = 0; i < right_count; i++) { 

        total_movement += abs(right[i] - head); 

        head = right[i]; 

        printf(" -> %d", head);} 

    if(left_count > 0) { 

        total_movement += abs(disk_size - 1 - head);  // move to end 

        total_movement += disk_size - 1;              // jump to beginning (track 0) 

        head = 0; 

        printf(" -> %d", head); 

        for(i = 0; i < left_count; i++) { 

            total_movement += abs(left[i] - head); 

            head = left[i]; 

            printf(" -> %d", head);}} 

    printf("\nTotal head movement: %d\n", total_movement); 

    printf("Average seek time: %.2f\n", (float)total_movement / n);} 

int main() { 

    int n, head, disk_size; 

    printf("Enter number of requests: "); 

    scanf("%d", &n); 

    int requests[n]; 

    printf("Enter the requests (space separated): "); 

    for(int i = 0; i < n; i++) { 

        scanf("%d", &requests[i]); 

    } 

    printf("Enter initial head position: "); 

    scanf("%d", &head); 

    printf("Enter disk size (number of tracks): "); 

    scanf("%d", &disk_size); 

    cscan(requests, n, head, disk_size); 

fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:10-d\n Sec:A");
    getchar();
    getchar();

    return 0;} 
