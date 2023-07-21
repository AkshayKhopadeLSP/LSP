//Write a program which accept two file names from user and copy the contents of existing file into newly created file..
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int fdSource =0;
    int fdCreate = 0;
    char Buffer[1024];
    int Ret = 0;
    int result = 0;

    if(argc != 3)
    {
        printf("Insufficient Aruge,ents\n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource ==-1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    fdCreate = creat(argv[2],O_RDWR);
    if(fdSource==-1)
    {
        printf("Unable to create the file\n");
        return -1;
    }

    while((Ret  = read(fdSource,Buffer,sizeof(Buffer)))!=0)
    {
        result = write(fdCreate,Buffer,Ret);
    }
    if(result == -1)
    {
        printf("Unsuccesssfull\n");
    }
    else
    {
        printf("Successfull to write the data in file\n");
    }
    return 0;
}