#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void producer(int item)
{
    if ((in + 1) % BUFFER_SIZE == out)
    {
        printf("Buffer is full. Producer cannot produce.\n");
    }
    else
    {
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Producer produced item %d\n", item);
    }
}

void consumer()
{
    if (in == out)
    {
        printf("Buffer is empty. Consumer cannot consume.\n");
    }
    else
    {
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer consumed item %d\n", item);
    }
}

int main()
{
    // produce an item
    producer(1);

    // consume an item
    consumer();

    // produce four items
    producer(2);
    producer(3);
    producer(4);
    producer(5);

    // consume an item
    consumer();

    return 0;
}