#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int Ret1 = 0;
    int Ret2 = 0;
    int cpidP = 0;
    int cpidC = 0;
    int Exit_StatusP = 0;
    int Exit_StatusC =0;

    Ret1 = fork();
    if(Ret1==0)
    {
        printf("Child Process & PID is %d\n",getpid());
        Ret2 = fork();
        if(Ret2==0)
        {
            printf("Process created by the Child Process & PID is : %d\n",getpid());
        }
        cpidC = wait(&Exit_StatusC);
    }
    else 
    {
        printf("Parent Process is : %d\n",getpid());
        cpidP = wait(&Exit_StatusP);
    }
    return 0;
}