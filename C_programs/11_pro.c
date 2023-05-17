#include <stdio.h>
#include <process.h>

int main()
{
    int p, i, j;
    int p_id[4];
    printf("Enter the number of process : ");
    scanf("%d", &p);

    printf("Each Process Functions : \n");
    for (i = 0; i < p; i++)
    {
        if (i == 0)
        {
            printf("For Child process %d is ", i + 1);
            for (j = 1; j <= 10; j += 2)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        else if (i == 1)
        {
            printf("For Child process %d is ", i + 1);
            for (j = 2; j <= 10; j += 2)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        else if (i == 2)
        {
            printf("For Child process %d is ", i + 1);
            for (j = 3; j <= 30; j += 3)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
        else if (i == 3)
        {
            printf("For Child process %d is ", i + 1);
            for (j = 0; j <= 50; j += 5)
            {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
}