//Write a program while accept the file name which contains data of all file.we have to create all file again.
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#pragma pack(1)
struct FileName
{
    char Name[20];
};

int main(int argc, char*argv[])
{
    int Ret  = 0;
    int fd = 0;
    char DirName[20];
    char SourceFile[20];
    struct FileName fobj;
    char path[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    printf("Enter the Filename which contains file information  :");
    scanf("%s",SourceFile);

    printf("Enter the directory to create the files again :");
    scanf("%s",DirName);
    fd  = open(SourceFile,O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    
    
    while(Ret = read(fd,&fobj,sizeof(fobj))!=0)
    {
    
        sprintf(path,"%s/%s",DirName,fobj.Name);
        creat(path,0777);
    }
    close(fd);
    return 0;
}