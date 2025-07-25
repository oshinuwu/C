// Banker's Algorithm (Fixed Version)
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void calculate_need(int need[][MAX_RESOURCES], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool is_safe_state(int processes, int resources, int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculate_need(need, max, allocation, processes, resources);

    bool finish[MAX_PROCESSES] = {false};
    int work[MAX_RESOURCES];
    for (int i = 0; i < resources; i++)
        work[i] = available[i];

    int count = 0;
    int safe_sequence[MAX_PROCESSES];

    while (count < processes) {
        bool found = false;
        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                bool can_allocate = true;
                for (int r = 0; r < resources; r++) {
                    if (need[p][r] > work[r]) {
                        can_allocate = false;
                        break;
                    }
                }
                if (can_allocate) {
                    for (int r = 0; r < resources; r++)
                        work[r] += allocation[p][r];

                    safe_sequence[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("\n❌ System is in an **Unsafe State** (Deadlock Detected)!\n");
            printf("Processes that could NOT finish: ");
            for (int i = 0; i < processes; i++)
                if (!finish[i])
                    printf("P%d ", i);
            printf("\n");
            return false;
        }
    }

    printf("\n✅ System is in a Safe State.\nSafe sequence is: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d", safe_sequence[i]);
        if (i != processes - 1) printf(" -> ");
    }
    printf("\n");
    return true;
}

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];

    printf("Enter available instances of each resource:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    printf("Enter maximum demand of each process for each resource:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter allocation of each process for each resource:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d:\n", i);
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    is_safe_state(n, m, available, max, allocation);

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:6-a\n Sec:A");
    getchar();
    getchar();
    return 0;
}
