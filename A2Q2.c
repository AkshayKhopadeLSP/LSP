#include<stdio.h>
#include<fcntl.h>
#include<string.h>



int main(int argc,char*argv[])
{
    int fd =0;
    char Buffer[1024];
    int Ret = 0;
    struct stat sobj;
    int Ret2 = 0;

    if(argc != 2)
    {
        printf("Insufficient arguements\n");
        return -1;
    }

    fd = open(argv[1],O_WRONLY|O_APPEND);
    if(fd == -1)
    {
        printf("Unable to Open the file\n");
        return -1;
    }

    printf("Enter the string to write in file :\n");
    scanf("%[^'\n']s",Buffer);
    Ret  = strlen(Buffer);
   //printf("%d",Ret);

    Ret2 = write(fd,Buffer,Ret);
    if(Ret2 ==-1)
    {
        printf("unable to write in file \n");
        return -1;
    }
    else
    {
        printf("Successfully Writtern into the file\n");
    }
    close(fd);
    return 0;
}