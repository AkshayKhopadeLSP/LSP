//Write a program which accepts the directory name from user and print all the files name and its type..
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR * dp = NULL;
    struct dirent *entry =NULL;
    char DirName[20];
    char name[20];
    struct stat sobj;

    printf("Enter the Directory name :");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            printf("%s:IS REGULAR FILE\n",name);
        }else if(S_ISDIR(sobj.st_mode))
        {
            printf("%s:IS DIRECTORY FILE\n",name);
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("%s:IS SYMBOLICLINK FILE\n",name);
        }
    }
    closedir(dp);
    return 0;
}