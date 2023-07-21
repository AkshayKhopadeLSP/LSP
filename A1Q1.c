//Write a program which accept file name from the user and open that.
#include<stdio.h>
#include<fcntl.h>

int main(int argc ,char *argv[])
{
    int fd = 0;
    char Fname[20];

    printf("Enter the Name of file :");
    scanf("%s",Fname);

    fd = open(Fname,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file : ");
        return -1;
    }
    else
    {
        printf("File is oopened successfully");
    }
    close(fd);
    return 0;
}
