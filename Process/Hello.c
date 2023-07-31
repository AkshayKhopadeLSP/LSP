#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
    int fd = 0;
    int Ret = 0;
    int iCnt = 0;
    char Buffer[1024];
    int iCount = 0;

    fd = open("Hello.txt",O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    while((Ret = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(iCnt=0; iCnt < Ret; iCnt++)
        {
            if((Buffer[iCnt] >= 'A')&&(Buffer[iCnt] <= 'Z'))
            {
                iCount = iCount + 1;
            }
        }
    }
    printf("Number of Captial Letters in Hello.txt are : %d\n",iCount);
    return 0;
}