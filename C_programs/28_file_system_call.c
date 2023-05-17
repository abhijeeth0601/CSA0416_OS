#include <stdio.h>
#include<string.h>

#define MAX_SIZE 100

int main() {
    FILE *file;
    char filename[100];
    char data[MAX_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        return 1;
    }

    printf("Enter data to write to the file (maximum 100 characters):\n");
    scanf(" %s", data);

    // Write data to the file
    fprintf(file, "%s", data);
    printf("Data written to the file successfully.\n");

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return 1;
    }

    // Read data from the file
    printf("Data read from the file:\n");
    fgets(data, MAX_SIZE, file);
    printf("%s\n", data);

    // Close the file
    fclose(file);

    return 0;
}

