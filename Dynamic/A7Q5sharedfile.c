#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void FileInfo(char Arr[])
{
    int fd = 0;
    int Inode = 0;
    int iSize = 0;
    struct stat sobj;

    stat(Arr,&sobj);
    Inode = sobj.st_ino;
    iSize = sobj.st_size;

    printf("File Name  is : %s\n",Arr);
    printf("Inode of File is  : %d\n",Inode);
    printf("File Size is : %d\n",iSize);

}
