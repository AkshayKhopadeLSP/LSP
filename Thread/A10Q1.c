#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * Threadproc(void*ptr)
{
    printf("Thread Creation Done Successfully\n");
    pthread_exit(NULL);
}
int main(int argc, char*argv[])
{
    pthread_t TID;
    int Ret = 0;

    Ret = pthread_create(&TID,
                         NULL,
                         Threadproc,
                         NULL
                        );
                        
    if(Ret!=0)
    {
        printf("Unable to create the thread\n");
        return -1;
    }
    printf("Threads TID is :%u\n",TID);
    pthread_join(TID,NULL);
    pthread_exit(NULL);
    return 0;
} 