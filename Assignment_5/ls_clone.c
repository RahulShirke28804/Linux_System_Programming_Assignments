/*
1) Directory Traversal Basics
Create a program ls_clone.c that takes one directory path and prints:
• Entry name
• Type (file/dir/link/other)
• Size (bytes)
• Permissions in rwxr-xr-x format
• Last modified time
• Skip . and ...
• Build full path using snprintf(dir + "/" + name).
*/


#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char dirname[256];
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    char path[512];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dp = opendir(dirname);
    if(dp == NULL)
    {
        perror("Unable to open directory");
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        // printf(path, sizeof(path), "%s/%s", dirname, ptr->d_name);

        if(lstat(ptr->d_name, &sobj) == -1)
        {
            perror("lstat failed");
            continue;
        }

        printf("%s : ", ptr->d_name);

        if(S_ISREG(sobj.st_mode))
            printf("Regular File\n");
        else if(S_ISDIR(sobj.st_mode))
            printf("Directory\n");
        else if(S_ISLNK(sobj.st_mode))
            printf("Symbolic Link\n");
        else if(S_ISCHR(sobj.st_mode))
            printf("Character Device\n");
        else if(S_ISBLK(sobj.st_mode))
            printf("Block Device\n");
        else if(S_ISFIFO(sobj.st_mode))
            printf("FIFO (Named Pipe)\n");
        else if(S_ISSOCK(sobj.st_mode))
            printf("Socket\n");
        else
            printf("Unknown\n");
    }

    closedir(dp);

    return 0;
}
