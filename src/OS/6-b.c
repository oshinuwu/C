#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], available[m];
    bool finish[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Maximum Matrix and calculate Need matrix
    printf("\nEnter Maximum Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    // Initialize finish[i] = false for all i
    for (int i = 0; i < n; i++)
        finish[i] = false;

    int process_completed = 0;

    while (1) {
        bool progress = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_run = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        can_run = false;
                        break;
                    }
                }

                if (can_run) {
                    // Pretend process finishes
                    for (int j = 0; j < m; j++) {
                        available[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    progress = true;
                    process_completed++;
                }
            }
        }

        // If no process could proceed in this cycle, break
        if (!progress)
            break;
    }

    if (process_completed == n) {
        printf("\nNo Deadlock Detected. System is in Safe State.\n");
    } else {
        printf("\nDeadlock Detected! The following processes are in deadlock:\n");
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    }

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:6-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}
