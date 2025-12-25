/*
4) Delete All Empty Regular Files
• Accept directory name.
• Delete files with size = 0 bytes (regular files only).
• Print names deleted + total deleted count.
*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char dirname[256];
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    int count = 0;

    printf("Enter the name of the directory : ");
    scanf("%s", dirname);

    // change working directory
    if(chdir(dirname) == -1)
    {
        perror("Unable to change directory");
        return -1;
    }

    // open current directory now
    dp = opendir(".");
    if(dp == NULL)
    {
        perror("Unable to open directory");
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        if(lstat(ptr->d_name, &sobj) == -1)
            continue;

        if(S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            if(unlink(ptr->d_name) == 0)
            {
                printf("Deleted: %s\n", ptr->d_name);
                count++;
            }
        }
    }

    closedir(dp);

    printf("\nTotal files deleted: %d\n", count);

    return 0;
}
