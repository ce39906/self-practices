#include "stdio.h"
#include "pthread.h"


#define MAX 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER;
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER;

int top = 0;
int buttom = 0;
void* producer(void*)
{
    int i;
    for (i = 0;i<MAX*2;i++)
    {
        pthread_mutex_lock(&mutex);
        while((top+1)%MAX == buttom)
        {
            pthread_cond_wait(&notfull,&mutex);
        }
        top = (top+1)%MAX;
        printf("producer,top is%d\n",top);
        pthread_cond_signal(&notempty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void* consumer(void*)
{
    int i;
    for (i=0;i<MAX*2;i++)
    {
        pthread_mutex_lock(&mutex);
        while(top % MAX == buttom)
        {
            printf("empty,consumer is waiting\n");
            pthread_cond_wait(&notempty,&mutex);
        }
        buttom = (buttom+1)%MAX;
        printf("consumer,buttom is%d\n",buttom);
        pthread_cond_signal(&notfull);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thd1;
    pthread_t thd2;
    pthread_t thd3;
    pthread_t thd4;

    pthread_create(&thd1,NULL,producer,NULL);
    pthread_create(&thd2,NULL,consumer,NULL);
    pthread_create(&thd3,NULL,producer,NULL);
    pthread_create(&thd4,NULL,consumer,NULL);

    pthread_join(thd1,NULL);
    pthread_join(thd2,NULL);
    pthread_join(thd3,NULL);
    pthread_join(thd4,NULL);

    return 0;

}
