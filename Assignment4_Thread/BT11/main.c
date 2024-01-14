#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
pthread_t thread_id1, thread_id2;

typedef struct{
    char name[30];
    char date[20];
    char number[10];
    char place[100];
}data_t;

static void *thr_handle(void *args)
{
    pthread_t tid = pthread_self();
    data_t *data = (data_t*) args;

    if (pthread_equal (tid,thread_id1))
    {
        printf("I'm thread_id1\n");
       
    }
    else 
    {
        printf("My name is: %s\n",data->name);
        printf("My birthday is: %s\n",data->name);
        printf("My number is: %s\n",data->name);
        printf("My address is: %s\n",data->name);
        
    }
    int i;
    int fd;


}


int main (void)
{
    data_t data ={0};
    int ret;
    strncpy(data.name,"Nguyen Thanh Thai",sizeof(data.name));
    strncpy(data.date,"03/07/1999",sizeof(data.date));
    strncpy(data.number,"0703010756",sizeof(data.number));
    strncpy(data.place,"district 6 TPHCM",sizeof(data.place));

    if (ret = pthread_create(&thread_id1,NULL,&thr_handle,NULL))
    {
        return -1;
    }
    if (ret = pthread_create(&thread_id2,NULL,&thr_handle,&data))
    {
        return -1;
    }

    pthread_join(thread_id1,NULL);
    pthread_join(thread_id2,NULL) ;
}