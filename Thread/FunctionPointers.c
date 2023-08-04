//Array of function pointers to run the 10 threads at a time.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * ThreadPoc1(void*ptr)
{
    printf("Ganesha...\n");
    pthread_exit(NULL);
}
void * ThreadPoc2(void*ptr)
{
    printf("Gajanan...\n");
    pthread_exit(NULL);
}
void * ThreadPoc3(void*ptr)
{
    printf("Vakratund...\n");
    pthread_exit(NULL);
}
void * ThreadPoc4(void*ptr)
{
    printf("Vinayak...\n");
    pthread_exit(NULL);
}
void * ThreadPoc5(void*ptr)
{
    printf("Lambodar...\n");
    pthread_exit(NULL);
}
void * ThreadPoc6(void*ptr)
{
    printf("Ganapati...\n");
    pthread_exit(NULL);
}
void * ThreadPoc7(void*ptr)
{
    printf("Ekdant...\n");
    pthread_exit(NULL);
}
void * ThreadPoc8(void*ptr)
{
    printf("Mangalmurti...\n");
    pthread_exit(NULL);
}
void * ThreadPoc9(void*ptr)
{
    printf("Vighnesh...\n");
    pthread_exit(NULL);
}
void * ThreadPoc10(void*ptr)
{
    printf("Anant...\n");
    pthread_exit(NULL);
}

int main(int argc,char*argv[])
{
    pthread_t TID[10];
    int ret  = 0;
    void (*ptrr[])(void*) = { ThreadPoc1,ThreadPoc2,ThreadPoc3,ThreadPoc4,ThreadPoc5,ThreadPoc6,ThreadPoc7,ThreadPoc8,ThreadPoc9,ThreadPoc10};
    int iCnt = 0;
    for(iCnt= 0;iCnt<10;iCnt++)
    {
        ret = pthread_create(&TID[iCnt],NULL,ptrr[iCnt],NULL);
    }

    for(iCnt =0;iCnt<10;iCnt++)
    {
        pthread_join(TID[iCnt],NULL);
    }
    pthread_exit(NULL);
    return 0;
}