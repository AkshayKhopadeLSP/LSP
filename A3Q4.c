//Write a program which accepts directory name from user and delete the 0 size file..
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char*argv[])
{
    DIR * dp= NULL;
    struct dirent *entry = NULL;
    char sourcename[20];
    struct stat sobj;
    int iCnt =0;

    if(argc != 2)
    {
        printf("Insufficient Arguements\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to directory\n");
        return -1;
    }
    
    while((entry = readdir(dp))!=NULL)
    {
        sprintf(sourcename,"%s/%s",argv[1],entry->d_name);
        stat(sourcename,&sobj);
        if((sobj.st_size)==0)
        {
            remove(sourcename);
            iCnt++;
        }
    }
    printf("%d File deleted which were having size as zero",iCnt);
    return 0;
}