
#include <stdio.h>

int main()
{
    int i, j, m, n;
    int allocation[5][3], max[5][3], need[5][3], available[3], safe[4];
    int status[4];
    int complete = 0, iter = 0;

    for (i = 0; i < n; i++)
    {
        status[i] = 0;
        safe[i] = 0;
    }

    printf("Enter the number of n for allocation and matrix: ");
    scanf("%d", &n);

    printf("Enter the number of m for allocation and matrix : ");
    scanf("%d", &m);

    printf("Enter the element for matrix : \n");
    for (i = 0; i < n; i++) // 0 --> 0 1 2, 1 --> 0 1 2, 2--> 0 1 2, 3 --> 0 1 2
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter matrix[%d][%d] = ", i, j); // {0,0}{0,1}{0,2}, {1,0}{1,1}{1,2}
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nThe Matrix : \nA\tB\tC\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", max[i][j]);
        }
        printf("\n");
    }

    printf("Enter the element for allocation : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter allocation[%d][%d] = ", i, j);
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("\nThe Allocation : \nA\tB\tC\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", allocation[i][j]);
        }
        printf("\n");
    }
    printf("The Need with subtracting max and allocation : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("The need[%d][%d] : %d\n", i, j, need[i][j]);
        }
    }
    printf("\nThe Need Matrix : \nA\tB\tC\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
    {
        printf("\n Enter the available resources for the %d : ", i);
        scanf("%d", &available[i]);
    }

    i = 0;
    complete = 0;
    iter = 0;
    while (complete < n && iter < 2)
    {
        if (status[i] == 0 && need[i][0] <= available[0] && need[i][1] <= available[1] && need[i][2] <= available[2])
        {
            available[0] += allocation[i][0];
            available[1] += allocation[i][1];
            available[2] += allocation[i][2];
            status[i] = 1;
            safe[complete] = i;
            complete++;
        }
        if (i < n)
            i++;
        else
        {
            i = 0;
            iter++;
        }
    }

    if (complete < n - 1)
    {
        printf("\n The system is in unsafe state");
    }
    else
    {
        printf("\n The safe sequence is ");
        for (i = 0; i < n; i++)
        {
            printf("%d -> ", safe[i]);
        }

        printf("\n the total no of resource available is ");
        for (i = 0; i < m; i++)
        {
            printf("\n the available resources for the %d ", available[i]);
        }
    }
    return 0;
}