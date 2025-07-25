//SJF
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int is_completed;
};

void display_table(struct Process p[], int n) {
    printf("\nPID\tAT\tBT\tST\tCT\tWT\tTAT\n");
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

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

void display_gantt_chart(struct Process p[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d(%d-%d) ", p[i].pid, p[i].start_time, p[i].completion_time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for Process P%d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].is_completed = 0;
    }

    int completed = 0, current_time = 0;
    while (completed < n) {
        int idx = -1, min_bt = 99999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && !p[i].is_completed) {
                if (p[i].burst_time < min_bt || 
                   (p[i].burst_time == min_bt && p[i].arrival_time < p[idx].arrival_time)) {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            p[idx].is_completed = 1;
            current_time = p[idx].completion_time;
            completed++;
        } else {
            current_time++; // CPU is idle
        }
    }

    display_table(p, n);

    // Sort by start time to print correct Gantt chart
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (p[j].start_time > p[j+1].start_time) {
                struct Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    display_gantt_chart(p, n);

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:5-b\n Sec:A");
    getchar();
    getchar();
    return 0;
}
