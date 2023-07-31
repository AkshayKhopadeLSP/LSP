#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
    int Ret = 0;
    int cpid = 0;
    int Exit_Status = 0;

    Ret = fork();
    if(Ret == 0)
    {
        printf("Child Process and PID is %d\n",getpid());
    }
    else
    {
        printf("Parent Process And PID is : %d\n",getpid());
        cpid = wait(&Exit_Status);
        printf("Child Process having PID : %d is terminated having exit status as %d\n",Ret,Exit_Status);
    }
    return 0;
}