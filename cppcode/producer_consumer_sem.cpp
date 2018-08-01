#include "stdio.h"
#include "pthread.h"
#include "semaphore.h"

#define MAX 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t full;
sem_t empty;

int top = 0;
int buttom = 0;

void* produce(void*)
{
    int i;
    for (i = 0; i < MAX * 2; i++)
    {
        printf("producer is preparing data\n");
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        top = (top + 1) % MAX;
        printf("now top is %d\n", top);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void* cunsume(void*)
{
    int i;
    for (i = 0; i < MAX * 2; i++)
    {
        printf("consumer is preparing data\n");
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        buttom = (buttom + 1) % MAX;
        printf("now buttom is %d\n", buttom);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    pthread_t thid1;
    pthread_t thid2;
    pthread_t thid3;
    pthread_t thid4;

    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX);
    pthread_create(&thid1, NULL, produce, NULL);
    pthread_create(&thid2, NULL, cunsume, NULL);
    pthread_create(&thid3, NULL, produce, NULL);
    pthread_create(&thid4, NULL, cunsume, NULL);


    pthread_join(thid1, NULL);
    pthread_join(thid2, NULL);
    pthread_join(thid3, NULL);
    pthread_join(thid4, NULL);
    return 0;
}

