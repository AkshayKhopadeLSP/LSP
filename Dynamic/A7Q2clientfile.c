#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    char Arr[30];
    char Brr[30];
    bool Ret = false;
    void *ptr = NULL;
    bool(*fptr)(char[],char[]);


    printf("Enter the File name :");
    scanf("%s",Arr);
    printf("Enter the File name :");
    scanf("%s",Brr);
    
    ptr = dlopen("./libQ2.so",RTLD_LAZY);
    if(ptr==NULL)
    {
        fprintf("Unable to open directory %s :",dlerror());
        return -1;
    }

    fptr = dlsym(ptr,"CompareFile");
    if(fptr==NULL)
    {
        printf("Error to call the function\n");
        return -1;
    }
    
    Ret = fptr(Arr,Brr);
    if(Ret==true)
    {
        printf("Same\n");
    }
    else{
        printf("Different\n");
    }
    return 0;
}