#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
    int Ret = 0;

    Ret = nice(-5);
    printf("Changed Priority of process is %d\n",Ret);
    
    return 0;
} 