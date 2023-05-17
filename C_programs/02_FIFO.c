#include <stdio.h>

int main()
{
    int numberstream[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int pagefaults = 0, frames = 3;
    int pages, i, j, s;

    pages = sizeof(numberstream) / sizeof(numberstream[0]);
    printf("\nIncoming \t Frame 1 \t Frame 2 \t Frame 3 ");
    int temp[frames];
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }
    for (i = 0; i < pages; i++)
    {
        s = 0;
        for (j = 0; j < frames; j++)
        {
            if (numberstream[i] == temp[j])
            {
                s++;
                pagefaults--;
            }
        }
        pagefaults++;

        if ((pagefaults <= frames) && (s == 0))
        {
            temp[i] = numberstream[i];
        }
        else if (s == 0)
        {
            temp[(pagefaults - 1) % frames] = numberstream[i];
        }

        printf("\n");
        printf("%d\t\t", numberstream[i]);

        for (j = 0; j < frames; j++)
        {
            if (temp[j] != -1)
                printf(" %d\t\t", temp[j]);
            else
                printf(" - \t\t");
        }
    }

    printf("\n\nTotal page faults : %d\n\n", pagefaults);
    // printf("\n\nTotal non - page faults : %d\n\n", sizeof(numberstream) - pagefaults);

    return 0;
}
