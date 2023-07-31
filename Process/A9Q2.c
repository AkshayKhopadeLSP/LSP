#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int Ret1 = 0;
    int Ret2 = 0;
    int Exit_Status1 = 0;
    int Exit_Status2 = 0;

    Ret1 = fork();
    if(Ret1==0)
    {
        execl("./Demo","NULL","NULL");
    }

    wait(&Exit_Status1);

    Ret1 = fork();
    if(Ret1==0)
    {
        execl("./Hello","NULL","NULL");
    }

    wait(&Exit_Status2);
    return 0;
}