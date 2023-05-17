#include <stdio.h>

int main()
{
    int p_id, bt[10], at[10];
    int i;

    printf("Enter the number of process id : ");
    scanf("%d", &p_id);

    printf("Enter the arrival process : \n");
    for (i = 0; i < p_id; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst process : \n");
    for (i = 0; i < p_id; i++)
    {
        scanf("%d", &bt[i]);
    }
}
