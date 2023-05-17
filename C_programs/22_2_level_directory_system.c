#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES_PER_USER 3
#define MAX_FILENAME_LENGTH 20

typedef struct
{
    char username[MAX_FILENAME_LENGTH];
    char files[MAX_FILES_PER_USER][MAX_FILENAME_LENGTH];
    int fileCount;
} UserDirectory;

typedef struct
{
    UserDirectory userDirectories[MAX_USERS];
    int userCount;
} FileSystem;

void createUserDirectory(FileSystem *fs, const char *username)
{
    if (fs->userCount >= MAX_USERS)
    {
        printf("Maximum number of users reached.\n");
        return;
    }

    UserDirectory *newUserDir = &(fs->userDirectories[fs->userCount]);
    strcpy(newUserDir->username, username);
    newUserDir->fileCount = 0;
    fs->userCount++;
}

void createFile(UserDirectory *userDir, const char *filename)
{
    if (userDir->fileCount >= MAX_FILES_PER_USER)
    {
        printf("Maximum number of files reached for user %s.\n", userDir->username);
        return;
    }

    strcpy(userDir->files[userDir->fileCount], filename);
    userDir->fileCount++;
}

void displayFileSystem(const FileSystem *fs)
{
    printf("FileSystem:\n");

    for (int i = 0; i < fs->userCount; i++)
    {
        const UserDirectory *userDir = &(fs->userDirectories[i]);
        printf("User: %s\n", userDir->username);
        printf("Files: ");
        for (int j = 0; j < userDir->fileCount; j++)
        {
            printf("%s ", userDir->files[j]);
        }
        printf("\n");
    }
}

int main()
{
    FileSystem fs;
    fs.userCount = 0;

    createUserDirectory(&fs, "user1");
    createUserDirectory(&fs, "user2");
    createUserDirectory(&fs, "user3");

    createFile(&(fs.userDirectories[0]), "file1.txt");
    createFile(&(fs.userDirectories[0]), "file2.txt");
    createFile(&(fs.userDirectories[0]), "file3.txt");

    createFile(&(fs.userDirectories[1]), "file4.txt");
    createFile(&(fs.userDirectories[1]), "file5.txt");

    createFile(&(fs.userDirectories[2]), "file6.txt");
    createFile(&(fs.userDirectories[2]), "file7.txt");

    displayFileSystem(&fs);

    return 0;
}