#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
//#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    int Ret = 0;
    char Buffer[1024];   
    
    if(argc != 3)
    {
        printf("Insufficient Arugements\n");
        return -1;
    }
    fd = open(argv[1],O_RDONLY);
    Ret = read(fd,Buffer,sizeof(atoi(argv[2])));

    //printf("Size of Buffer :%d\n",sizeof(Buffer));
    printf("%s",Buffer);
    close(fd);
    return 0;
}