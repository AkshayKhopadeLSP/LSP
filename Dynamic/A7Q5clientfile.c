#include<stdio.h>
#include"A7Q5Headerfile.h"

int main(int argc, char*argv[])
{
    char Arr[50];

    printf("Enter the File Name : ");
    scanf("%s",Arr);

    FileInfo(Arr);
    return 0;
}