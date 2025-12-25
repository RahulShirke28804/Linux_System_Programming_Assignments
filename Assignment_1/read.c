/*
5) Read N Bytes From File
• Accept file name and number of bytes N.
• Read exactly N bytes using read() and print on console.
• If file contains less than N, print only available bytes
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int fd = 0;
    int N = 0;
    char str[20];
    char buffer[4096];

    memset(str,'\0',sizeof(str));
    memset(buffer,'\0',sizeof(buffer));

    printf("Enter the name of file that you want to read : ");
    scanf("%s",str);

    printf("Enter nunmber of bytes that you want to read : ");
    scanf("%d",&N);
    
    fd = open(str,O_RDONLY);

    read(fd,buffer,N);

    printf("%s",buffer);

    
    return 0;
}
