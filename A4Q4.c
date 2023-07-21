/*Write a program which accepts the directory name from the user and
copy first 10 bytes from all regular files into newly created file as Demo.txt*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    DIR * dp = NULL;
    struct dirent * entry = NULL;
    int fd = 0;
    int Ret = 0;
    int Size = 10;
    char Buffer[Size];
    char DirName[30];
    char name[30];
    char path[30];
    int fd2 = 0;

    printf("Ente the Directory name : ");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to directory\n");
        return -1;
    }
    
    sprintf(path,"%s/%s",DirName,"Demo.txt");    
    fd = creat(path,0777);
    if(fd ==-1)
    {
        printf("Unable to create the file Demo.txt\n");
        return -1;
    }

    while ((entry = readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        if(entry->d_type == DT_REG)
        {
            //printf("%s\n",name);
            fd2 = open(name,O_RDONLY);
            Ret = read(fd2,Buffer,Size);
            printf("%s",Buffer);
            write(fd,Buffer,Size);   
        }
        
    }
    close(fd);
    close(fd2);
    closedir(DirName);
    
   
    return 0;
}