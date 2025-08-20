#include <stdio.h> 

#include <stdlib.h> 

int compare(const void *a, const void *b) { 

    return (*(int*)a - *(int*)b);} 

void c_look(int requests[], int n, int head) { 

    int left[50], right[50]; 

    int lcount = 0, rcount = 0; 

    int total_movement = 0; 

    int i; 

    for(i = 0; i < n; i++) { 

     if(requests[i] < head) 

            left[lcount++] = requests[i]; 

        else 

            right[rcount++] = requests[i];} 

    qsort(left, lcount, sizeof(int), compare); 

    qsort(right, rcount, sizeof(int), compare); 

    printf("Sequence of head movement: %d", head); 

    for(i = 0; i < rcount; i++) { 

        total_movement += abs(right[i] - head); 

        head = right[i]; 

        printf(" -> %d", head);} 

    if (lcount > 0) { 

        total_movement += abs(head - left[0]); 

        head = left[0]; 

        printf(" -> %d", head); 

        for(i = 1; i < lcount; i++) { 

            total_movement += abs(left[i] - head); 

            head = left[i]; 

            printf(" -> %d", head);}} 

    printf("\nTotal head movement: %d\n", total_movement); 

    printf("Average seek time: %.2f\n", (float)total_movement / n);} 

int main() { 

    int n, head; 

    printf("Enter number of requests: "); 

    scanf("%d", &n); 

    int requests[n]; 

    printf("Enter the requests (space separated): "); 

    for(int i = 0; i < n; i++) { 

   scanf("%d", &requests[i]);} 

    printf("Enter initial head position: "); 

    scanf("%d", &head); 

    c_look(requests, n, head); 

 fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:10-f\n Sec:A");
    getchar();
    getchar();

    return 0;} 
