/*
4) Delete All Empty Regular Files
• Accept directory name.
• Delete files with size = 0 bytes (regular files only).
• Print names deleted + total deleted count.
*/

#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main()
{
    char dirname[20];
    DIR *dp;
    struct dirent *ptr;

    memset(dirname, '\0', sizeof(dirname));

    printf("Enter the name of the directory : ");
    scanf("%s", dirname);

    dp = opendir(dirname);

    if(dp == NULL)
    {
        perror("Unable to open directory");
        return -1;
    }

    while((ptr = readdir(dp)) != NULL)
    {
        if((ptr->d_reclen) == 0)
        {
            unlink(ptr->d_name);
        }

    }

    closedir(dp);

    return 0;
}
