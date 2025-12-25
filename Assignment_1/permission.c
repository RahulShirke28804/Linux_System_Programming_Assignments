/*
3) Check File Access Permission
• Accept file name and mode (read/write/execute).
• Use access() to check permission for current process.
• Print “Accessible / Not accessible” with reason.
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>

int main()
{
    int fd = 0;

    char str[20];
    char mode[10];

    memset(str,'\0',sizeof(str));
    memset(mode,'\0',sizeof(mode));

    printf("Enter the name of file that you want to open : ");
    scanf("%s",str);

    printf("Enter the mode of file in which you want to open (R,W,E): ");
    scanf("%s",mode);

    if(strcmp(mode,"R") == 0)
    {
        fd = open(str,O_RDONLY, 444);
    }
    else if (strcmp(mode,"W") == 0)
    {
        fd = open(str,O_WRONLY | O_CREAT, 0222);
    }
    else if (strcmp(mode,"E") == 0)
    {
        fd = open(str,O_RDONLY, 0111  );
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
        
        if(access(str, R_OK) == 0)
            printf("Read\n");

        if(access(str, W_OK) == 0)
            printf("Write\n");

        if(access(str, X_OK) == 0)
            printf("Execute\n");

        if(access(str, R_OK|W_OK|X_OK) == -1)
            printf("No permissions available to this user\n");
    }

    close(fd);

    return 0;
}