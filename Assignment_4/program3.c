/*
3) File Copy Using pread & pwrite
Problem Statement:
Copy a file using pread() and pwrite() without changing the file offset.
Input:
Source and destination file names.
Output:
Copied file identical to source.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int args, char *argv[])
{
    int src_fd = 0;
    int dest_fd = 0;
    char Buffer[4096];
    int bytesread = 0, byteswrite = 0;
    int offset = 0;

    memset(Buffer,'\0',sizeof(Buffer));

    src_fd = open(argv[1],O_RDONLY);
    if(src_fd == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    dest_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(dest_fd == -1)
    {
        printf("Unable to open Destination file\n");
        close(src_fd);
        return -1;
    }

    while((bytesread = pread(src_fd,Buffer,sizeof(Buffer),offset)) > 0)
    {
        byteswrite = pwrite(dest_fd,Buffer,bytesread,offset);
        if(byteswrite != bytesread)
        {
            close(src_fd);
            close(dest_fd);
            return -1;
        }
        offset = offset + bytesread;
    }

    if(bytesread == -1)
    {
        printf("Error in reading file\n");
    }
    close(src_fd);
    close(dest_fd);

    return 0;
}
