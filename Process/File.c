#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[50];
    int Ret = 0;
    struct dirent *entry = NULL;
    int Exit_Status = 0;
    DIR *dp = NULL;
    

    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create the file demo\n");
        return -1;
    }

    dp = opendir("/home/pawar/Desktop");

    while((entry = readdir(dp))!=NULL)
    {
        strcpy(Buffer,entry->d_name);
        Ret = write(fd,Buffer,sizeof(Buffer));
    }
    if(Ret > 0)
    {
        printf("File Names wriiten successfully\n");
    }
    else if(Ret==0)
    {
        printf("Eror ouccured in opening the file\n");
    }
    return 0;
}