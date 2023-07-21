//gcc A4Q1.c -o Myexe
//./Myexe <I Input.txt > Output.txt

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[1024];
    char name[20];
    int Ret = 0;

    scanf("%s",name);
    printf("%s",name);
    fd = open(name,O_RDWR);
    if(fd==-1)
    {
        printf("Unable to open the file : ");
        return -1;
    }

    while(Ret=read(fd,Buffer,sizeof(Buffer))!=0)
    {
        printf("%s",Buffer);
    }
    close(fd);

    return 0;
}