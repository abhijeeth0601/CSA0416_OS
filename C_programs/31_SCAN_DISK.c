#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *tracks, int num_tracks)
{
    for (int i = 0; i < num_tracks - 1; i++)
    {
        for (int j = 0; j < num_tracks - i - 1; j++)
        {
            if (tracks[j] > tracks[j + 1])
            {
                swap(&tracks[j], &tracks[j + 1]);
            }
        }
    }
}

int findMinIndex(const int *tracks, int num_tracks, int head)
{
    int min_diff = abs(tracks[0] - head);
    int min_index = 0;
    for (int i = 1; i < num_tracks; i++)
    {
        int diff = abs(tracks[i] - head);
        if (diff < min_diff)
        {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

int scanDiskScheduling(int *tracks, int num_tracks, int head, int direction)
{
    sort(tracks, num_tracks);
    int total_head_movement = 0;
    int current_track = head;
    int current_index = findMinIndex(tracks, num_tracks, head);
    if (direction == -1)
    {
        // Move towards smaller track numbers
        for (int i = current_index; i >= 0; i--)
        {
            total_head_movement += abs(tracks[i] - current_track);
            current_track = tracks[i];
        }
        total_head_movement += current_track; // Move to the leftmost track
        current_track = 0;

        for (int i = current_index + 1; i < num_tracks; i++)
        {
            total_head_movement += abs(tracks[i] - current_track);
            current_track = tracks[i];
        }
    }
    else
    {
        // Move towards larger track numbers
        for (int i = current_index; i < num_tracks; i++)
        {
            total_head_movement += abs(tracks[i] - current_track);
            current_track = tracks[i];
        }

        total_head_movement += (MAX_TRACKS - 1 - current_track); // Move to the rightmost track
        current_track = MAX_TRACKS - 1;

        for (int i = current_index - 1; i >= 0; i--)
        {
            total_head_movement += abs(tracks[i] - current_track);
            current_track = tracks[i];
        }
    }
    return total_head_movement;
}

int main()
{
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int head_position = 50; // Starting head position
    int direction = 1;      // Direction: 1 for moving towards larger track numbers, -1 for moving towards smaller track numbers
    int total_head_movement = scanDiskScheduling(tracks, num_tracks, head_position, direction);
    float average_head_movement = (float)total_head_movement / num_tracks;

    printf("Average head movement: %.2f\n", average_head_movement);
    return 0;
}
