//Write a program which accpets the file namefrom user ,
//which contains the information about employee, we have to read the all informtion...
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

struct Employee
{
    int Eid;
    char Name[30];
    char Department[20];
};

int main(int argc, char*argv[])
{
    int fd = 0;
    char Name[20];
    struct stat sobj;
    struct Employee eobj;
    int Ret = 0;

    printf("Enter the file nmae which contains the Employee information :");
    scanf("%s",Name);

    stat(Name,&sobj);
    if(sobj.st_size <=0)
    {
        printf("File doesnt content any data\n");
        return -1;
    }

    fd =open(Name,O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open the file.\n");
        return -1;
    }

    Ret = read(fd,&eobj,sizeof(eobj));
    printf("Employee nmae :%s\n",eobj.Name);
    printf("Empolyee id : %d\n",eobj.Eid);
    printf("Profile : %s\n",eobj.Department);
    return 0;
}