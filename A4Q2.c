//Write a program which accept directory name from user and create that name of directory...
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int dd =0;
    
    if (argc != 2)
    {
        printf("Insufficient arguements\n");
        return -1;
    }

    dd = mkdir(argv[1],0777);
    if(dd==-1)
    {
        printf("Unable to create the directory\n");
        return -1;
    }
    else
    {
        printf("Successfully created directory\n");
    }
    
    return 0;
}