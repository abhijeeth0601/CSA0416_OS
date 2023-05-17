#include <stdio.h>

void main()
{
    int processes[] = {0, 1, 2};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {2, 4, 8};
    int arrival_time[] = {0, 0, 0};

    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];

    completion_time[0] = burst_time[0];
    for (int i = 1; i < n; i++)
    {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }

    waiting_time[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waiting_time[i] = completion_time[i - 1] - arrival_time[i];
    }

    turnaround_time[0] = burst_time[0];
    for (int i = 1; i < n; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
    }

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}
