//Write a program which accepts two file names from user check whether contents of that two files are equal...
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc ,char *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    struct stat sobj1;
    struct stat sobj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int Ret = 0;

    if(argc !=3)
    {
        printf("Insufficient Arguements\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);

    if((sobj1.st_size)!=(sobj2.st_size))
    {
        printf("File has different sizes,therefore they are not identical\n");
        return -1;
    }
    while((Ret= read(fd1,Buffer1,sizeof(Buffer1)))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2)!=0)
        {
            break;
        }
    }
    if(Ret==0)
    {
        printf("Files are identical \n");
    }
    else
    {
        printf("Files are different\n")
    }
    close(fd1);
    close(fd2);
    return 0;
}