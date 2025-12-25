/*
1) Open File
• Accept file name from user and open it using open().
• Print: success message + returned file descriptor.
• Handle errors using perror().

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    int fd = 0;
    char str[20];

    memset(str,'\0',sizeof(str));

    printf("Enter the name of file that you want to open : ");
    scanf("%s",str);

    fd = open(str,O_RDONLY);

    if (fd == -1)
    {
        perror("Unable to open file ");
    }
    else
    {
        printf("File successfully opened with fd : %d\n",fd);
    }
    
    close(fd);
    
    return 0;
}
