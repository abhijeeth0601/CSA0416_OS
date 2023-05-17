#include <stdio.h>

int main()
{
    int i, process, bt[4], ct[4], wt[4], tat[4];
    int completion_time = 0, waiting_time = 0, turnaround_time = 0;

    printf("\nEnter the number of processes : ");
    scanf("%d", &process);

    for (i = 0; i < process; i++)
    {
        printf("The burst time of [%d] : ", i);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < process; i++)
    {
        if (i == 0)
        {
            ct[i] = bt[i];
            wt[i] = 0;
            tat[i] = wt[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
            wt[i] = ct[i - 1];
            tat[i] = wt[i] + bt[i];
        }
    }

    printf("\nCompletion Time : \n");
    for (i = 0; i < process; i++)
    {
        printf("\n%d", ct[i]);
        completion_time = completion_time + ct[i];
    }
    printf("\nThe average completion time is %d", completion_time / process);
    printf("\n");
    printf("\nWaiting Time : \n");
    for (i = 0; i < process; i++)
    {
        printf("\n%d", wt[i]);
        waiting_time = waiting_time + wt[i];
    }
    printf("\nThe average waiting time is %d", waiting_time / process);
    printf("\n");
    printf("\nTurn Around Time : \n");
    for (i = 0; i < process; i++)
    {
        printf("\n%d", tat[i]);
        turnaround_time = turnaround_time + tat[i];
    }
    printf("\nThe average turnaround time is %d", turnaround_time / process);
}