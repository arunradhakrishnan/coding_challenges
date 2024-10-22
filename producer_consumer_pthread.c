#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutexattr_t     attr;  
pthread_cond_t  condA  = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int ProcessRow = 0 ;
#define LOOPCNT 10

void *producer(void *args)
{
    int idx ;
    printf("producer-->\n");
    for(idx=0; idx<LOOPCNT; idx++)
    {
        //pthread_mutex_lock(&mutex);
        __sync_add_and_fetch(&ProcessRow,1) ;
        pthread_cond_signal(&condA);
        printf("sending signal...(%d)\n",ProcessRow) ;
        //pthread_mutex_unlock(&mutex);
    }
    printf("I am out ... \n") ;
    return NULL;
}

void *consumer(void *args)
{
    int icnt = 0 ;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while (ProcessRow <= 0)
            pthread_cond_wait(&condA, &mutex);
        pthread_mutex_unlock(&mutex); // I forget to add unlock to fail this test
        __sync_sub_and_fetch(&ProcessRow,1) ;
        ++icnt ;
        printf("receving=(%d)\n",ProcessRow) ;
        usleep(10000) ;
    }
    printf("(%d)\n",ProcessRow) ;
 return NULL;
}

 pthread_t thread_id1;
 pthread_t thread_id2;
 pthread_attr_t pthread_attr;

int main()
{
     printf("main ... \n") ;
    pthread_mutexattr_init(&attr);
    pthread_mutex_init(&mutex, &attr);
 printf("main ...1 \n") ;
    pthread_create(&thread_id1,
                          NULL,
                          producer,
                          NULL);

    pthread_create(&thread_id2,
                          NULL,
                          consumer,
                          NULL);
printf("main ...3 \n") ;
while(1);

}