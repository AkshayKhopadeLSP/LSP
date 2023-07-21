#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char*argv[])
{
    int Check =-1;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Insufficient Arguements\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0)
    {
        Mode = R_OK;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        Mode = W_OK;
    }
    else if(strcmp(argv[2],"Execute")==0)
    {
        Mode = X_OK;
    }
    else
    {
        printf("Entered Not appropriate\n");
    }
    
    Check = access(argv[1],Mode);       
    //access function returns 0 if successfull..... 
    //access function returns -1 if failure......
    
    if(Check ==0)
    {
     printf("File can be access is %s Mode\n",argv[2]);
    } 
    else 
    {
     printf("File cannot open in %s Mode\n",argv[1]);
    }

    return 0;
}