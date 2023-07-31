#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    int RetP1 = 0;
    int RetP2 =0;
    int RetP3 = 0;
    int cpid = 0;
    int status1,status2,status3 = 0;
    
    RetP1 = fork();
    if(RetP1 == 0)
    {
        execl("./Process1","NULL","NULL");
    }

    wait(&status1);

    RetP2 = fork();
    if(RetP2==0)
    {
        execl("./Process2","NULL","NULL");
    }

    wait(&status2);

    RetP3 = fork();
    if(RetP3==0)
    {
        execl("./Process3","NULL","NULL");
    }
    
    wait(&status3);
    
    return 0;
}