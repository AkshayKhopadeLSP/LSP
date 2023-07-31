#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
#include<string.h>
#include<stdbool.h>


int main(int argc,char *argv[])
{
    void *ptr1 = NULL;
    void *ptr2 = NULL;
    void(*fptr1)(int);
    void(*fptr2)(int);
    int iNo = 0;
    
    printf("Enter the Number :");
    scanf("%d",&iNo);

    ptr1 = dlopen("./lib1Q3.so",RTLD_LAZY);
    if(ptr1==NULL)
    {
        fprintf("Unable to load the library :%s",dlerror());
        return -1;
    }

    ptr2 = dlopen("./lib2Q3.so",RTLD_LAZY);
    if(ptr2==NULL)
    {
        fprintf("Unable to load the library : %s",dlerror());
        return -1;
    }

    fptr1 = dlsym(ptr1,"CheckPrime");
    if(fptr1==NULL)
    {
        printf("Error to call function\n");
        return -1;
    }

    fptr2 = dlsym(ptr2,"CheckPerfect");
    if(fptr2==NULL)
    {
        printf("Error to call function\n");
        return -1;
    }

     fptr1(iNo);
     fptr2(iNo);

    

    return 0;
}