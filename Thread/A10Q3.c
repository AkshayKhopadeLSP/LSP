#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void * ThreadProc(void*ptr)
{
    int iValue = (int)ptr;
    printf("The Value is  : %d\n",(int)iValue);
}
int main(int argc,char*argv[])
{
    int Ret = 0;
    pthread_t TID;
    int iNo = 11;
    
    Ret = pthread_create(&TID,NULL,ThreadProc,(int*)iNo);
    pthread_join(TID,NULL);
    pthread_exit(NULL);

    return 0;
}