#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int iCounter = 0;
pthread_mutex_t lock;

void *ThreadProc(void*ptr)
{
    pthread_mutex_lock(&lock);
    int iCnt = 0;
    iCounter++;
    printf("Thread1 executed with counter :%d\n",iCounter);
    for(iCnt=0;iCnt < 0xFFFFFFFF;iCnt++);
    printf("Counter vallue after execution :%d\n",iCounter);
    pthread_exit(NULL);
}

int main()
{
    int ret = 0;
    pthread_t TID1,TID2;
    
    pthread_mutex_init(&lock,NULL);
    ret = pthread_create(&TID1,NULL,ThreadProc,NULL);
    if(ret!=0)
    {
        printf("Unable to create the thread..\n");
        return -1;
    }
    
    ret  = pthread_create(&TID2,NULL,ThreadProc,NULL);
    if(ret!=0)
    {
        printf("Unable to create thread...\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_mutex_destroy(&lock,NULL);
    return 0;
}