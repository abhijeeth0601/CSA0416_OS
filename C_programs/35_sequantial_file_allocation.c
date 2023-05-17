#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for exit()

#define BLOCK_SIZE 1024
#define TOTAL_BLOCKS 16
#define INODE_BLOCKS 8
#define FIRST_DATA_BLOCK 8
#define MIN_FILE_SIZE 1024

typedef struct {
    int start_block;
    int num_blocks;
} FileAllocation;

bool is_block_free(int block_number, bool allocated_blocks[]) {
    if (block_number < FIRST_DATA_BLOCK || block_number >= TOTAL_BLOCKS)
        return false;
    
    return !allocated_blocks[block_number];
}

FileAllocation allocate_blocks(int num_blocks, bool allocated_blocks[]) {
    FileAllocation allocation;
    allocation.start_block = -1;
    allocation.num_blocks = 0;

    int consecutive_blocks = 0;
    for (int block = FIRST_DATA_BLOCK; block < TOTAL_BLOCKS; block++) {
        if (is_block_free(block, allocated_blocks)) {
            if (consecutive_blocks == 0) {
                allocation.start_block = block;
            }
            
            consecutive_blocks++;
            
            if (consecutive_blocks == num_blocks) {
                allocation.num_blocks = num_blocks;
                break;
            }
        } else {
            consecutive_blocks = 0;
            allocation.start_block = -1;
        }
    }
    
    return allocation;
}

int main() {
    bool allocated_blocks[TOTAL_BLOCKS] = { false };
    int num_files;
    
    printf("Enter the number of files to create: ");
    scanf("%d", &num_files);
    
    for (int i = 0; i < num_files; i++) {
        int file_size;
        printf("Enter the size of file %d (in KB): ", i + 1);
        scanf("%d", &file_size);
        
        if (file_size < MIN_FILE_SIZE) {
            printf("Minimum file size is 1 KB. Exiting program.\n");
            exit(1);
        }
        
        int num_blocks_required = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
        FileAllocation allocation = allocate_blocks(num_blocks_required, allocated_blocks);
        
        if (allocation.start_block == -1) {
            printf("Not enough contiguous blocks available for file %d. Exiting program.\n", i + 1);
            exit(1);
        }
        
        printf("File %d allocated blocks: ", i + 1);
        for (int block = allocation.start_block; block < allocation.start_block + allocation.num_blocks; block++) {
            printf("%d ", block);
            allocated_blocks[block] = true;
        }
        printf("\n");
    }
    
    return 0;
}
