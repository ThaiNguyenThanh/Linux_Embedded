#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
pthread_t thread_id1, thread_id2;
static void *thr_handle(void *args)
{
    int i;
    int fd;
    fd = open ("text.txt", O_RDWR);
    for (i = 0; i<500000;i++){
        write (fd, "A",1);
    }
    close (fd);
}


int main (void)
{
   int ret;
    int i;
    int fd;
    fd = open ("text.txt", O_WRONLY);
    for (i = 0; i<500000;i++){
        write (fd, "A",1);
    }
    close (fd);
/*
    if (ret = pthread_create(&thread_id1,NULL,&thr_handle,NULL))
    {
        return -1;
    }
    if (ret = pthread_create(&thread_id2,NULL,&thr_handle,NULL))
    {
        return -1;
    }
    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL) ;*/
}