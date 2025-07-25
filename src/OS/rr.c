//rr.c
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].is_completed = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int completed = 0, current_time = 0, idle_flag = 0;
    int queue[100], front = 0, rear = 0;
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("\nGantt Chart:\n");

    while (completed < n) {
        // Enqueue newly arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (front == rear) {
            // No process in queue, CPU idle
            printf("Idle(%d-%d) ", current_time, current_time + 1);
            current_time++;
            continue;
        }

        int idx = queue[front++];
        int exec_time = (p[idx].remaining_time > tq) ? tq : p[idx].remaining_time;

        printf("P%d(%d-%d) ", p[idx].pid, current_time, current_time + exec_time);

        current_time += exec_time;
        p[idx].remaining_time -= exec_time;

        // Enqueue new processes during execution
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time > current_time - exec_time &&
                p[i].arrival_time <= current_time && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (p[idx].remaining_time == 0) {
            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].is_completed = 1;
            completed++;
        } else {
            queue[rear++] = idx; // Requeue
        }
    }

    // Print result
    float total_wt = 0, total_tat = 0;
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time,
               p[i].turnaround_time,
               p[i].waiting_time);
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    fflush(stdin);
    printf("Name:Oshin Pant\n Roll no:23\n Lab no:5-d\n Sec:A");
    getchar();
    getchar();
    return 0;
}
