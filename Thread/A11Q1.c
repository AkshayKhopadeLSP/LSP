#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc1(void*ptr)
{
    printf("Inside Thread 1\n");
    pthread_exit(NULL);
}
void * ThreadProc2(void*ptr)
{
    printf("Inside Thread 2\n");
    pthread_exit(NULL);
}
void * ThreadProc3(void*ptr)
{
    printf("Inside Thread 3\n");
    pthread_exit(NULL);
}
void * ThreadProc4(void*ptr)
{
    printf("Inside Thread 4\n");
    pthread_exit(NULL);
}
int main()
{
    int ret = 0;
    pthread_t TID[3];
    void(*ptr[])(void*) = {ThreadProc1,ThreadProc2,ThreadProc3,ThreadProc4};
    
    
    int iCnt = 0;

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        ret = pthread_create(&TID[iCnt],NULL,ptr[iCnt],NULL);
    }

    for(iCnt =0;iCnt<4;iCnt++)
    {
        pthread_join(TID[iCnt],NULL);
    }
    printf("End of main\n");
    pthread_exit(NULL);
    return 0;
}