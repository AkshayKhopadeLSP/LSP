#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>
#include"A7Q2headerfile.h"

bool CompareFile(char Arr[],char Brr[])
{
    bool bRet = false;
    int fd1 = 0;
    int fd2 = 0;
    int Ret = 0;
    char Buffer1[1024];
    char Buffer2[1024];

    fd1 = open(Arr,O_RDWR);
    if(fd1==0)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    fd2 = open(Brr,O_RDWR);
    if(fd2==0)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    while(Ret = read(fd1,Buffer1,sizeof(Buffer1))!=0)
    {
        Ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,Ret)!=0)
        {
            bRet = false;
            break;
        }
    }
    if(Ret==0)
    {
        bRet = true;
    }
    
    return bRet;
}

