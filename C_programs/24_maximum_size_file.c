#include <stdio.h>

#define DBS 8192          // 8 KB Disk Block Size
#define PS 4              // Size of a pointer in bytes
#define DB 12             // Number of direct disk blocks
#define IBS (DBS / PS)    // Number of pointers in an indirect block
#define DIBS (IBS * IBS)  // Number of pointers in a double indirect block
#define TIBS (IBS * DIBS) // Number of pointers in a triple indirect block

int main()
{
    int max_file_size = 0;
    // Calculate the maximum file size for direct blocks
    max_file_size += DB * DBS;
    // Calculate the maximum file size for single indirect block

    int single_indirect_size = IBS * DBS;
    max_file_size += single_indirect_size;
    // Calculate the maximum file size for double indirect block

    int double_indirect_size = IBS * single_indirect_size;
    max_file_size += double_indirect_size;
    // Calculate the maximum file size for triple indirect block

    int triple_indirect_size = IBS * double_indirect_size;
    max_file_size += triple_indirect_size;

    printf("Maximum file size: %d bytes\n", max_file_size);

    return 0;
}