#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4

sem_t semaphore;

void* process(void* arg) {
    int process_number = *((int*)arg);
    
    printf("Process P%d is waiting on the semaphore.\n", process_number);
    sem_wait(&semaphore);
    
    printf("Process P%d has acquired the semaphore.\n", process_number);
    
    // Simulating some work being done by the process
    sleep(2);
    
    printf("Process P%d has released the semaphore.\n", process_number);
    sem_post(&semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[NUM_INSTANCES];
    int process_numbers[NUM_INSTANCES] = {1, 2, 3, 4};
    
    sem_init(&semaphore, 0, NUM_INSTANCES);
    
    // Creating threads for the processes
    for (int i = 0; i < NUM_INSTANCES; i++) {
        pthread_create(&threads[i], NULL, process, &process_numbers[i]);
    }
    
    // Waiting for the processes to finish
    for (int i = 0; i < NUM_INSTANCES; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore);
    
    // Another process wants the same resource
    printf("Process P5 is waiting on the semaphore.\n");
    sem_wait(&semaphore);
    
    printf("Process P5 has acquired the semaphore.\n");
    
    // Simulating some work being done by process P5
    sleep(2);
    
    printf("Process P5 has released the semaphore.\n");
    sem_post(&semaphore);
    
    return 0;
}
