//Write a program which accept file name and offset from user and remove all the data from that offset..
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
    int fd =0;
    int offset = 0;
    char FileName[20];
    

    printf("Enter the filename :");
    scanf("%s",FileName);

    printf("Enter the OFFSET :");
    scanf("%d",&offset);

    fd = open(FileName,O_RDWR);
    if(fd==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    //lseek(fd,offset,SEEK_SET);
    truncate(FileName,offset);
    
    return 0;
}