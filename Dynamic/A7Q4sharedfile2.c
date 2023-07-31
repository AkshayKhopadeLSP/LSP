#include<stdio.h>
#include<dlfcn.h>
#include"A7Q4Headerfile.h"

void InnerCall(int iNo)
{
    void *ptr = NULL;
    int(*fptr)(int);
    int iRet = 0;

    ptr = dlopen("./libInner.so",RTLD_LAZY);
    if(ptr==NULL)
    {
        fprintf("Unable to load the library %s\n",dlerror());
        return -1;
    }

    fptr = dlsym(ptr,"Factorial");
    if(fptr==NULL)
    {
        printf("Error to load the library\n");
        return -1;
    }

    iRet = fptr(iNo);
    printf("Factorial is %d",iRet);
}