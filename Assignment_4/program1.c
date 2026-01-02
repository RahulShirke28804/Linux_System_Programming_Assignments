/*
1) File Copy Utility
Problem Statement:
Write a program that copies the contents of one file into another.
Input:
Source file name and destination file name as command-line arguments.
Output:
Destination file containing an exact copy of source file.
• Handle file-not-found and permission errors.
• Destination file should be created if not present.
*/



#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int args, char* argv[])
{   
    int fd1 = 0, fd2 = 0;
    char buffer[4096];
    int readbytes = 0, writebytes = 0;

    memset(buffer,'\0',sizeof(buffer));

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1)
    {
        printf("Source file opening error\n");
        return -1;
    }
    

    fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd2 == -1)
    {
        printf("Destination file opening error\n");
        close(fd1);
        return -1;
    }

    while ((readbytes = read(fd1,buffer,sizeof(buffer))) > 0)
    {
        writebytes = write(fd2,buffer,readbytes);
        if(readbytes != writebytes)
        {
            printf("Error in writing data\n");
            close(fd1);
            close(fd2);
            return -1;
        }
    }
    if (readbytes == -1)
    {
        printf("error in reading source file\n");
    }

    close(fd1);
    close(fd2);
    
    return 0;
}
