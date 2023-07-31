#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int iNo1, iNo2 = 0;
    void *ptr = NULL;
    int(*fptr)(int,int);
    int Ret = 0;
    int choice = 0;
    char functname[20];

    printf("Enter the Numbe 1 :");
    scanf("%d",&iNo1);
    printf("Enter the number 2 : ");
    scanf("%d",&iNo2);

    printf("-------------------------------------------------------------------------\n");
    printf("\nPlease Enter the choice : \n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    scanf("%s",functname);
    printf("-------------------------------------------------------------------------\n");

    ptr = dlopen("./libQ1.so",RTLD_LAZY);
    if(ptr==NULL)
    {
        fprintf("Unable to load library %s\n",dlerror());
        return -1;
    }

    if(strcmp(functname,"Addition")==0)
    {
        fptr = dlsym(ptr,"Addition");
    }
    else if(strcmp(functname,"Subtraction")==0)
    {
        fptr = dlsym(ptr,"Subtraction");
    }
    else if(strcmp(functname,"Multiplication")==0)
    {
        fptr = dlsym(ptr,"Multiplication");
    }
    else if(strcmp(functname,"Division")==0)
    {
        fptr = dlsym(ptr,"Division");
    }
    else if(fptr == NULL)
    {
        printf("Unable to laod the address of functon");
        return -1;
    }
    
    Ret = fptr(iNo1,iNo2);
    printf("Result is  : %d\n",Ret);

    return 0;
}