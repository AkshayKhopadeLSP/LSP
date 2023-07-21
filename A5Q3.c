/*Write a program which accept directory name from user and 
write all information of regular files in and read the contents from that file*/
/*
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	off_t st_size;
    */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#pragma pack(1)
struct FileInfo
{

    char FileName[20];
    int size;
};

int main(int argc, char*argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry;
    struct stat sobj;
    struct FileInfo iobj;
    int fd =0;
    int Ret  = 0;
    char Filename[30];
    char name[20];

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    printf("Enter the Filename to Write the informnation files : ");
    scanf("%s",Filename);

    dp = opendir(DirName);
    if(dp==NULL)
    {
        printf("Unable to the directory. \n");
        return -1;
    }
    
    fd = open(Filename,O_RDWR);
    if(fd==-1)
    {
        printf("Unabble to open the file.\n");
        return -1;
    }
   
    while((entry = readdir(dp))!= NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            strcpy(iobj.FileName,entry->d_name);
            iobj.size = sobj.st_size;
            write(fd,&iobj,sizeof(iobj));
            printf("%s :: %d\n",iobj.FileName,iobj.size);
        }
    }
    close(fd);
    closedir(dp);

    return 0;
}
