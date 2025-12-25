/*
1) Read Whole File
• Accept file name and print full content on console.
• Use a buffer loop (read() until 0).
• Show total bytes read.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;
    char str[20];
    
    memset(str,'\0',sizeof(str));
    
    printf("Enter the name of file that you want to read : ");
    scanf("%s",str);
    
    struct stat sobj;
    stat(str,&sobj);
    
    char buffer[sobj.st_blksize];

    memset(buffer,'\0',sizeof(buffer));

    fd = open(str,O_RDONLY);

    read(fd,buffer,sobj.st_size);

    printf("%s",buffer);

    close(fd);

    return 0;
}
