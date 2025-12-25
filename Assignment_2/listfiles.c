/*
3) List All Files From Directory
• Accept directory name.
• Use opendir() / readdir() to print only names (skip . and ..).
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
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
            continue;

        printf("%s\n", ptr->d_name);
    }

    closedir(dp);

    return 0;
}
