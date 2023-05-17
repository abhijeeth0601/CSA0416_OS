#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SHARED_MEMORY_INITIAL_VALUE 5
#define SHARED_MEMORY_SIZE 1

sem_t semaphore;
int shared_memory[SHARED_MEMORY_SIZE] = {SHARED_MEMORY_INITIAL_VALUE};

void *thread1(void *arg)
{
    sem_wait(&semaphore);
    shared_memory[0] *= 2;
    printf("Thread 1: Doubled value is %d\n", shared_memory[0]);
    sem_post(&semaphore);
    return NULL;
}

void *thread2(void *arg)
{
    sem_wait(&semaphore);
    shared_memory[0] *= 5;
    printf("Thread 2: Multiplied value is %d\n", shared_memory[0]);
    sem_post(&semaphore);
    return NULL;
}

int main()
{
    sem_init(&semaphore, 0, 1);
    pthread_t thread_id_1, thread_id_2;
    pthread_create(&thread_id_1, NULL, &thread1, NULL);
    pthread_create(&thread_id_2, NULL, &thread2, NULL);
    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);
    printf("Final value of shared memory is %d\n", shared_memory[0]);
    sem_destroy(&semaphore);
    return 0;
}
