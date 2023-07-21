#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char*argv[])
{

    int fd = 0;
    int Mode = 0; 

    if(argc !=3)
    {
        printf("Insufficient Arugements\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        Mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"Create")==0)
    {
        Mode =O_CREAT;
    }
    else 
    {
        printf("Entered Mode is Inappropriate\n");
        return -1;
    }   

    fd = open(argv[1],Mode);
    if(fd ==-1)
    {
        printf("Cannot Open the File\n");
        return -1;
    }
    else
    {
        if(Mode == 0)
        {
            printf("File is Openend in Read Mode\n");
        }
        else if(Mode == 1)
        {
            printf("File is opened in Write Mode\n");
        }       
    }
    close(fd);
    return 0;
}