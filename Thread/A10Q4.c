#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
    int ivalue = (int)ptr;
    printf("Value from main is : %d\n",ivalue++);
    pthread_exit(ivalue);
}
int main()
{
    int Ret = 0;
    pthread_t TID;
    int iNo = 12;
    int threadValue = 0;

    Ret = pthread_create(&TID,NULL,ThreadProc,(int*)iNo);
    pthread_join(TID,&threadValue);
    printf("Value from thread is : %d\n",threadValue);
    pthread_exit(NULL);
    return 0;
}