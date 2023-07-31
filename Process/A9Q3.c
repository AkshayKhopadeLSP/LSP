#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret = 0;

    Ret = getpriority(PRIO_PROCESS,0);
    printf("Priority process is %d\n",Ret);
    return 0;
}    