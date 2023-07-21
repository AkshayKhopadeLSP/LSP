//Write a program which accepts directory name from user and print all the file from the directory..
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR * dp =NULL;
    struct dirent * entry = NULL;
    char DirName[20];
    char name[20];

    printf("Enter the directory name :");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp==NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        printf("%s\n",name);
    }
    closedir(dp);
    return 0;
}