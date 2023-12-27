#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
int main(int argc, char *argv[])
{
    struct stat file_stat;
    if (argc !=2)
    {
        fprintf(stderr, "Usage: %s <file>\n",argv[0]);
        return 1;
    }
    if (stat(argv[1],&file_stat)==-1)
    {
        fprintf(stderr,"Cannot read file %s : %s\n",argv[1],strerror(errno));
        return errno;
    }
    printf("File Type:                       %d\n\n", file_stat.st_mode);
    printf("I-node number:                   %ju\n\n",file_stat.st_ino);
    printf("Last Status Change:              %s\n", ctime(&file_stat.st_ctim.tv_sec));
    printf("Last File Access:                %s\n", ctime(&file_stat.st_atim.tv_sec));
    printf("Last File Modification :         %s\n", ctime(&file_stat.st_mtime));
    printf("File Size:                       %jd bytes\n", file_stat.st_size);   
    return 0;
}