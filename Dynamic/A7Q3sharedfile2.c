#include<stdio.h>
#include<stdbool.h>
#include"A7Q3Headerfile.h"

void CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;
    bool bRet = false;
    if(iNo < 0)
    {
        iNo = -iNo;
    }

    for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
    {
        if((iNo % iCnt) == 0)
        {
            iSum = iSum + iCnt;
        }
    }
    if(iSum == iNo)
    {
        printf("Number is Perfect\n");
    }
    else
    {
        printf("Nummber is not Not Perfect\n");
    }
}