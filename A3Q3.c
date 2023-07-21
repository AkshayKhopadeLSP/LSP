//Write a program which accepts two directory names from user and move all the files from source directory to destination directory
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char*argv[])
{
    DIR * dp= NULL;
    struct dirent *entry = NULL;
    char sourcename[20];
    char destiname[20];

    if(argc != 3)
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
    //mkdir(argv[2]);
    while((entry = readdir(dp))!=NULL)
    {
        sprintf(sourcename,"%s/%s",argv[1],entry->d_name);
        //printf("%s",sourcename);
        sprintf(destiname,"%s/%s",argv[2],entry->d_name);
        rename(sourcename,destiname);
        
    }
    return 0;
}