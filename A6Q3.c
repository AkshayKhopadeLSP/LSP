//Write a program which accept directory name and file nmae from user and create that file in that directory.
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char*argv[])
{
    int fd = 0;
    DIR * dp = NULL;
    struct dirent *entry = NULL;
    char DirName[20];
    char FileName[20];
    char Name[20];

    printf("Enter the Directory name : ");
    scanf("%s",DirName);

    printf("Enter the File name : ");
    scanf("%s",FileName);

    dp = opendir(DirName);
    if(dp==NULL)
    {
        printf("Unable to the Directory\n");
        return - 1;
    }

    sprintf(Name,"%s/%s",DirName,FileName);
    fd = creat(Name,0777);
    if(fd==-1)
    {
        printf("Unable to create the file in directory\n");
        return -1;
    }

    return 0;
}