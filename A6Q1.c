//Write a program while accept the file name which contains data of all files and print file names those size is less than 10 bytes.
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
    int size;
};

int main(int argc, char*argv[])
{
    int Ret  = 0;
    int fd = 0;
    char SourceFile[20];
    struct FileName fobj;


    printf("Enter the Filename which contains file information  :");
    scanf("%s",SourceFile);

    fd  = open(SourceFile,O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    
    
    while(Ret = read(fd,&fobj,sizeof(fobj))!=0)
    {
        if(fobj.size > 10)
        {
            printf("%s : %d\n",fobj.Name,fobj.size);
        }        
    }
    close(fd);
    return 0;
}