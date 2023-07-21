#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char*argv[])
{
    struct stat sobj;
    int fd =0;

    if(argc !=2)
    {
        printf("Insufficient aarugements\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("Name of File :%s\n",argv[1]);
    printf("Inode number of file : %d\n",sobj.st_ino);
    printf("Mode of File :%d\n",sobj.st_mode);
    printf("Links  of File :%d\n",sobj.st_nlink);
    printf("Size of file :%d\n",sobj.st_size);
    printf("Time of last access :%d\n",sobj.st_atime);
    printf("Time of last data modification :%d\n",sobj.st_mtime);
    printf("Number of blocks allocated :%d\n",sobj.st_blocks);

    
    return 0;
}

/*
dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	time_t st_atime;
	time_t st_mtime;
	time_t st_ctime;
	blksize_t st_blksize;
	blkcnt_t st_blocks;
	mode_t st_attr;
    */