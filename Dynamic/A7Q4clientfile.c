#include<stdio.h>
#include<dlfcn.h>

int main(int argc, char*argv[])
{
    void *ptr = NULL;
    void(*fptr)(int);
    int iNo = 0;

    printf("Ente the Number :");
    scanf("%d",&iNo);

    ptr = dlopen("./libOuter.so",RTLD_LAZY);
    if(ptr==NULL)
    {
        fprintf("Unable to load the library %s",dlerror());
        return -1;
    }

    fptr = dlsym(ptr,"InnerCall");
    if(fptr==NULL)
    {
        printf("Error to the function\n");
        return -1;
    }
    fptr(iNo);
    return 0;
}