#include <stdio.h>

#define BLOCK_SIZE 1 // Size of each block in memory

// Contiguous Allocation
int contiguousAllocation(int blockCount)
{
    return blockCount + 1; // Number of blocks to be read/write (blockCount) + File Control Block (FCB)
}

// Linked Allocation
int linkedAllocation(int blockCount)
{
    return blockCount + 1; // Number of blocks to be read/write (blockCount) + File Control Block (FCB)
}

// Indexed Allocation
int indexedAllocation(int blockCount)
{
    return blockCount + 2; // Number of blocks to be read/write (blockCount) + Index Block + File Control Block (FCB)
}

int main()
{
    int blockCount = 100; // Number of blocks in the file

    // Adding a block at the beginning
    printf("Adding a block at the beginning:\n");
    printf("Contiguous Allocation: %d I/O operations\n", contiguousAllocation(blockCount));
    printf("Linked Allocation: %d I/O operations\n", linkedAllocation(blockCount));
    printf("Indexed Allocation: %d I/O operations\n", indexedAllocation(blockCount));

    // Adding a block in the middle
    printf("\nAdding a block in the middle:\n");
    printf("Contiguous Allocation: %d I/O operations\n", contiguousAllocation(blockCount));
    printf("Linked Allocation: %d I/O operations\n", linkedAllocation(blockCount));
    printf("Indexed Allocation: %d I/O operations\n", indexedAllocation(blockCount));

    // Adding a block at the end
    printf("\nAdding a block at the end:\n");
    printf("Contiguous Allocation: %d I/O operations\n", contiguousAllocation(blockCount));
    printf("Linked Allocation: %d I/O operations\n", linkedAllocation(blockCount));
    printf("Indexed Allocation: %d I/O operations\n", indexedAllocation(blockCount));

    return 0;
}