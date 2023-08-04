#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadProc(void*ptr)
{
    int tid= pthread_self();
    printf("Inside thread\n");
    printf("Threa Id is %d\n",tid);

}
int main()
{
    int ret = 0;
    pthread_t TID;
    long unsigned int ThreadId= 0;

    ret = pthread_create(&TID,NULL,ThreadProc,NULL);
    pthread_join(TID,NULL);
    pthread_exit(NULL);
    return 0;
}