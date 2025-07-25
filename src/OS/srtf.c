//srtf
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_started;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int completed = 0, current_time = 0;
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].is_started = 0;
    }

    int prev = -1;
    printf("\nGantt Chart:\n");

    while (completed < n) {
        int idx = -1;
        int min_rt = 99999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0) {
                if (p[i].remaining_time < min_rt || 
                    (p[i].remaining_time == min_rt && p[i].arrival_time < p[idx].arrival_time)) {
                    min_rt = p[i].remaining_time;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (!p[idx].is_started) {
                p[idx].start_time = current_time;
                p[idx].is_started = 1;
            }

            if (prev != idx) {
                if (prev != -1 && p[prev].remaining_time != 0)
                    printf("%d) ", current_time);
                printf("P%d(%d-", p[idx].pid, current_time);
            }

            current_time++;
            p[idx].remaining_time--;

            if (p[idx].remaining_time == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_wt += p[idx].waiting_time;
                total_tat += p[idx].turnaround_time;
                completed++;

                printf("%d) ", current_time);
                prev = -1;
            } else {
                prev = idx;
            }

        } else {
            if (prev != -2) {
                printf("Idle(%d-", current_time);
                prev = -2;
            }
            current_time++;
            if (prev == -2) {
                printf("%d) ", current_time);
                prev = -1;
            }
        }
    }

    // Print table
    printf("\n\nPID\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].start_time,
               p[i].completion_time,
               p[i].waiting_time,
               p[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:5-c\n Sec:A");
    getchar();
    getchar();
    return 0;
}
