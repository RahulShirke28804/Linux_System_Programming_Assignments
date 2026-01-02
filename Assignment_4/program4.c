/*
4) File Merge Utility
Problem Statement:
Merge multiple input files into a single output file.
Input:
output_file file1 file2 file3 ...
Output:
Combined file content in order.
*/


#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int args, char* argv[])
{   
    int src_fd1 = 0, dest_fd = 0, iCnt = 0;
    char buffer[4096];
    int readbytes = 0, writebytes = 0;

    memset(buffer,'\0',sizeof(buffer));

    dest_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(dest_fd == -1)
    {
        printf("Unable to open output file");
        return -1;
    }

    for(iCnt = 2; iCnt < args; iCnt++)
    {
        src_fd1 = open(argv[iCnt],O_RDONLY);
        if(src_fd1 == -1)
        {
            printf("Source file opening error\n");
            return -1;
        }    

        while ((readbytes = read(src_fd1,buffer,sizeof(buffer))) > 0)
        {
            writebytes = write(dest_fd,buffer,readbytes);
            if(readbytes != writebytes)
            {
                printf("Error in writing data\n");
                close(src_fd1);
                close(dest_fd);
                return -1;
            }
        }
        
        if (readbytes == -1)
        {
            printf("error in reading source file\n");
        }

        close(src_fd1);
    }
    
    close(dest_fd);
    
    return 0;
}
