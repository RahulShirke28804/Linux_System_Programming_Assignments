/*
5) Reverse File Content
Problem Statement:
Display the contents of a file in reverse order.
Input:
File name.
Output:
File content printed in reverse.
*/


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int args, char *argv[])
{
    int src_fd = 0, dest_fd = 0;
    int readbytes = 0, writebytes = 0;
    off_t size = 0;
    off_t iCnt = 0;
    off_t seek = 0;
    char ch;

    src_fd = open(argv[1],O_RDONLY);
    if (src_fd == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }
    
    dest_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (dest_fd == -1)
    {
        printf("Unable to open Destination file\n");
        close(src_fd);
        return -1;
    }

    size = lseek(src_fd, 0, SEEK_END);
    if(size == -1)
    {
        perror("lseek failed");
        close(src_fd);
        close(dest_fd);
        return -1;
    }
    
    
    for(iCnt = size - 1; iCnt >= 0; iCnt--)
    {
        seek = lseek(src_fd, iCnt, SEEK_SET);
        if (seek == -1)
        {
            printf("lseek failed");
            break;
        }

        readbytes = read(src_fd, &ch, 1);
        if (readbytes == -1)
        {
            printf("read failed");
            break;
        }
        

        writebytes = write(dest_fd, &ch, 1);
        if (writebytes == -1)
        {
            printf("write failed");
            break;
        }
    }
    

    close(src_fd);
    close(dest_fd);



    return 0;
}
