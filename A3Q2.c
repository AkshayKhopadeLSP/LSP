//Write a program which accept the directory name and file name from user and check that file is present in the directory or not.
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<stdbool.h>


int main(int argc, char*argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    bool bRet = false;    

    if(argc != 3)
    {
        printf("Insufficient Arguements\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to directory\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        if(strcmp(argv[2],entry->d_name)==0)
        {
            bRet = true;        
            break;
        }
    }
    if(bRet == false)
    {
        printf("File is not present the directory\n");
    }
    else
    {
        printf("File is present\n");
    }
    return 0;
}