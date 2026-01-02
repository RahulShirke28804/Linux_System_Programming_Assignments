/*
2) File Copy with Offset
Problem Statement:
Copy a file starting from a given byte offset of the source file.
Input:
source_file destination_file offset
Output:
Partial file copied starting from offset.
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include <stdlib.h>


int main(int args, char *argv[])
{
    int source_fd = 0, dest_fd = 0;
    char Buffer[4096];
    int bytesread = 0, byteswritten = 0;
    off_t offset;

    offset = (off_t)strtoll(argv[3], NULL, 10);

    memset(Buffer,'\0',sizeof(Buffer));

    source_fd = open(argv[1],O_RDONLY);
    if(source_fd == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }
    
    dest_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(dest_fd == -1)
    {
        printf("Unable to open Destination file\n");
        close(source_fd);
        return -1;
    }

    lseek(source_fd,offset,SEEK_SET);

    while ((bytesread = read(source_fd,Buffer,sizeof(Buffer))) > 0)
    {
        byteswritten = write(dest_fd,Buffer,bytesread);
        if(bytesread != byteswritten)
        {
            printf("Error in writing\n");
            close(source_fd);
            close(dest_fd);
            return -1;
        }   
    }
    
    if(bytesread == -1)
    {
        printf("Error in reading file\n");
    }
    close(source_fd);
    close(dest_fd);

    return 0;
}
