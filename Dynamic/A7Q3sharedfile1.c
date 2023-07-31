#include<stdio.h>
#include<stdbool.h>
#include"A7Q3Headerfile.h"

void CheckPrime(int iNo)
{
    bool bRet = true;
    int iCnt = 0;
    
    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            bRet = false;
            break;
        }
    }
    if(bRet==true)
    {
        printf("number is Prime Number\n");
    }
    else
    {
        printf("Number is not Prime\n");
    }
}


