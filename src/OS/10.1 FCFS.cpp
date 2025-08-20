#include <stdio.h> 

#include <stdlib.h> 

void fcfs(int requests[], int n, int head) { 

    int total_movement = 0; 

    printf("Sequence of head movement: %d", head); 

    for (int i = 0; i < n; i++) { 

        total_movement += abs(requests[i] - head); 

        head = requests[i]; 

        printf(" -> %d", head);} 

    printf("\nTotal head movement: %d\n", total_movement); 

    printf("Average seek time: %.2f\n", (float)total_movement / n);} 

int main() { 

    int n, head; 

    printf("Enter number of requests: "); 

    scanf("%d", &n); 

    int requests[n]; 

    printf("Enter the requests (space separated): "); 

    for (int i = 0; i < n; i++) { 

        scanf("%d", &requests[i]);} 

    printf("Enter initial head position: "); 

    scanf("%d", &head); 

    fcfs(requests, n, head); 

 fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:10-a\n Sec:A");
    getchar();
    getchar();

    return 0; 

}  
