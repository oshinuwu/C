#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int absDiff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}
int main() {
    int n, i, j, current, minDist, minIndex;
    int totalSeek = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    bool visited[n];
    printf("Enter the disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        visited[i] = false;
    }
    printf("Enter the initial head position: ");
    scanf("%d", &current);
    printf("\nSSTF Disk Scheduling:\n");
    printf("Order of servicing: ");
    for (i = 0; i < n; i++) {
        minDist = 1e9;
        minIndex = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = absDiff(current, requests[j]);
                if (distance < minDist) {
                    minDist = distance;
                    minIndex = j;
                }
            }
        }
        visited[minIndex] = true;
        totalSeek += absDiff(current, requests[minIndex]);
        current = requests[minIndex];
        printf("%d ", current);
    }
    printf("\nTotal seek time: %d\n", totalSeek);
    printf("Average seek time: %.2f\n", (float)totalSeek / n);
 fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:10-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}

