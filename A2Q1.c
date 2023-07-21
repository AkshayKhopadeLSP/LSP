#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
    int fd =0;
    char Buffer[1024];
    int Ret = 0;

    if(argc != 2)
    {
        printf("Insufficient arguements\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    while(Ret =read(fd,Buffer,sizeof(Buffer))!=0)
    {
        printf("Data from the file is : \n................................................................");
        printf("\n%s\n",Buffer);
    }
    close(fd);
    return 0;
}