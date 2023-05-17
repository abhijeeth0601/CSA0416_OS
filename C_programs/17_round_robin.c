#include <stdio.h>

#define MAX_PROCESSES 10

// Structure to store process information
struct process
{
    int id;
    int bt;
    int rt;
    int wt;
    int tat;
};

int main()
{
    struct process p[MAX_PROCESSES];
    int n, quantum, i, j, time = 0, total_wt = 0, total_tat = 0;

    // Get input from user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    printf("Enter the CPU burst times for each process: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
        p[i].rt = p[i].bt;
    }

    // Run the Round Robin scheduling algorithm
    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (p[i].rt > 0)
            {
                done = 0;

                // Calculate waiting time for this process
                if (p[i].rt == p[i].bt)
                {
                    p[i].wt = time;
                }

                // Execute process for the quantum time or until it finishes
                if (p[i].rt <= quantum)
                {
                    time += p[i].rt;
                    p[i].rt = 0;
                }
                else
                {
                    time += quantum;
                    p[i].rt -= quantum;
                }

                // Calculate turnaround time for this process
                p[i].tat = time - p[i].bt;

                // Add waiting and turnaround times to totals
                total_wt += p[i].wt;
                total_tat += p[i].tat;
            }
        }

        // If all p have finished executing, exit the loop
        if (done == 1)
        {
            break;
        }
    }

    // Calculate and print average waiting and turnaround times
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);

    return 0;
}