
#include <stdio.h>

void fcfs_scheduling(int n, int burst_time[]);

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];

    printf("Enter the burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    fcfs_scheduling(n, burst_time);

    return 0;
}

void fcfs_scheduling(int n, int burst_time[]) {

    int waiting_time[n], turnaround_time[n];

    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    // Calculate waiting time and turnaround time
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];

        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Display results
    printf("\nFCFS Scheduling\n");

    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1,
               burst_time[i],
               waiting_time[i],
               turnaround_time[i]);
    }
}
