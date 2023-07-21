//Write program which accept filename and position from user and read 20 bytes from their..
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define SIZE 20
int main(int argc,char *argv[])
{
    int fd = 0;
    char Buffer[SIZE];
    char name[30];
    int position = 0;
    int Ret1 = 0;
    int Ret = 0;

    printf("Enter the filename :");
    scanf("%s",name);
    printf("Enter the postion byte to read the data :");
    scanf("%d",&position);

    fd = open(name,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file :\n");
        return -1;
    }
     Ret1 = lseek(fd,position,0);
     if(Ret1 == -1)
     {
        printf("Fail\n");
        return -1;
     }

     Ret = read(fd,Buffer,SIZE);
     //printf("%s/n",Buffer);
     close(fd);
    return 0;
}