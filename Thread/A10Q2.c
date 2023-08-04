#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * Thread1(void*ptr)
{
    int iCnt =0;
    printf("1 to 500\n");
    for(iCnt=1;iCnt<=500;iCnt++)
    {
        printf("%d\n",iCnt);
    }

    pthread_exit(NULL);
}
void * Thread2(void*ptr)
{
    int iCnt = 0;
    for(iCnt=500;iCnt>=0;iCnt--)
    {
        printf("%d\n",iCnt);
    }
    pthread_exit(NULL);
}

int main(int argc,char*argv[])
{
    int Ret1 = 0;
    int Ret2 = 0;
    pthread_t TID1;
    pthread_t TID2;

    Ret1 = pthread_create(&TID1,NULL,Thread1,NULL);
    if(Ret1!=0)
    {
        printf("Unable to create Thread\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    
    Ret2 = pthread_create(&TID2,NULL,Thread2,NULL);
    if(Ret2!=0)
    {
        printf("Unable to create thread2\n");
        return -1;
    }
    
    pthread_join(TID2,NULL);
    printf("End of Main Thread\n");
    pthread_exit(NULL);

    return 0;
}