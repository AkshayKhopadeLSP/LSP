#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc,char*argv[])
{
    char * HomeDir = NULL;
    char *UserName = NULL;

    HomeDir = getenv("HOME");
    if(HomeDir==NULL)
    {
        printf("Unable to get the home\n");
        return -1;
    }

    UserName = getlogin();
    if(UserName==NULL)
    {
        printf("Unable to get the user name\n");
        return -1; 
    }

    printf("Hoem is : %s\n",HomeDir);
    printf("User is : %s\n",UserName);
    return 0;
}