#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

// struct stat
// {
//     dev_t st_dev;         /* ID of device containing file */
//     ino_t st_ino;         /* inode number */
//     mode_t st_mode;       /* permissions */
//     nlink_t st_nlink;     /* number of hard links */
//     uid_t st_uid;         /*I user ID of owner */
//     gid_t st_gid;         /* group ID of owner */
//     dev_t st_rdev;        /* device ID (if special file) */
//     off_t st_size;        /* total size in bytes */
//     blksize_t st_blksize; /* blocksize for filesystem I/O */
//     blkcnt_t st_blocks;   /* number of blocks allocated */
//     time_t st_atime;      /* last access time */
//     time_t st_mtime;      /* last modification time */
//     time_t st_ctime;      /* last status change time */
// } :

int main(int argc, char const *argv[])
{
    struct stat statbuf;
    int ret;
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s <file> \n", argv[0]);
        return 1;
    }

    ret = stat(argv[1], &statbuf);
    if (ret)
    {
        perror("stat");
        return 1;
    }

    printf(" ID of device containing file  %d \n", statbuf.st_dev);
    printf(" inode number  %d \n", statbuf.st_ino);
    printf(" permissions  %d \n", statbuf.st_mode);
    printf(" number of hard links  %d \n", statbuf.st_nlink);
    printf(" user ID of owner  %d \n", statbuf.st_uid);
    printf(" group ID of owner  %d \n", statbuf.st_gid);
    printf(" device ID (if special file)  %d \n", statbuf.st_rdev);
    printf(" total size in bytes  %d \n", statbuf.st_size);
    printf(" blocksize for filesystem I/O  %d \n", statbuf.st_blksize);
    printf(" number of blocks allocated  %d \n", statbuf.st_blocks);
    printf(" last access time  %d \n", statbuf.st_atime);
    printf(" last modification time  %d \n", statbuf.st_mtime);
    printf(" last status change time  %d \n", statbuf.st_ctime);

    return 0;
}
