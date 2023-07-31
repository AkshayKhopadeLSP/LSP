#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc, char*argv[])
{
    int Ret = 0;
    int Exit_Status = 0;

    Ret = fork();
    if(Ret==0)
    {
        execl("./File","NULL","NULL");
    }
    wait(&Exit_Status);
    return 0;
}