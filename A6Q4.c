//write program which accept directory name from user and delete all such file those size is greater than 100 bytes.
#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>



int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char DirName[20];
    char name[20];
    struct stat sobj;
   

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
        stat(name,&sobj);
        if(sobj.st_size >100)
        {
            remove(name);
            printf("File Deleted successfully\n");
        }
    }
    return 0;
}