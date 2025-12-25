/*
4) Display Complete File Information
• Accept file name and display file metadata using stat():
◦ Size, inode, permissions, hard links, owner uid/gid, file type, last access/modify time.
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>    
#include<string.h>

int main()
{
    int fd = 0;

    char str[20];

    memset(str,'\0',sizeof(str));

    printf("Enter the name of file that you want to open : ");
    scanf("%s",str);

    struct stat sobj;

    stat(str,&sobj);

    printf("File size : %lu\n",sobj.st_size);
    printf("Inode number : %lu\n",sobj.st_ino);
    printf("File Permissions : %u\n",sobj.st_mode);
    printf("Number of hard links : %lu\n",sobj.st_nlink);
    printf("Owner id : %u\n",sobj.st_uid);
    printf("Group id : %u\n",sobj.st_gid);
    printf("Last access time : %lu\n",sobj.st_atime);
    printf("Last modified time : %lu\n",sobj.st_mtime);
    printf("File type : ");

    if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if (S_ISCHR(sobj.st_mode))
    {
        printf("Character Device\n");
    }
    else if (S_ISDIR(sobj.st_mode))
    {
        printf("Directory File\n");
    }
    else if (S_ISREG(sobj.st_mode))
    {
        printf("Regular File\n");
    }
    else if (S_ISSOCK(sobj.st_mode))
    {
        printf("socke File\n");
    }
    else if (S_ISFIFO(sobj.st_mode))
    {
        printf("Pipe File\n");
    }
    else if (S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }


    return 0;
}