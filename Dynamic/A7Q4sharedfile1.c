#include<stdio.h>
#include"A7Q4Headerfile.h"

int Factorial(int iNo)
{
    unsigned long int iFact = 1;
    int iCnt = 0;

    for(iCnt = 1;iCnt <= iNo; iCnt++)
    {
        iFact = iFact*iCnt;
    }
    return iFact;
}