#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int Counter = 0;

void *ThreadProc(void*ptr)
{
    int i = 0;
    Counter++;
    printf("Thread executed with counter : %d.\n",Counter);
    for(i = 0; i < 0xFFFFFFFF; i++);
    printf("Thread completed with counter : %d.\n",Counter);
    pthread_exit(NULL);
}
int main()
{
    pthread_t TID1,TID2;
    int ret = 0;
    
    ret = pthread_create(&TID1,NULL,ThreadProc,NULL);
    
    if(ret != 0)
    {
        printf("Unablr to create thread.\n");
        return -1;
    }

    pthread_join(TID1,NULL);

    ret = pthread_create(&TID2,NULL,ThreadProc,NULL);
    
    if(ret != 0)
    {
        printf("Unablr to create thread.\n");
        return -1;
    }
    
    
  
    pthread_join(TID2,NULL);
             
    printf("End of main thread.\n");
    
    pthread_exit(NULL);
    return 0;
}