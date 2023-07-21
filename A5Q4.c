/*Write a program whicjh accept the directory name from user and 
all combine contents of file from that directory into one as AllCombine.txt*/
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp  = NULL;
    int fd = 0;
    int fd1 =0;
    char name[20];
    char Buffer[1024];
    char DirName[20];
    struct dirent *entry;
    int Ret= 0;

    printf("Enter the directory name \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp==NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    fd = creat("AllCombine.txt",0777);
    
    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        fd1 = open(name,O_RDWR);
        Ret = read(fd1,Buffer,sizeof(Buffer));
        write(fd,Buffer,Ret);
        
    }
    close(fd);
    closedir(dp);
    return 0;
}