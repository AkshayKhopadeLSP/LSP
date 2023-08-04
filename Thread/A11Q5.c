#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void*ptr)
{
    int fd = 0;
    int ret = 0;
    char Buffer[1024];

    fd = open("Demo.txt",O_RDONLY);
    while((ret = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        printf("%s\n",Buffer);
    }
    pthread_exit(NULL);
    
}
void * ThreadProc2(void*ptr)
{
    int fd = 0;
    int ret = 0;
    char Buffer[1024];

    fd = open("Hello.txt",O_RDONLY);
    while((ret = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        printf("%s\n",Buffer);
    }
    pthread_exit(NULL);
    
}
int main()
{
    int ret1 = 0;
    int ret2 = 0;
    pthread_t TID1;
    pthread_t TID2;

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    pthread_join(TID1,NULL);

    ret2 = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    pthread_join(TID2,NULL);

    pthread_exit(NULL);
    return 0;
}