#include <stdio.h> 

#include <stdlib.h> 

void scan(int requests[], int n, int head, int disk_size, int direction) { 

    int total_movement = 0; 

    int left[n], right[n]; 

    int left_count = 0, right_count = 0; 

    for (int i = 0; i < n; i++) { 

        if (requests[i] < head) 

            left[left_count++] = requests[i]; 

        else 

            right[right_count++] = requests[i];} 

    for (int i = 0; i < left_count - 1; i++) 

        for (int j = i + 1; j < left_count; j++) 

            if (left[i] > left[j]) { 

                int temp = left[i]; 

                left[i] = left[j]; 

                left[j] = temp;} 

    for (int i = 0; i < right_count - 1; i++) 

        for (int j = i + 1; j < right_count; j++) 

            if (right[i] > right[j]) { 

                int temp = right[i]; 

                right[i] = right[j]; 

                right[j] = temp;} 

    printf("Sequence of head movement: %d", head); 

    if (direction == 0) {  

        for (int i = left_count - 1; i >= 0; i--) { 

            total_movement += abs(head - left[i]); 

            head = left[i]; 

            printf(" -> %d", head);} 

        if (head != 0) { 

            total_movement += head; 

            head = 0; 

            printf(" -> %d", head);} 

        for (int i = 0; i < right_count; i++) { 

            total_movement += abs(head - right[i]); 

            head = right[i]; 

            printf(" -> %d", head);} 

    } else { // Move towards right first 

        for (int i = 0; i < right_count; i++) { 

            total_movement += abs(head - right[i]); 

            head = right[i]; 

            printf(" -> %d", head);} 

        if (head != disk_size - 1) { 

            total_movement += abs(head - (disk_size - 1)); 

            head = disk_size - 1; 

            printf(" -> %d", head);} 

        for (int i = left_count - 1; i >= 0; i--) { 

            total_movement += abs(head - left[i]); 

            head = left[i]; 

            printf(" -> %d", head); 

        }} 

    printf("\nTotal head movement: %d\n", total_movement);} 

int main() { 

    int n, head, disk_size, direction; 

    printf("Enter total number of requests: "); 

    scanf("%d", &n); 

    int requests[n]; 

    printf("Enter the requests (space separated): "); 

    for (int i = 0; i < n; i++) 

        scanf("%d", &requests[i]); 

    printf("Enter initial head position: "); 

    scanf("%d", &head); 

    printf("Enter disk size (number of tracks): "); 

    scanf("%d", &disk_size); 

    printf("Enter direction (0 for left, 1 for right): "); 

    scanf("%d", &direction); 

    scan(requests, n, head, disk_size, direction); 

fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:10-c\n Sec:A");
    getchar();
    getchar();

 

  return 0; 

} 
