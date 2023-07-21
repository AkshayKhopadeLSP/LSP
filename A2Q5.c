//Write a program which accepts the directory name from the user and print the file name having the lagerst size..
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char*argv[])
{
    DIR * dp = NULL;
    struct dirent *entry =NULL;
    char Dirname[20];
    char name[20];
    int iMax = 0;
    struct stat sobj;
    char filename[30];

    printf("Enter the directory name : ");
    scanf("%s",Dirname);

    dp = opendir(Dirname);
    if(dp==NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",Dirname,entry->d_name);
        stat(name,&sobj);
        if(iMax < sobj.st_size)
        {
            iMax = sobj.st_size;
            strcpy(filename,name);
        }
    }

    printf("File having largest size is :%s and size is %d",filename,iMax);
    closedir(dp);

    return 0;
}