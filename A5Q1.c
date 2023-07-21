//Write a program which writes structure in file .Structure should contains the information Student;
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)
struct StudentInfo
{
    int iRollno;
    int Marks;
    float percentage;
    char Name[30];
};

int main(int argc,char*argv[])
{
    int fd = 0;
    int Roll = 0;
    int marks = 0;
    float perc =0.0;
    char Buffer[1024];
    struct StudentInfo sobj;
    char StudName[30];
    int Ret = 0;

    fd = open("Student.txt",O_RDWR);
    if(fd==-1)
    {
        printf("Unable to Open the file\n");
        return -1;
    }
    printf("Enter the student name : ");
    scanf("%s",StudName);
    printf("\nEnter student's Rollno :");
    scanf("%d",&Roll);
    printf("Enter the Marks :");
    scanf("%d",&marks);
    printf("Enter the percentage of student :");
    scanf("%f",&perc);
    strcpy(sobj.Name,StudName);
    sobj.iRollno = Roll;
    sobj.Marks=marks;
    sobj.percentage=perc;

    write(fd,&sobj,sizeof(sobj));
    // Ret = read(fd,&sobj,sizeof(sobj));
    // printf("%s\n",sobj.Name);
    // printf("%d\n",sobj.iRollno);
    // printf("%d\n",sobj.Marks);
    // printf("%f\n",sobj.percentage);
    // printf("%d\n",sizeof(sobj));   
    return 0;
}