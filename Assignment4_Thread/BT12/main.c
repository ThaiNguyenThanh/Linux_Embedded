#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
pthread_t thread_id1, thread_id2;

typedef struct{
    char name[20];
    char date[10];
    char number[10];
    char place[10];
}data_t;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;

int is_done;
int is_done2;

static void *thr_handle1(void *args)
{

    data_t *data = (data_t*) args;
    pthread_mutex_lock(&lock);
    if(!is_done2)
    {
    pthread_cond_wait(&cond2,&lock);
    }
    printf("Ho va ten: %s\n",data->name);
    printf("Ngay sinh: %s\n",data->date);
    printf("Dia chi: %s\n",data->place);
    is_done2=0;
    
    pthread_mutex_unlock(&lock);

}

static void *thr_handle2(void *args)
{
    pthread_mutex_lock(&lock);
    if(!is_done)
    {
    pthread_cond_wait(&cond1,&lock);
    }
    data_t *data = (data_t*) args;
    int fd;
    fd = open("thongtinsinhvien.txt", O_WRONLY);
    lseek(fd, 0, SEEK_END);
    write (fd, "\n",1);   
    write (fd, data->name,sizeof(data->name));
    write (fd, ",",1);
    write (fd, data->date,sizeof(data->date));
    write (fd, ",",1);
    write (fd, data->place,sizeof(data->place));
    close (fd);

    is_done2=1;
    is_done=0;
    pthread_cond_signal(&cond2);
    pthread_mutex_unlock(&lock);
}



int main (void)
{
    data_t data ={0};
    int ret;
    
    pthread_mutex_lock(&lock);
    while (1)
    {
    //data_t *data = (data_t*) args;
    data_t data ={0};
    printf("Nhap ten ho va ten: ");
    scanf("%[^\n]",data.name);
    getchar();
    printf("Nhap ngay sinh: ");
    scanf("%[^\n]",data.date);
    getchar();
    printf("Nhap que quan: ");
    scanf("%[^\n]",data.place);
    getchar();
    printf("\n\n");
    is_done=1;
    pthread_cond_signal(&cond1);
    pthread_mutex_unlock(&lock);
    
    if (ret = pthread_create(&thread_id2,NULL,&thr_handle2,&data))
    {
        return -1;
    }

   pthread_join(thread_id2,NULL) ;

    if (ret = pthread_create(&thread_id1,NULL,&thr_handle1,&data))
    {
        return -1;
    }
    pthread_join(thread_id1,NULL);
    }
    
}