/*
2) Open File in Given Mode
• Accept file name and mode (R, W, RW, A) from user.
• Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
• Open file accordingly and display fd.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd = 0;

    char str[20];
    char mode[10];

    memset(str,'\0',sizeof(str));

    printf("Enter the name of file that you want to open : ");
    scanf("%s",str);

    printf("Enter the mode of file in which you want to open (R,W,RW,A): ");
    scanf("%s",mode);

    if(strcmp(mode,"R") == 0)
    {
        fd = open(str,O_RDONLY);
    }
    else if (strcmp(mode,"W") == 0)
    {
        fd = open(str,O_WRONLY | O_CREAT);
    }
    else if (strcmp(mode,"RW") == 0)
    {
        fd = open(str,O_RDWR | O_CREAT | O_TRUNC);
    }
    else if (strcmp(mode,"A") == 0)
    {
        fd = open(str,O_APPEND | O_CREAT);
    }   
    else
    {
        printf("Invalid mode\n");
        return -1;
    }
    
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